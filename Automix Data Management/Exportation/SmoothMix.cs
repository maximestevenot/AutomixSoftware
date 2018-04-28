// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using Automix_Data_Management.Model;
using Automix_Data_Management.Storage;
using log4net;
using NAudio.Wave;
using NAudio.Wave.SampleProviders;

namespace Automix_Data_Management.Exportation
{
    public class SmoothMix : IExportation
    {
        public static int DEFAULTTRANSITIONDURATION = 10;

        public int TransitionDuration { get; set; }

        public int MixDuration { get; set; }

        private static readonly int SamplesPerSecond = AudioIO.TempWaveFormat.AverageBytesPerSecond / 4;
        private readonly string _tempDirPath;
        private string _tempWavPath;
        private readonly List<string> _tempFileList;
        private WaveFileWriter _waveFileWriter;
        private float[] _savedOverlay;
        private static readonly ILog log = LogManager.GetLogger(MethodBase.GetCurrentMethod().DeclaringType);
        private int _currentMixDuration;

        public SmoothMix() : this(10) { }

        public SmoothMix(int transitionDuration)
        {
            var settingsManager = new SettingsManager();

            TransitionDuration = transitionDuration;
            MixDuration = Convert.ToInt32(60000 * (int.Parse(settingsManager.GetSetting(SettingsManager.SettingTypes.MixDuration))));
            _tempDirPath = settingsManager.GetSetting(SettingsManager.SettingTypes.TempDir);
            _tempFileList = new List<string>();
        }

        public void ExportMix(BackgroundWorker bw, TrackCollection collection, string outputFile)
        {
            _savedOverlay = null;
            _tempWavPath = _tempDirPath + "automix_1.wav";
            _waveFileWriter = new WaveFileWriter(_tempWavPath, AudioIO.TempWaveFormat);

            var count = 1;
            var tempFileDuration = 0;
            _currentMixDuration = 0;

            Track firstTrack = collection[0];
            int fadeInDurationPreviousTrack = CalculateFadeInDuration(firstTrack);
            int nbTracks = collection.Count;
            for (int i = 0; i < nbTracks && MixDuration != 0; i++)
            {
                Track track = collection[i];
                if (bw.CancellationPending)
                {
                    _waveFileWriter.Close();
                    break;
                }

                //TO DO : change this after transition start
                tempFileDuration += track.Duration;
                if (tempFileDuration > 2700000) //45 minutes
                {
                    tempFileDuration = track.Duration;
                    CreateNewTempFile();
                }

                if (i == 0)
                {
                    _currentMixDuration += CalculateFadeInDuration(firstTrack);
                }

                if (track != collection[nbTracks - 1])
                {
                    if (_currentMixDuration < MixDuration)
                    {
                        Track nextTrack = collection[i + 1];
                        fadeInDurationPreviousTrack = FadeInOut(track, nextTrack, fadeInDurationPreviousTrack, collection);
                    }
                }
                else
                {
                    if (_currentMixDuration < MixDuration)
                    { 
                        FadeInOut(track, track, fadeInDurationPreviousTrack, collection);
                    }
                }

                bw.ReportProgress(1000 * count++ / (collection.Count + 2));
            }

            if (!bw.CancellationPending)
            {
                FinalizeLastTempFile();
                bw.ReportProgress(1000 * count++ / (collection.Count + 2));
                AudioIO.WavToMp3(_tempFileList, outputFile, AudioIO.CreateId3TagData(outputFile));
                bw.ReportProgress(1000 * count++ / (collection.Count + 2));
            }
            DeleteTempFiles();
            Console.WriteLine(_currentMixDuration);
        }

        private int CalculateFadeInDuration(Track track)
        {
            int nbFadeIns = track.FadeIns.Length;
            int fadeInDuration = 10 * 1000;
            if (nbFadeIns > 1)
            {
                fadeInDuration = track.FadeIns[1] - track.FadeIns[0];
            }
            return fadeInDuration;
        }

        private int CalculateFadeOutDuration(Track track)
        {
            int nbFadeOuts = track.FadeOuts.Length;
            int fadeOutDuration = 10 * 1000;
            if (nbFadeOuts > 1)
            {
                fadeOutDuration = track.FadeOuts[track.FadeOuts.Length - 1] - track.FadeOuts[track.FadeOuts.Length - 2];
            }
            return fadeOutDuration;
        }

        private int CalculateStartFadeIn(Track track)
        {
            int nbFadeIns = track.FadeIns.Length;
            int startFadeIn = 0;

            if (nbFadeIns > 1)
            {
                if (track.FadeIns[0] != 0)
                {
                    startFadeIn = track.FadeIns[0];
                }
                else
                {
                    startFadeIn = track.FadeIns[1];
                }
            }
            return startFadeIn;
        }

