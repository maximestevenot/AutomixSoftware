﻿// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using AutomixDataManagement.Model;
using NAudio.Wave;
using NAudio.Wave.SampleProviders;

namespace AutomixDataManagement.Exportation
{
    class SmoothMix : IExportation
    {
        public int TransitionDuration { get; set; }

        private static readonly int SAMPLES_PER_SECOND = AudioIO.TempWaveFormat.AverageBytesPerSecond / 4;
        private string _tempDirPath;
        private string _tempWavPath;
        private List<string> _tempFileList;
        private WaveFileWriter _waveFileWriter;
        private float[] _savedOverlay;

        public SmoothMix() : this(10) { }

        public SmoothMix(int transitionDuration)
        {
            TransitionDuration = transitionDuration;
            _tempDirPath = Path.GetTempPath() + "AutomixSoftware/";
            _tempFileList = new List<string>();
        }

        public void ExportMix(BackgroundWorker bw, TrackCollection collection, string outputFile)
        {
            _savedOverlay = null;
            _tempWavPath = _tempDirPath + "automix_1.wav";
            _waveFileWriter = new WaveFileWriter(_tempWavPath, AudioIO.TempWaveFormat);

            int count = 1;
            int tempFileDuration = 0;

            foreach (var track in collection)
            {
                if (bw.CancellationPending)
                {
                    _waveFileWriter.Close();
                    break;
                }

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
                AudioIO.WavToMp3(_tempFileList, outputFile, AudioIO.CreateID3TagData(outputFile));
                bw.ReportProgress((int)(1000 * count++) / (collection.Count + 2));
            }
            DeleteTempFiles();
        }

        private void FadeInOut(Track track)
        {
            var fileReader = new Mp3FileReader(track.Path);
            var fade = new FadeInOutSampleProvider(WaveExtensionMethods.ToSampleProvider(fileReader), false);

            long bufferSize = fileReader.Length / 2 - (long)track.GetLastFadeOutDuration() * SAMPLES_PER_SECOND;
            int overlaySize = TransitionDuration * SAMPLES_PER_SECOND;

            if (bufferSize < overlaySize)
            {
                bufferSize = overlaySize;
            }

            var buffer = new float[bufferSize];

            fade.BeginFadeIn(TransitionDuration * 1000);
            fade.Read(buffer, 0, (int)(bufferSize - overlaySize));
            fade.BeginFadeOut(TransitionDuration * 1000);
            fade.Read(buffer, (int)(bufferSize - overlaySize), overlaySize);

            if (_savedOverlay != null)
            {
                buffer = ApplyOverlay(buffer, _savedOverlay);
            }

            _waveFileWriter.WriteSamples(buffer, 0, (int)(bufferSize - overlaySize));
            _waveFileWriter.Flush();

            _savedOverlay = new float[overlaySize];
            for (int i = 0; i < overlaySize; i++)
            {
                _savedOverlay[i] = buffer[(bufferSize - overlaySize) + i];
            }
        }

        private float[] ApplyOverlay(float[] trackBuffer, float[] overlayBuffer)
        {
            for (int i = 0; i < overlayBuffer.Length; i++)
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
                    System.Diagnostics.Debug.WriteLine(e.Message);
                }
            }
        }
    }
}
