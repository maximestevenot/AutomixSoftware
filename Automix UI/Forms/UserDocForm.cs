// Copyright (C) 2016 - 2018 LesProjecteurs
// This file is part of Automix Software licensed under MIT License.

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
