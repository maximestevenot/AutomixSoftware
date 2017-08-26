// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using System;
using System.Windows.Forms;

namespace Automix_UI.Forms
{
    public partial class UserDocForm : Form
    {
        public UserDocForm()
        {
            InitializeComponent();
        }

        private void OnOkButtonClick(object sender, EventArgs e) => Close();
    }
}
