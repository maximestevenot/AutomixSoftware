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
            BpmPriority = bpmBarValue;
            KeyNumberPriority = keyNumberBarValue;
            KeyTonalityPriority = keyTonalityBarValue;
            DanceabilityPriority = danceabiltyBarValue;
        }
        public void UpdateBpmPriority(int value)
        {
            BpmPriority = value;
        }
        public void UpdateKeyNumberPriority(int value)
        {
            KeyNumberPriority = value;
        }
        public void UpdateKeyTonalityPriority(int value)
        {
            KeyTonalityPriority = value;
        }
        public void UpdateDanceabilityPriority(int value)
        {
            DanceabilityPriority = value;
        }
    }
}
