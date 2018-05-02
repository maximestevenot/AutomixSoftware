// Copyright (C) 2016 - 2018 LesProjecteurs
// This file is part of Automix Software licensed under MIT License.

using System;
using System.Reflection;
using Automix_Data_Management.Model;
using log4net;

namespace Automix_AI.Distances
{
    public class SimpleTracksDistance : AbstractTracksDistance
    {
        private static readonly ILog log = LogManager.GetLogger(MethodBase.GetCurrentMethod().DeclaringType);

        public SimpleTracksDistance(IProfileDistance sortProfile) : base(sortProfile)
        {

        }

        public SimpleTracksDistance()
        {

        }

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
            catch(Exception ex) when (ex is ArgumentNullException || ex is FormatException)
            {
                log.Info("Unable to compute distance between tracks { 0} and { 1}\n\n" + track1.Name + track2.Name, ex);
                return -1;
            }
            catch(OverflowException oe)
            {
                log.Info("One of the following song is too big : {0} or {1}\n\n" + track1.Name + track2.Name, oe);
                return -1;
            }

            var distance = Math.Abs(track2.Bpm - track1.Bpm) * 120 * BpmPriority;
            var distanceDouble = track2.Bpm < track1.Bpm ? Math.Abs(2 * track2.Bpm - track1.Bpm) * 120 * BpmPriority : Math.Abs(track2.Bpm - 2 * track1.Bpm) * 120 * BpmPriority;

            distance = distanceDouble < distance ? distanceDouble : distance;
            distance += Math.Abs(track1.Danceability - track2.Danceability) * DanceabilityPriority;

            if (haveSameScale)
            {
                var absoluteDistance = (int)Math.Abs(digitalTrack1Key - digitalTrack2Key);
                if (absoluteDistance > 6)
                {
                    absoluteDistance = 12 - absoluteDistance;
                }
                distance += absoluteDistance * 2 * KeyNumberPriority;
            }
            else
            {
                if (Math.Abs(digitalTrack1Key - digitalTrack2Key) > 0.0001)
                {
                    distance += 200 * KeyTonalityPriority;
                }

            }
            return distance;
        }
    }
}
