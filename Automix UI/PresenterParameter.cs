using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Automix_Data_Management.Model;
using Automix_AI.Distances;
using Automix_UI.Forms;
using static Automix_Data_Management.SettingsAccessor;
using Automix_Data_Management;
using NAudio.Lame;

namespace Automix_UI
{
    public class PresenterParameter
    {
        private readonly List<IViewWithParameters> _views;
        private Parameters _parameters;
        private IProfileDistance _actualProfile;
        private MainForm _mainForm;

        public PresenterParameter()
        {
            _views = new List<IViewWithParameters>();
            _parameters = LoadParametersFromFile();
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
            _parameters.BpmPriority = profile.BpmPriority.ToString();
            _parameters.KeyNumberPriority = profile.KeyNumberPriority.ToString();
            _parameters.KeyTonalityPriority = profile.KeyTonalityPriority.ToString();
            _parameters.DanceabilityPriority = profile.DanceabilityPriority.ToString();

            UpdateViews();
        }

        internal void UpdateSortProfile()
        {
            _mainForm.UpdateSortProfile(_actualProfile);
        }

        public void SaveParameters() => _parameters.Save();

        internal void SetTransitionDuration(decimal value) => _parameters.TransitionDuration = value.ToString();

        internal void SetMixDuration(decimal value) => _parameters.MixDuration = value.ToString();

        internal void SetMP3Quality(int value)
        {
            _parameters.MP3Quality = value.ToString();
            AudioIO.ExportQuality = (LAMEPreset)value;
        } 

        public void UpdateViews()
        {
            foreach (IViewWithParameters view in _views)
            {
                view.LoadParameters(_parameters);
            }
        }
    }
}
