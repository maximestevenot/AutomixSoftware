﻿// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

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
