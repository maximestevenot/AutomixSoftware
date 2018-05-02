// Copyright (C) 2016 - 2018 LesProjecteurs
// This file is part of Automix Software licensed under MIT License.

namespace Automix_AI.Distances
{
    public class TonalityProfile : PresetProfile
    {
        public TonalityProfile()
        {
            BpmPriority = 0;
            KeyNumberPriority = 20;
            KeyTonalityPriority = 15;
            DanceabilityPriority = 10;
        }
    }
}
