using System;

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
        public string Mp3Quality { get; set; }

        public Parameters()
        {
            TempDir = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "//AutomixSoftware";
            TransitionDuration = "10";
            MixDuration = "30";
            BpmPriority = "10";
            KeyNumberPriority = "10";
            KeyTonalityPriority = "10";
            DanceabilityPriority = "10";
            Mp3Quality = "320";
        }

        public void Save() => new SettingsAccessor().SaveParametersInFile(this);
    }
}
