using Automix_AI.Distances;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static Automix_Data_Management.SettingsAccessor;

namespace Automix_UI.Forms
{
    public partial class ParameterForm : Form
    {
        private IProfileDistance _actualProfile;
        private MainForm _mainForm;

        private int _bpmPriority;
        private int _keyTonalityPriority;
        private int _keyNumberPriority;
        private int _danceabilityPriority;

        public ParameterForm(MainForm mainForm)
        {
            InitializeComponent();
            _normalRadioButton.Checked = true;
            _actualProfile = new BasicProfile();
            _mainForm = mainForm;
            UpdateAdvancedUI();
        }

        private void OnCancelButtonClick(object sender, EventArgs e)
        {
            Hide();
        }

        private void OnApplyButtonClick(object sender, EventArgs e)
        {
            _mainForm.UpdateSortProfile(_actualProfile);
        }

        private void OnOKButtonClick(object sender, EventArgs e)
        {
            OnApplyButtonClick(sender, e);
            Hide();
        }

        private void OnFormCloseButtonClick(object sender, FormClosingEventArgs e)
        {
            OnCancelButtonClick(sender, e);
        }

        private void OnNormalProfileClick(object sender, EventArgs e)
        {
            _actualProfile = new BasicProfile();
            UpdateAdvancedUI();
        }

        private void OnTonalityProfileClick(object sender, EventArgs e)
        {
            _actualProfile = new TonalityProfile();
            UpdateAdvancedUI();
        }

        private void OnRhythmProfileClick(object sender, EventArgs e)
        {
            _actualProfile = new RhythmProfile();
            UpdateAdvancedUI();
        }

        private void UpdateAdvancedUI()
        {
            _bpmBar.Value = (int) ((_actualProfile.BpmPriority) / 120);
            _keyTonalityBar.Value = (int) ((_actualProfile.KeyTonalityPriority) / 200);
            _keyNumberBar.Value = (int) ((_actualProfile.KeyNumberPriority) / 2);
            _danceabilityBar.Value = (int) _actualProfile.DanceabilityPriority;

        }

        private void TransitionDuration_ValueChanged(object sender, EventArgs e)
        {
            Automix_Data_Management.SettingsAccessor.SetSetting(Automix_Data_Management.SettingsAccessor.Settings.transitionDuration, "10");
        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {
            Automix_Data_Management.SettingsAccessor.SetSetting(Automix_Data_Management.SettingsAccessor.Settings.mixDuration, "45");

        }
    }
}
