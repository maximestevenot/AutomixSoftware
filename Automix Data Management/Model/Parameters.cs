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

        public Parameters ()
        {
            TempDir = GetSetting(Settings.tempDir);
            TransitionDuration = GetSetting(Settings.transitionDuration);
            MixDuration = GetSetting(Settings.mixDuration);
            BpmPriority = GetSetting(Settings.bpmPriority);
            KeyNumberPriority = GetSetting(Settings.keyNumberPriority);
            KeyTonalityPriority = GetSetting(Settings.keyTonalityPriority);
            DanceabilityPriority = GetSetting(Settings.danceabilityPriority);
        }
        public void Save()
        {
            System.Console.WriteLine("HELLO");
            SetSetting(Settings.tempDir, TempDir);
            SetSetting(Settings.transitionDuration, TransitionDuration);
            SetSetting(Settings.mixDuration, MixDuration);
            SetSetting(Settings.bpmPriority, BpmPriority);
            SetSetting(Settings.keyNumberPriority, KeyNumberPriority);
            SetSetting(Settings.keyTonalityPriority, KeyTonalityPriority);
            SetSetting(Settings.danceabilityPriority, DanceabilityPriority);
        }
    }
}
