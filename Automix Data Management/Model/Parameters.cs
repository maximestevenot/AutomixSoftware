using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static Automix_Data_Management.SettingsAccessor;

namespace Automix_Data_Management.Model
{
    public class Parameters
    {
        private string TempDir { get; set; }
        private string TransitionDuration { get; set; }
        private string MixDuration { get; set; }

        public Parameters ()
        {
            TempDir = GetSetting(Settings.tempDir);
            TransitionDuration = GetSetting(Settings.transitionDuration);
            MixDuration = GetSetting(Settings.mixDuration);

        }

        ~Parameters()
        {
            SetSetting(Settings.tempDir, TempDir);
            SetSetting(Settings.transitionDuration, TransitionDuration);
            SetSetting(Settings.mixDuration, MixDuration);
        }
    }
}
