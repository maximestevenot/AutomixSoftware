// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using Automix_Data_Management.Model;

namespace Automix_AI.Distances
{
    public abstract class AbstractTracksDistance : ITracksDistance
    {
        public double BpmPriority { get; set; }
        public double KeyNumberPriority { get; set; }
        public double KeyTonalityPriority { get; set; }
        public double DanceabilityPriority { get; set; }


        protected AbstractTracksDistance() : this(new BasicProfile())
        {

        }

        protected AbstractTracksDistance(IProfileDistance profile)
        {
            BpmPriority = profile.BpmPriority;
            KeyNumberPriority = profile.KeyNumberPriority;
            KeyTonalityPriority = profile.KeyTonalityPriority;
            DanceabilityPriority = profile.DanceabilityPriority;
        }

        public abstract double Compute(Track track1, Track track2);

       



    }
}
