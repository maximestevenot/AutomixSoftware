// Copyright (C) 2016 - 2018 LesProjecteurs
// This file is part of Automix Software licensed under MIT License.

namespace Automix_AI.Distances
{
    public class RhythmProfile : PresetProfile
    {
        public RhythmProfile()
        {
            BpmPriority = 20;
            KeyNumberPriority = 5;
            KeyTonalityPriority = 3;
            DanceabilityPriority = 12;
        }
    }
}