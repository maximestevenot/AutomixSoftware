// Copyright (C) 2016 - 2018 LesProjecteurs
// This file is part of Automix Software licensed under MIT License.

using System;
using NAudio.Wave;

namespace Automix_Data_Management.Audio_Playing
{
    //TODO review this class!
    public class Mp3Player
    {
        private readonly IWavePlayer _waveOutDevice;
        private readonly AudioFileReader _audioFileReader;

        public Mp3Player(string file)
        {
            _waveOutDevice = new WaveOut();
            _audioFileReader = new AudioFileReader(file);
            _waveOutDevice.Init(_audioFileReader);
        }

        public void Play()
        {
            _waveOutDevice.Play();
        }

        public void Pause()
        {
            _waveOutDevice.Pause();
        }

        public void Stop()
        {
            _waveOutDevice.Stop();
            SetPosition(0.0);
        }
        public long GetLength()
        {
            return _audioFileReader.Length;
        }

        public long GetPosition()
        {
            return _audioFileReader.Position;
        }
        public void Seek(double seconds)
        {
            _audioFileReader.Position = _audioFileReader.Position + (long)(seconds * _audioFileReader.WaveFormat.AverageBytesPerSecond);
        }

        public void SetPosition(long position)
        {
            var adj = position % _audioFileReader.WaveFormat.BlockAlign;
            _audioFileReader.Position = Math.Max(0, Math.Min(_audioFileReader.Length, position - adj));
        }
        public void SetPosition(double seconds)
        {
            _audioFileReader.Position = (long)(seconds * _audioFileReader.WaveFormat.AverageBytesPerSecond);
        }
        public void SetPosition(TimeSpan timeSpan)
        {
            _audioFileReader.Position = (long)timeSpan.TotalSeconds;
        }

    }
}
