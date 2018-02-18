// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using Automix_Data_Management.Model;
using NAudio.Wave;
using NAudio.Wave.SampleProviders;
using static Automix_Data_Management.Utils;
using log4net;
using System;

namespace Automix_Data_Management.Exportation
{
    public class SmoothMix : IExportation
    {
        public static int DEFAULTTRANSITIONDURATION = 10;

        public int TransitionDuration { get; set; }

        private static readonly int SamplesPerSecond = AudioIO.TempWaveFormat.AverageBytesPerSecond / 4;
        private readonly string _tempDirPath;
        private string _tempWavPath;
        private readonly List<string> _tempFileList;
        private WaveFileWriter _waveFileWriter;
        private float[] _savedOverlay;

        private static readonly log4net.ILog log = log4net.LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);

        public SmoothMix() : this(DEFAULTTRANSITIONDURATION) { }

        public SmoothMix(int transitionDuration)
        {
            TransitionDuration = transitionDuration;
            _tempDirPath = GetTempDir();
            _tempFileList = new List<string>();
        }

        public void ExportMix(BackgroundWorker bw, TrackCollection collection, string outputFile)
        {
            _savedOverlay = null;
            _tempWavPath = _tempDirPath + "automix_1.wav";
            _waveFileWriter = new WaveFileWriter(_tempWavPath, AudioIO.TempWaveFormat);

            var count = 1;
            var tempFileDuration = 0;

            foreach (var track in collection)
            {
                if (bw.CancellationPending)
                {
                    _waveFileWriter.Close();
                    break;
                }

                //TODO : change this after transition start
                tempFileDuration += track.Duration;
                if (tempFileDuration > 2700000) //45 minutes
                {
                    tempFileDuration = track.Duration;
                    CreateNewTempFile();
                }

                FadeInOut(track);
                bw.ReportProgress((int)(1000 * count++) / (collection.Count + 2));
            }

            if (!bw.CancellationPending)
            {
                FinalizeLastTempFile();
                bw.ReportProgress((int)(1000 * count++) / (collection.Count + 2));
                AudioIO.WavToMp3(_tempFileList, outputFile, AudioIO.CreateId3TagData(outputFile));
                bw.ReportProgress((int)(1000 * count++) / (collection.Count + 2));
            }
            DeleteTempFiles();
        }

        private void FadeInOut(Track track)
        {
            int nbFadeIns = track.FadeIns.Length;
            int nbFadeOuts = track.FadeOuts.Length;

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

            var fileReader = new Mp3FileReader(track.Path);
            var startTimeSpan = new TimeSpan(0, 0, 0, 0, startFadeIn);
            var fade = new FadeInOutSampleProvider(fileReader.ToSampleProvider().Skip(startTimeSpan), false);

            var fadeInDuration = TransitionDuration * 1000;
            if (nbFadeIns > 1)
            {
                fadeInDuration = track.FadeIns[1] - track.FadeIns[0];
            }

            var fadeOutDuration = TransitionDuration * 1000;
            if (nbFadeOuts > 1)
            {
                fadeOutDuration = track.FadeOuts[track.FadeOuts.Length - 1] - track.FadeOuts[track.FadeOuts.Length - 2];
            }
            var bufferSize = (fileReader.Length) / 2 - ((fadeOutDuration + fadeInDuration - 2000) / 1000) * SamplesPerSecond;
            var overlaySize = (fadeOutDuration / 1000) * SamplesPerSecond;

            if (bufferSize < overlaySize)
            {
                bufferSize = overlaySize;
            }

            var buffer = new float[bufferSize];

            int startFadeOut = track.Duration - TransitionDuration * 1000;
            if (nbFadeOuts > 1)
            {
                startFadeOut = track.FadeOuts[track.FadeOuts.Length - 2];
            }

            fade.BeginFadeIn(fadeInDuration);
            fade.Read(buffer, 0, (int)(bufferSize - overlaySize));
            fade.BeginFadeOut(fadeOutDuration);
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
                    System.Diagnostics.Debug.WriteLine(e.Message);
                }
            }
        }
    }
}
