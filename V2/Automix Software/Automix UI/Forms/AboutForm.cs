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
    public partial class AboutForm : Form
    {
        public AboutForm()
        {
            InitializeComponent();
            var text = richTextBox1.Text;
            richTextBox1.Text = string.Format(text,Application.ProductVersion);
        }
        private void OnOkButtonClick(object sender, EventArgs e) => Close();
    }
}
