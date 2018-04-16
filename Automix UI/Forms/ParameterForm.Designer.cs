namespace Automix_UI.Forms
{
    partial class ParameterForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.label8 = new System.Windows.Forms.Label();
            this._MP3Quality = new System.Windows.Forms.ComboBox();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this._mixDuration = new System.Windows.Forms.NumericUpDown();
            this._transitionDuration = new System.Windows.Forms.NumericUpDown();
            this.label5 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this._tonalityRadioButton = new System.Windows.Forms.RadioButton();
            this._rhythmRadioButton = new System.Windows.Forms.RadioButton();
            this._normalRadioButton = new System.Windows.Forms.RadioButton();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this._keyTonalityBar = new System.Windows.Forms.TrackBar();
            this._keyNumberBar = new System.Windows.Forms.TrackBar();
            this._danceabilityBar = new System.Windows.Forms.TrackBar();
            this._bpmBar = new System.Windows.Forms.TrackBar();
            this.label1 = new System.Windows.Forms.Label();
            this._applyButton = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.toolTip1 = new System.Windows.Forms.ToolTip(this.components);
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this._mixDuration)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this._transitionDuration)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.tableLayoutPanel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this._keyTonalityBar)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this._keyNumberBar)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this._danceabilityBar)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this._bpmBar)).BeginInit();
            this.SuspendLayout();
            // 
            // tabControl1
            // 
            this.tabControl1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Location = new System.Drawing.Point(12, 12);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(634, 302);
            this.tabControl1.TabIndex = 0;
            // 
            // tabPage1
            // 
            this.tabPage1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(69)))), ((int)(((byte)(69)))));
            this.tabPage1.Controls.Add(this.label8);
            this.tabPage1.Controls.Add(this._MP3Quality);
            this.tabPage1.Controls.Add(this.label7);
            this.tabPage1.Controls.Add(this.label6);
            this.tabPage1.Controls.Add(this._mixDuration);
            this.tabPage1.Controls.Add(this._transitionDuration);
            this.tabPage1.Controls.Add(this.label5);
            this.tabPage1.Controls.Add(this.groupBox1);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(626, 276);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Basic";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.ForeColor = System.Drawing.Color.White;
            this.label8.Location = new System.Drawing.Point(275, 191);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(40, 13);
            this.label8.TabIndex = 7;
            this.label8.Text = "Kbits/s";
            // 
            // _MP3Quality
            // 
            this._MP3Quality.AutoCompleteCustomSource.AddRange(new string[] {
            "8",
            "16",
            "32",
            "48",
            "64",
            "96",
            "128",
            "160",
            "256",
            "320"});
            this._MP3Quality.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this._MP3Quality.FormattingEnabled = true;
            this._MP3Quality.Items.AddRange(new object[] {
            "8",
            "16",
            "32",
            "48",
            "64",
            "96",
            "128",
            "256",
            "320"});
            this._MP3Quality.Location = new System.Drawing.Point(195, 188);
            this._MP3Quality.Name = "_MP3Quality";
            this._MP3Quality.Size = new System.Drawing.Size(74, 21);
            this._MP3Quality.TabIndex = 6;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.ForeColor = System.Drawing.Color.White;
            this.label7.Location = new System.Drawing.Point(3, 191);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(160, 13);
            this.label7.TabIndex = 5;
            this.label7.Text = "Quality of the exported MP3 file :";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.ForeColor = System.Drawing.Color.White;
            this.label6.Location = new System.Drawing.Point(3, 153);
            this.label6.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(104, 13);
            this.label6.TabIndex = 4;
            this.label6.Text = "Duration of the mix : ";
            // 
            // _mixDuration
            // 
            this._mixDuration.Location = new System.Drawing.Point(195, 151);
            this._mixDuration.Name = "_mixDuration";
            this._mixDuration.Size = new System.Drawing.Size(90, 20);
            this._mixDuration.TabIndex = 3;
            this.toolTip1.SetToolTip(this._mixDuration, "Recommended transition durations stands between 5 and 30 seconds");
            this._mixDuration.Value = new decimal(new int[] {
            30,
            0,
            0,
            0});
            // 
            // _transitionDuration
            // 
            this._transitionDuration.Location = new System.Drawing.Point(195, 113);
            this._transitionDuration.Name = "_transitionDuration";
            this._transitionDuration.Size = new System.Drawing.Size(90, 20);
            this._transitionDuration.TabIndex = 2;
            this.toolTip1.SetToolTip(this._transitionDuration, "Recommended transition durations stands between 5 and 30 seconds");
            this._transitionDuration.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.ForeColor = System.Drawing.Color.White;
            this.label5.Location = new System.Drawing.Point(3, 115);
            this.label5.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(136, 13);
            this.label5.TabIndex = 1;
            this.label5.Text = "Duration of the transitions : ";
            // 
            // groupBox1
            // 
            this.groupBox1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox1.Controls.Add(this._tonalityRadioButton);
            this.groupBox1.Controls.Add(this._rhythmRadioButton);
            this.groupBox1.Controls.Add(this._normalRadioButton);
            this.groupBox1.ForeColor = System.Drawing.Color.White;
            this.groupBox1.Location = new System.Drawing.Point(6, 6);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(614, 92);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Sort Profile";
            // 
            // _tonalityRadioButton
            // 
            this._tonalityRadioButton.AutoSize = true;
            this._tonalityRadioButton.Location = new System.Drawing.Point(6, 42);
            this._tonalityRadioButton.Name = "_tonalityRadioButton";
            this._tonalityRadioButton.Size = new System.Drawing.Size(62, 17);
            this._tonalityRadioButton.TabIndex = 2;
            this._tonalityRadioButton.TabStop = true;
            this._tonalityRadioButton.Text = "Tonality";
            this.toolTip1.SetToolTip(this._tonalityRadioButton, "Click to set a tonality oriented profile");
            this._tonalityRadioButton.UseVisualStyleBackColor = true;
            this._tonalityRadioButton.Click += new System.EventHandler(this.OnTonalityProfileClick);
            // 
            // _rhythmRadioButton
            // 
            this._rhythmRadioButton.AutoSize = true;
            this._rhythmRadioButton.Location = new System.Drawing.Point(6, 65);
            this._rhythmRadioButton.Name = "_rhythmRadioButton";
            this._rhythmRadioButton.Size = new System.Drawing.Size(61, 17);
            this._rhythmRadioButton.TabIndex = 1;
            this._rhythmRadioButton.TabStop = true;
            this._rhythmRadioButton.Text = "Rhythm";
            this.toolTip1.SetToolTip(this._rhythmRadioButton, "Click to set a rhythm oriented profile");
            this._rhythmRadioButton.UseVisualStyleBackColor = true;
            this._rhythmRadioButton.Click += new System.EventHandler(this.OnRhythmProfileClick);
            // 
            // _normalRadioButton
            // 
            this._normalRadioButton.AutoSize = true;
            this._normalRadioButton.Location = new System.Drawing.Point(6, 19);
            this._normalRadioButton.Name = "_normalRadioButton";
            this._normalRadioButton.Size = new System.Drawing.Size(58, 17);
            this._normalRadioButton.TabIndex = 0;
            this._normalRadioButton.TabStop = true;
            this._normalRadioButton.Text = "Normal";
            this.toolTip1.SetToolTip(this._normalRadioButton, "Click to set a balanced ratio between tonality and rhythm");
            this._normalRadioButton.UseVisualStyleBackColor = true;
            this._normalRadioButton.Click += new System.EventHandler(this.OnNormalProfileClick);
            // 
            // tabPage2
            // 
            this.tabPage2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(69)))), ((int)(((byte)(69)))));
            this.tabPage2.Controls.Add(this.tableLayoutPanel1);
            this.tabPage2.ForeColor = System.Drawing.Color.White;
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(626, 276);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Advanced";
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 2;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 15.16129F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 84.83871F));
            this.tableLayoutPanel1.Controls.Add(this.label4, 0, 4);
            this.tableLayoutPanel1.Controls.Add(this.label3, 0, 3);
            this.tableLayoutPanel1.Controls.Add(this.label2, 0, 2);
            this.tableLayoutPanel1.Controls.Add(this._keyTonalityBar, 1, 2);
            this.tableLayoutPanel1.Controls.Add(this._keyNumberBar, 1, 3);
            this.tableLayoutPanel1.Controls.Add(this._danceabilityBar, 1, 4);
            this.tableLayoutPanel1.Controls.Add(this._bpmBar, 1, 1);
            this.tableLayoutPanel1.Controls.Add(this.label1, 0, 1);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(3, 3);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 5;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(620, 270);
            this.tableLayoutPanel1.TabIndex = 1;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Dock = System.Windows.Forms.DockStyle.Fill;
            this.label4.Location = new System.Drawing.Point(3, 206);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(87, 64);
            this.label4.TabIndex = 7;
            this.label4.Text = "Danceability";
            this.label4.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.label3.Location = new System.Drawing.Point(3, 144);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(87, 62);
            this.label3.TabIndex = 6;
            this.label3.Text = "Key Number";
            this.label3.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.label2.Location = new System.Drawing.Point(3, 82);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(87, 62);
            this.label2.TabIndex = 5;
            this.label2.Text = "Key Tonality";
            this.label2.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // _keyTonalityBar
            // 
            this._keyTonalityBar.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(69)))), ((int)(((byte)(69)))));
            this._keyTonalityBar.Dock = System.Windows.Forms.DockStyle.Fill;
            this._keyTonalityBar.Location = new System.Drawing.Point(96, 85);
            this._keyTonalityBar.Maximum = 20;
            this._keyTonalityBar.Name = "_keyTonalityBar";
            this._keyTonalityBar.Size = new System.Drawing.Size(521, 56);
            this._keyTonalityBar.TabIndex = 1;
            // 
            // _keyNumberBar
            // 
            this._keyNumberBar.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(69)))), ((int)(((byte)(69)))));
            this._keyNumberBar.Dock = System.Windows.Forms.DockStyle.Fill;
            this._keyNumberBar.Location = new System.Drawing.Point(96, 147);
            this._keyNumberBar.Maximum = 20;
            this._keyNumberBar.Name = "_keyNumberBar";
            this._keyNumberBar.Size = new System.Drawing.Size(521, 56);
            this._keyNumberBar.TabIndex = 2;
            // 
            // _danceabilityBar
            // 
            this._danceabilityBar.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(69)))), ((int)(((byte)(69)))));
            this._danceabilityBar.Dock = System.Windows.Forms.DockStyle.Fill;
            this._danceabilityBar.Location = new System.Drawing.Point(96, 209);
            this._danceabilityBar.Maximum = 20;
            this._danceabilityBar.Name = "_danceabilityBar";
            this._danceabilityBar.Size = new System.Drawing.Size(521, 58);
            this._danceabilityBar.TabIndex = 3;
            // 
            // _bpmBar
            // 
            this._bpmBar.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(69)))), ((int)(((byte)(69)))));
            this._bpmBar.Dock = System.Windows.Forms.DockStyle.Fill;
            this._bpmBar.Location = new System.Drawing.Point(96, 23);
            this._bpmBar.Maximum = 20;
            this._bpmBar.Name = "_bpmBar";
            this._bpmBar.Size = new System.Drawing.Size(521, 56);
            this._bpmBar.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.label1.Location = new System.Drawing.Point(3, 20);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(87, 62);
            this.label1.TabIndex = 4;
            this.label1.Text = "BPM";
            this.label1.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // _applyButton
            // 
            this._applyButton.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this._applyButton.Location = new System.Drawing.Point(490, 321);
            this._applyButton.Name = "_applyButton";
            this._applyButton.Size = new System.Drawing.Size(75, 23);
            this._applyButton.TabIndex = 1;
            this._applyButton.Text = "Apply";
            this._applyButton.UseVisualStyleBackColor = true;
            this._applyButton.Click += new System.EventHandler(this.OnApplyButtonClick);
            // 
            // button2
            // 
            this.button2.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.button2.Location = new System.Drawing.Point(571, 321);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 2;
            this.button2.Text = "OK";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.OnOkButtonClick);
            // 
            // button3
            // 
            this.button3.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.button3.Location = new System.Drawing.Point(12, 320);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(75, 23);
            this.button3.TabIndex = 3;
            this.button3.Text = "Cancel";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.OnCancelButtonClick);
            // 
            // ParameterForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(69)))), ((int)(((byte)(69)))));
            this.ClientSize = new System.Drawing.Size(658, 356);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this._applyButton);
            this.Controls.Add(this.tabControl1);
            this.MaximumSize = new System.Drawing.Size(740, 579);
            this.MinimumSize = new System.Drawing.Size(639, 328);
            this.Name = "ParameterForm";
            this.Text = "ParameterForm";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.OnFormCloseButtonClick);
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this._mixDuration)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this._transitionDuration)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this._keyTonalityBar)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this._keyNumberBar)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this._danceabilityBar)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this._bpmBar)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton _tonalityRadioButton;
        private System.Windows.Forms.RadioButton _rhythmRadioButton;
        private System.Windows.Forms.RadioButton _normalRadioButton;
        private System.Windows.Forms.TrackBar _bpmBar;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.TrackBar _keyTonalityBar;
        private System.Windows.Forms.TrackBar _keyNumberBar;
        private System.Windows.Forms.TrackBar _danceabilityBar;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button _applyButton;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.ToolTip toolTip1;
        private System.Windows.Forms.NumericUpDown _transitionDuration;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.NumericUpDown _mixDuration;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.ComboBox _MP3Quality;
        private System.Windows.Forms.Label label7;
    }
}