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
using Automix_Data_Management.Model;

namespace Automix_UI.Forms
{
    public partial class ParameterForm : Form, IViewWithParameters
    {
        private IProfileDistance _actualProfile;
        private MainForm _mainForm;

        private readonly PresenterParameter _presenter;

        private int _bpmPriority;
        private int _keyTonalityPriority;
        private int _keyNumberPriority;
        private int _danceabilityPriority;

        public ParameterForm(MainForm mainForm)
        {
            InitializeComponent();
            _normalRadioButton.Checked = true;
            _presenter = new PresenterParameter(this);
            _actualProfile = new BasicProfile();
            _presenter.setProfile(_actualProfile);  
            _mainForm = mainForm;
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
            _presenter.setProfile(new BasicProfile());  
        }

        private void OnTonalityProfileClick(object sender, EventArgs e)
        {
            _presenter.setProfile(new TonalityProfile());
        }

        private void OnRhythmProfileClick(object sender, EventArgs e)
        {
            _presenter.setProfile(new RhythmProfile());
        }

        private void UpdateAdvancedUI()
        {
        }

        public void LoadParameters(Parameters param)
        {
            _transitionDuration.Value = Int32.Parse(param.TransitionDuration);
            _mixDuration.Value = Int32.Parse(param.MixDuration);
            _bpmBar.Value = (int)((_actualProfile.BpmPriority) / 120);
            _keyTonalityBar.Value = (int)((_actualProfile.KeyTonalityPriority) / 200);
            _keyNumberBar.Value = (int)((_actualProfile.KeyNumberPriority) / 2);
            _danceabilityBar.Value = (int)_actualProfile.DanceabilityPriority;

        }
    }
}