        private int CalculateStartFadeOut(Track track)
        {
            int nbFadeOuts = track.FadeOuts.Length;
            int startFadeOut = track.Duration - 10 * 1000;
            if (nbFadeOuts > 1)
            {
                startFadeOut = track.FadeOuts[track.FadeOuts.Length - 2];
            }
            return startFadeOut;
        }


        private int FadeInOut(Track track1, Track track2, int averageFadeDuration, TrackCollection collection)
        {
            int startFadeIn1 = CalculateStartFadeIn(track1);
            var fileReader = new Mp3FileReader(track1.Path);
            var startTimeSpan = new TimeSpan(0, 0, 0, 0, startFadeIn1);
            var fade = new FadeInOutSampleProvider(fileReader.ToSampleProvider().Skip(startTimeSpan), false);

            int fadeInDuration1, fadeOutDuration1, fadeInDuration2;
            if (track1 == collection[0])
            {
                fadeInDuration1 = CalculateFadeInDuration(track1);
            }
            else
            {
                fadeInDuration1 = averageFadeDuration;
            }
            if (track1 == collection[collection.Count - 1])
            {
                fadeOutDuration1 = CalculateFadeOutDuration(track1);
                averageFadeDuration = 0;
            }
            else
            {
                fadeOutDuration1 = CalculateFadeOutDuration(track1);
                fadeInDuration2 = CalculateFadeInDuration(track2);
                var averageFadesDuration = (fadeOutDuration1 + fadeInDuration2) / 2;
                averageFadeDuration = averageFadesDuration;
                fadeOutDuration1 = averageFadeDuration;
            }
            var trackDuration = (track1.Duration - startFadeIn1) + fadeInDuration1 + averageFadeDuration;
            if (track2 == null)
            {
                trackDuration += averageFadeDuration;
            }

            long bufferSize;
            if (_currentMixDuration < MixDuration)
            {
                bufferSize = (fileReader.Length) / 2 - ((fadeOutDuration1 + fadeInDuration1 + startFadeIn1 - 2000) / 1000) * SamplesPerSecond;
            }
            else
            {
                bufferSize = (MixDuration - _currentMixDuration) * SamplesPerSecond;
            }

            var overlaySize = (fadeOutDuration1 / 1000) * SamplesPerSecond;

            if (bufferSize < overlaySize)
            {
                bufferSize = overlaySize;
            }

            var buffer = new float[bufferSize];

            fade.BeginFadeIn(fadeInDuration1);
            fade.Read(buffer, 0, (int)(bufferSize - overlaySize));
            fade.BeginFadeOut(fadeOutDuration1);
            fade.Read(buffer, (int)(bufferSize - overlaySize), overlaySize);

            if (_savedOverlay != null)
            {
                buffer = ApplyOverlay(buffer, _savedOverlay);
            }

            _waveFileWriter.WriteSamples(buffer, 0, (int)(bufferSize - overlaySize));
            _waveFileWriter.Flush();

            _savedOverlay = new float[overlaySize];
            for (var i = 0; i < overlaySize; i++)
            {
                _savedOverlay[i] = buffer[(bufferSize - overlaySize) + i];
            }

            _currentMixDuration += trackDuration;

            return averageFadeDuration;
        }

        private static float[] ApplyOverlay(float[] trackBuffer, float[] overlayBuffer)
        {
            for (var i = 0; i < overlayBuffer.Length; i++)
            {
                trackBuffer[i] += overlayBuffer[i];
            }
            return trackBuffer;
        }

        private void CreateNewTempFile()
        {
            _waveFileWriter.Flush();
            _waveFileWriter.Close();

            _tempFileList.Add(_tempWavPath);

            _tempWavPath = _tempDirPath + "automix_" + (_tempFileList.Count + 1) + ".wav";
            _waveFileWriter = new WaveFileWriter(_tempWavPath, AudioIO.TempWaveFormat);
        }

        private void FinalizeLastTempFile()
        {
            _waveFileWriter.WriteSamples(_savedOverlay, 0, _savedOverlay.Length);
            _waveFileWriter.Flush();
            _waveFileWriter.Close();
            _tempFileList.Add(_tempWavPath);
        }

        private void DeleteTempFiles()
        {
            foreach (var path in _tempFileList)
            {
                try
                {
                    File.Delete(path);
                }
                catch (IOException e)
                {
                    log.Debug(e.Message, e);
                    Debug.WriteLine(e.Message);
                }
            }
        }
    }
}
