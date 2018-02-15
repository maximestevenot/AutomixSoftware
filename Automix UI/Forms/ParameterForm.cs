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
            _mainForm = mainForm;
        }

        private void OnCancelButtonClick(object sender, EventArgs e)
        {
            Hide();
        }

        private void OnApplyButtonClick(object sender, EventArgs e)
        {
            
            _applyButton.Enabled = false;
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
        }

        private void OnTonalityProfileClick(object sender, EventArgs e)
        {
            _actualProfile = new TonalityProfile();
        }

        private void OnRhythmProfileClick(object sender, EventArgs e)
        {
            _actualProfile = new RhythmProfile();
        }
    }
}
