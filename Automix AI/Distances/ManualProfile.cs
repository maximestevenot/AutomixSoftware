using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Automix_AI.Distances
{
    public class ManualProfile : IProfileDistance
    {
        public double BpmPriority { get; private set; }

        public double KeyNumberPriority { get; private set; }

        public double KeyTonalityPriority { get; private set; }

        public double DanceabilityPriority { get; private set; }

        public ManualProfile()
        {
            BpmPriority = 120 * 10;
            KeyNumberPriority = 2 * 10;
            KeyTonalityPriority = 200 * 10;
            DanceabilityPriority = 1 * 10;
        }
        public void UpdateBpmPriority(int value)
        {
            BpmPriority = value * 120;
        }
        public void UpdateKeyNumberPriority(int value)
        {
            KeyNumberPriority = value * 2;
        }
        public void UpdateKeyTonalityPriority(int value)
        {
            KeyTonalityPriority = value * 200;
        }
        public void UpdateDanceabilityPriority(int value)
        {
            DanceabilityPriority = value;
        }
    }
}
