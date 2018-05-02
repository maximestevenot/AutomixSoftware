// Copyright (C) 2016 - 2018 LesProjecteurs
// This file is part of Automix Software licensed under MIT License.

namespace Automix_AI.Distances
{
    public abstract class PresetProfile : IProfileDistance
    {
        public double BpmPriority { get; protected set; }
        public double KeyNumberPriority { get; protected set; }
        public double KeyTonalityPriority { get; protected set; }
        public double DanceabilityPriority { get; protected set; }
    }
}
