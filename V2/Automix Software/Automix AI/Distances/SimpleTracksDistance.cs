using System;
using Automix_Data_Management.Model;

namespace Automix_AI.Distances
{
    internal class SimpleTracksDistance : AbstractTracksDistance
    {
        public override double Compute(Track track1, Track track2)
        {
            bool haveSameScale;
            double digitalTrack1Key, digitalTrack2Key;

            try
            {
                haveSameScale = track1.Key.Contains("d") == track2.Key.Contains("d");
                digitalTrack1Key = double.Parse(track1.Key.Remove(track1.Key.Length - 1));
                digitalTrack2Key = double.Parse(track2.Key.Remove(track2.Key.Length - 1));

            }
            catch
            {
                return -1;
            }

            var distance = Math.Abs(track2.Bpm - track1.Bpm) * 1200 * BpmPriority;
            distance += Math.Abs(track1.Danceability - track2.Danceability) * 10 * DanceabilityPriority;

            if (haveSameScale)
            {
                var absoluteDistance = (int)Math.Abs(digitalTrack1Key - digitalTrack2Key);
                if (absoluteDistance > 6)
                {
                    absoluteDistance = 12 - absoluteDistance;
                }
                distance += absoluteDistance * 20 * KeyNumberPriority;
            }
            else
            {
                if (Math.Abs(digitalTrack1Key - digitalTrack2Key) > 0.0001)
                {
                    distance += 2000 * KeyTonalityPriority;
                }

            }
            return distance;
        }
    }
}
