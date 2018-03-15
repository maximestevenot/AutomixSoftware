using static Automix_Data_Management.SettingsAccessor;

namespace Automix_Data_Management.Model
{
    public class Parameters
    {
        public string TempDir { get; set; }
        public string TransitionDuration { get; set; }
        public string MixDuration { get; set; }
        public string BpmPriority { get; set; }
        public string KeyTonalityPriority { get; set; }
        public string KeyNumberPriority { get; set; }
        public string DanceabilityPriority { get; set; }
        public int MP3Quality { get; set; }

        public Parameters() { }

        public void Save() => SaveParametersInFile(this);
    }
}
