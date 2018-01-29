// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using System;
using Automix_Data_Management.Model;
using static Automix_Data_Management.Utils;

namespace Automix_AI.Distances
{
    public class SimpleTracksDistance : AbstractTracksDistance
    {
        private static readonly log4net.ILog log = log4net.LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);


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
                Console.WriteLine("Unable to compute distance between tracks {0} and {1}\n\n", track1.Name, track2.Name);
                return -1;
            }
            catch(OverflowException oe)
            {
                log.Info("One of the following song is too big : {0} or {1}\n\n" + track1.Name + track2.Name, oe);
                Console.WriteLine("One of the following song is too big : {0} or {1}\n\n", track1.Name, track2.Name);
                return -1;
            }

           
            var distance = Math.Abs(track2.Bpm - track1.Bpm) * 1200 * BpmPriority;
            var distanceDouble = track2.Bpm < track1.Bpm ? Math.Abs(2 * track2.Bpm - track1.Bpm) * 1200 * BpmPriority : Math.Abs(track2.Bpm - 2 * track1.Bpm) * 1200 * BpmPriority;
            distance = distanceDouble < distance ? distanceDouble : distance;

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
