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
    public interface ITracksDistance
    {
        double BpmPriority { get; set; }
        double KeyNumberPriority { get; set; }
        double KeyTonalityPriority { get; set; }
        double DanceabilityPriority { get; set; }

        double Compute(Track track1, Track track2);
    }
}
