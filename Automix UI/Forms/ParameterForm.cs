using Automix_AI.Distances;
using System;
using System.Windows.Forms;
using Automix_Data_Management.Model;
using Automix_Data_Management;
using NAudio.Lame;

namespace Automix_UI.Forms
{
    public partial class ParameterForm : Form, IViewWithParameters
    {
        private readonly PresenterParameter _presenter;

        public ParameterForm()
        {
            InitializeComponent();
            _normalRadioButton.Checked = true;
            _presenter = new PresenterParameter(this);
        }

        public ParameterForm(MainForm mainForm) : this()
        {
            _presenter.SetMainForm(mainForm);
            _presenter.UpdateViews();
        }

        private void OnCancelButtonClick(object sender, EventArgs e)
        {
            Hide();
        }

        private void OnApplyButtonClick(object sender, EventArgs e)
        {          
            _presenter.UpdateSortProfile();
        }

        private void OnOkButtonClick(object sender, EventArgs e)
        {
            _presenter.SetMixDuration(_mixDuration.Value);
            _presenter.SetTransitionDuration(_transitionDuration.Value);
            _presenter.SetMP3Quality((int)Int32.Parse(_MP3Quality.SelectedItem.ToString()));

            ManualProfile toSave = new ManualProfile();
            toSave.UpdateBpmPriority(_bpmBar.Value);
            toSave.UpdateDanceabilityPriority(_danceabilityBar.Value);
            toSave.UpdateKeyNumberPriority(_keyNumberBar.Value);
            toSave.UpdateKeyTonalityPriority(_keyTonalityBar.Value);
     
            _presenter.SetProfile(toSave);

            _presenter.SaveParameters();
            OnApplyButtonClick(sender, e);
            Hide();
        }

        private void OnFormCloseButtonClick(object sender, FormClosingEventArgs e)
        {
            OnCancelButtonClick(sender, e);
        }

        private void OnNormalProfileClick(object sender, EventArgs e)
        {
            _presenter.SetProfile(new BasicProfile());  
        }

        private void OnTonalityProfileClick(object sender, EventArgs e)
        {
            _presenter.SetProfile(new TonalityProfile());
        }

        private void OnRhythmProfileClick(object sender, EventArgs e)
        {
            _presenter.SetProfile(new RhythmProfile());
        }

        public void LoadParameters(Settings param)
        {
            _transitionDuration.Value = Int32.Parse(param.TransitionDuration);
            _mixDuration.Value = Int32.Parse(param.MixDuration);
            _bpmBar.Value = (int)Int32.Parse(param.BpmPriority);
            _keyTonalityBar.Value = (int)Int32.Parse(param.KeyTonalityPriority);
            _keyNumberBar.Value = (int)Int32.Parse(param.KeyNumberPriority);
            _danceabilityBar.Value = (int)Int32.Parse(param.DanceabilityPriority);
            _MP3Quality.SelectedIndex = _MP3Quality.FindString(param.Mp3Quality);
            AudioIO.ExportQuality = (LAMEPreset)Int32.Parse(param.Mp3Quality);
        }

    }
}
