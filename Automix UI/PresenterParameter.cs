using System.Collections.Generic;
using Automix_AI.Distances;
using Automix_Data_Management;
using Automix_Data_Management.Exportation;
using Automix_Data_Management.Model;
using Automix_Data_Management.Storage;
using Automix_UI.Forms;
using NAudio.Lame;

namespace Automix_UI
{
    public class PresenterParameter
    {
        private readonly List<IViewWithParameters> _views;
        private Settings _settings;
        private IProfileDistance _actualProfile;
        private MainForm _mainForm;

        public PresenterParameter()
        {
            _views = new List<IViewWithParameters>();
            _settings = new SettingsManager().LoadParametersFromFile();
            _actualProfile = new ManualProfile(
                int.Parse(_settings.BpmPriority),
                int.Parse(_settings.KeyNumberPriority),
                int.Parse(_settings.KeyTonalityPriority),
                int.Parse(_settings.DanceabilityPriority)
                );
        }

        public PresenterParameter(IViewWithParameters view) : this()
        {
            _views.Add(view);
        }

        internal void SetMainForm(MainForm mainForm)
        {
            _mainForm = mainForm;
        }

        public void SetProfile(IProfileDistance profile)
        {
            _actualProfile = profile;
            _settings.BpmPriority = profile.BpmPriority.ToString();
            _settings.KeyNumberPriority = profile.KeyNumberPriority.ToString();
            _settings.KeyTonalityPriority = profile.KeyTonalityPriority.ToString();
            _settings.DanceabilityPriority = profile.DanceabilityPriority.ToString();

            UpdateViews();
        }

        internal void UpdateSortProfile()
        {
            _mainForm.UpdateSortProfile(_actualProfile);
        }

        public void SaveParameters() => _settings.Save();

        internal void SetTransitionDuration(decimal value)
        {
            _settings.TransitionDuration = value.ToString();
            SmoothMix.DEFAULTTRANSITIONDURATION = (int) value;
        }

        internal void SetMixDuration(decimal value)
        {
            _settings.MixDuration = value.ToString();
        }

        internal void SetMP3Quality(int value)
        {
            _settings.Mp3Quality = value.ToString();
            AudioIO.ExportQuality = (LAMEPreset)value;
        } 

        public void UpdateViews()
        {
            foreach (IViewWithParameters view in _views)
            {
                view.LoadParameters(_settings);
            }
        }
    }
}
