using Automix_AI.Distances;
using System;
using System.Windows.Forms;

namespace Automix_UI.Forms
{
    public partial class ParameterForm : Form
    {
        private IProfileDistance _actualProfile;
        private ManualProfile _resultProfile;
        private readonly MainForm _mainForm;

        private int _bpmPriorityValue;
        private int _keyTonalityPriorityValue;
        private int _keyNumberPriorityValue;
        private int _danceabilityPriorityValue;

        public ParameterForm(MainForm mainForm)
        {
            InitializeComponent();
            _normalRadioButton.Checked = true;
            _actualProfile = new BasicProfile();
            _mainForm = mainForm;
            UpdateAdvancedUi();
        }

        private void UpdatePriorities()
        {
            _bpmPriorityValue = _bpmBar.Value;
            _danceabilityPriorityValue = _danceabilityBar.Value;
            _keyNumberPriorityValue = _keyNumberBar.Value;
            _keyTonalityPriorityValue = _keyTonalityBar.Value;
        }

        private void ApplyPriorities()
        {
            _resultProfile = new ManualProfile(_bpmPriorityValue, _keyNumberPriorityValue,
                _keyTonalityPriorityValue, _danceabilityPriorityValue);
        }

        private void OnCancelButtonClick(object sender, EventArgs e)
        {
            Hide();
        }

        private void OnApplyButtonClick(object sender, EventArgs e)
        {
            ApplyPriorities();
        }

        private void OnOkButtonClick(object sender, EventArgs e)
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
            UpdateAdvancedUi();
        }

        private void OnTonalityProfileClick(object sender, EventArgs e)
        {
            _actualProfile = new TonalityProfile();
            UpdateAdvancedUi();
        }

        private void OnRhythmProfileClick(object sender, EventArgs e)
        {
            _actualProfile = new RhythmProfile();
            UpdateAdvancedUi();
        }

        private void UpdateAdvancedUi()
        {
            _bpmBar.Value = (int) ((_actualProfile.BpmPriority) / 120);
            _keyTonalityBar.Value = (int) ((_actualProfile.KeyTonalityPriority) / 200);
            _keyNumberBar.Value = (int) ((_actualProfile.KeyNumberPriority) / 2);
            _danceabilityBar.Value = (int) _actualProfile.DanceabilityPriority;
            UpdatePriorities();
        }

        private void AdvancedPageSelected(object sender, EventArgs e)
        {
            _resultProfile = new ManualProfile(_bpmPriorityValue, _keyNumberPriorityValue, 
                _keyTonalityPriorityValue, _danceabilityPriorityValue);
            _normalRadioButton.Checked = false;
            _rhythmRadioButton.Checked = false;
            _tonalityRadioButton.Checked = false;
        }

        private void OnScrollBpmBar(object sender, EventArgs e)
        {
            UpdatePriorities();
        }


        private void OnScrollKeyTonalityBar(object sender, EventArgs e)
        {
            UpdatePriorities();
        }

        private void OnScrollKeyNumberBar(object sender, EventArgs e)
        {
            UpdatePriorities();
        }

        private void OnScrollDanceabilityBar(object sender, EventArgs e)
        {
            UpdatePriorities();
        }
    }
}
