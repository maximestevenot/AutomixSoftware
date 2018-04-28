using System.IO;
using Automix_Data_Management.Storage;

namespace Automix_Data_Management.Model
{
    public class Settings
    {
        public string TempDir { get; set; }
        public string TransitionDuration { get; set; }
        public string MixDuration { get; set; }
        public string BpmPriority { get; set; }
        public string KeyTonalityPriority { get; set; }
        public string KeyNumberPriority { get; set; }
        public string DanceabilityPriority { get; set; }
        public string Mp3Quality { get; set; }

        public Settings()
        {
            TempDir = Path.GetTempPath() + "\\AutomixSoftware";
            TransitionDuration = "10";
            MixDuration = "60";
            BpmPriority = "10";
            KeyNumberPriority = "10";
            KeyTonalityPriority = "10";
            DanceabilityPriority = "10";
            Mp3Quality = "320";
        }

        public void Save() => new SettingsManager().SaveParametersInFile(this);
    }
}
