// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

namespace Automix_AI.Distances
{
    public class BasicProfile : IProfileDistance
    {
        public double BpmPriority { get; set; }
        public double KeyNumberPriority { get; set; }
        public double KeyTonalityPriority { get; set; }
        public double DanceabilityPriority { get; set; }

        public BasicProfile()
        {
            BpmPriority = 1200;
            KeyNumberPriority = 20;
            KeyTonalityPriority = 2000;
            DanceabilityPriority = 10;
        }
    }
}
