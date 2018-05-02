// Copyright (C) 2016 - 2018 LesProjecteurs
// This file is part of Automix Software licensed under MIT License.

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
