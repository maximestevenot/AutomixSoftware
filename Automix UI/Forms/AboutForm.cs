// Copyright (C) 2016 - 2018 LesProjecteurs
// This file is part of Automix Software licensed under MIT License.

using System;
using System.Windows.Forms;

namespace Automix_UI.Forms
{
    public partial class AboutForm : Form
    {
        public AboutForm()
        {
            InitializeComponent();
            var text = richTextBox1.Text;
            richTextBox1.Text = string.Format(text, GetEnhancedProductVersion());
        }

        private static string GetEnhancedProductVersion()
        {
            var productVersion = Application.ProductVersion;
            var lastDotIndex = productVersion.LastIndexOf(".", StringComparison.Ordinal);
            if (lastDotIndex > 0)
            {
                productVersion = productVersion.Substring(0, lastDotIndex);
            }
            return productVersion;
        }

        private void OnOkButtonClick(object sender, EventArgs e) => Close();
    }
}
