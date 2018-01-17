// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using System;

namespace Automix_Data_Management.Model
{
    public class Track
    {
        private static int _tracksCount;
        public int Bpm { get; set; }
        public int Duration { get; set; }
        public string Key { get; set; }
        public double Danceability { get; set; }
        public int Samplerate { get; set; }
        public int[] Beats { get; set; }
        public int[] FadeIns { get; set; }
        public int[] FadeOuts { get; set; }
        public string Checksum { get; private set; }
        public string Name { get; private set; }
        public string Path { get; private set; }
        public int Id { get; private set; }
        public bool isFixed { get; set; }

        public static Track CopyFrom(Track old)
        {
            var newTrack = new Track(string.Copy(old.Path), string.Copy(old.Checksum))
            {
                Duration = old.Duration,
                Bpm = old.Bpm,
                Key = string.Copy(old.Key),
                Danceability = old.Danceability,
                Samplerate = old.Samplerate,
                Beats = new int[old.Beats.Length],
                FadeIns = new int[old.FadeIns.Length],
                FadeOuts = new int[old.FadeOuts.Length]
            };
            Array.Copy(old.Beats, newTrack.Beats, old.Beats.Length);
            Array.Copy(old.FadeIns, newTrack.FadeIns, old.FadeIns.Length);
            Array.Copy(old.FadeOuts, newTrack.FadeOuts, old.FadeOuts.Length);
            return newTrack;
        }
        public Track()
        {
            Duration = 0;
            Bpm = 0;
            Key = "";
            Danceability = 0;
            Samplerate = 0;
            Id = _tracksCount++;
        }

        public Track(string path) : this(path, null)
        {
        }

        public Track(string path, string checksum) : this()
        {
            Path = path;
            Name = Utils.NameFromPath(path);
            Checksum = checksum ?? AudioIO.Mp3Md5Hash(path);
        }

        public string DisplayDuration()
        {
            var ts = TimeSpan.FromMilliseconds(Duration);
            var durationString = ts.ToString();
            var dotIndex = durationString.LastIndexOf(".", StringComparison.Ordinal);

            if (dotIndex > 0)
            {
                durationString = durationString.Substring(0, dotIndex);
            }
            return durationString;
        }

        public double GetLastFadeOutDuration()
        {
            double time = Duration;

            if (FadeOuts.Length >= 2)
            {
                time -= FadeOuts[FadeOuts.Length - 2];
            }
            else if (FadeOuts.Length == 1)
            {
                time -= FadeOuts[0];
            }
            else
            {
                time = 0;
            }

            return time / 1000;
        }
    }
}