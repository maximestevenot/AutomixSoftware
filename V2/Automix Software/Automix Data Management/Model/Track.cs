using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AutomixDataManagement.Model
{
    //TODO: Change constructors
    public class Track
    {
        private static int TRACKS_COUNT = 0;
        public int BPM { get; set; }
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

        public static Track CopyFrom(Track old)
        {
            Track newTrack = new Track(string.Copy(old.Path), string.Copy(old.Checksum));
            newTrack.Duration = old.Duration;
            newTrack.BPM = old.BPM;
            newTrack.Key = string.Copy(old.Key);
            newTrack.Danceability = old.Danceability;
            newTrack.Samplerate = old.Samplerate;
            newTrack.Beats = new int[old.Beats.Length];
            newTrack.FadeIns = new int[old.FadeIns.Length];
            newTrack.FadeOuts = new int[old.FadeOuts.Length];
            Array.Copy(old.Beats, newTrack.Beats, old.Beats.Length);
            Array.Copy(old.FadeIns, newTrack.FadeIns, old.FadeIns.Length);
            Array.Copy(old.FadeOuts, newTrack.FadeOuts, old.FadeOuts.Length);
            return newTrack;
        }
        public Track()
        {
            Duration = 0;
            BPM = 0;
            Key = "";
            Danceability = 0;
            Samplerate = 0;
            Id = TRACKS_COUNT++;
        }

        public Track(string path) : this()
        {
            Path = path;
            Name = Utils.NameFromPath(path);
            if (path.StartsWith("test"))
            {
                Checksum = path;
            }
            else
            {
                Checksum = AudioIO.Mp3Md5Hash(path);
            }
        }

        public Track(string path, string checksum) : this()
        {
            Path = path;
            Name = Utils.NameFromPath(path);
            Checksum = checksum;
        }

        public string DisplayDuration()
        {
            TimeSpan ts = TimeSpan.FromMilliseconds(Duration);
            string durationString = ts.ToString();
            int dotIndex = durationString.LastIndexOf(".");

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