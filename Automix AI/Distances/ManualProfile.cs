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
        : this(10, 10, 10, 10) {}

        public ManualProfile(int bpmBarValue, int keyNumberBarValue,
            int keyTonalityBarValue, int danceabiltyBarValue)
        {
            BpmPriority = 120 * bpmBarValue;
            KeyNumberPriority = 2 * keyNumberBarValue;
            KeyTonalityPriority = 200 * keyTonalityBarValue;
            DanceabilityPriority = 1 * danceabiltyBarValue;
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
