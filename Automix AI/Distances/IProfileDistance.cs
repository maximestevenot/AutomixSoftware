// Copyright (C) 2016 - 2018 LesProjecteurs
// This file is part of Automix Software licensed under MIT License.

namespace Automix_AI.Distances
{
    public interface IProfileDistance 
    {
        double BpmPriority { get; }
        double KeyNumberPriority { get; }
        double KeyTonalityPriority { get; }
        double DanceabilityPriority { get; }
    }
}
