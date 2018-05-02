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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ParameterForm));
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
            resources.ApplyResources(this.tabControl1, "tabControl1");
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
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
            resources.ApplyResources(this.tabPage1, "tabPage1");
            this.tabPage1.Name = "tabPage1";
            // 
            // label8
            // 
            resources.ApplyResources(this.label8, "label8");
            this.label8.ForeColor = System.Drawing.Color.White;
            this.label8.Name = "label8";
            // 
            // _MP3Quality
            // 
            this._MP3Quality.AutoCompleteCustomSource.AddRange(new string[] {
            resources.GetString("_MP3Quality.AutoCompleteCustomSource"),
            resources.GetString("_MP3Quality.AutoCompleteCustomSource1"),
            resources.GetString("_MP3Quality.AutoCompleteCustomSource2"),
            resources.GetString("_MP3Quality.AutoCompleteCustomSource3"),
            resources.GetString("_MP3Quality.AutoCompleteCustomSource4"),
            resources.GetString("_MP3Quality.AutoCompleteCustomSource5"),
            resources.GetString("_MP3Quality.AutoCompleteCustomSource6"),
            resources.GetString("_MP3Quality.AutoCompleteCustomSource7"),
            resources.GetString("_MP3Quality.AutoCompleteCustomSource8"),
            resources.GetString("_MP3Quality.AutoCompleteCustomSource9")});
            this._MP3Quality.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this._MP3Quality.FormattingEnabled = true;
            this._MP3Quality.Items.AddRange(new object[] {
            resources.GetString("_MP3Quality.Items"),
            resources.GetString("_MP3Quality.Items1"),
            resources.GetString("_MP3Quality.Items2"),
            resources.GetString("_MP3Quality.Items3"),
            resources.GetString("_MP3Quality.Items4"),
            resources.GetString("_MP3Quality.Items5"),
            resources.GetString("_MP3Quality.Items6"),
            resources.GetString("_MP3Quality.Items7"),
            resources.GetString("_MP3Quality.Items8")});
            resources.ApplyResources(this._MP3Quality, "_MP3Quality");
            this._MP3Quality.Name = "_MP3Quality";
            // 
            // label7
            // 
            resources.ApplyResources(this.label7, "label7");
            this.label7.ForeColor = System.Drawing.Color.White;
            this.label7.Name = "label7";
            // 
            // label6
            // 
            resources.ApplyResources(this.label6, "label6");
            this.label6.ForeColor = System.Drawing.Color.White;
            this.label6.Name = "label6";
            // 
            // _mixDuration
            // 
            resources.ApplyResources(this._mixDuration, "_mixDuration");
            this._mixDuration.Name = "_mixDuration";
            this.toolTip1.SetToolTip(this._mixDuration, resources.GetString("_mixDuration.ToolTip"));
            this._mixDuration.Value = new decimal(new int[] {
            30,
            0,
            0,
            0});
            // 
            // _transitionDuration
            // 
            resources.ApplyResources(this._transitionDuration, "_transitionDuration");
            this._transitionDuration.Name = "_transitionDuration";
            this.toolTip1.SetToolTip(this._transitionDuration, resources.GetString("_transitionDuration.ToolTip"));
            this._transitionDuration.Value = new decimal(new int[] {
            10,
            0,
            0,
            0});
            // 
            // label5
            // 
            resources.ApplyResources(this.label5, "label5");
            this.label5.ForeColor = System.Drawing.Color.White;
            this.label5.Name = "label5";
            // 
            // groupBox1
            // 
            resources.ApplyResources(this.groupBox1, "groupBox1");
            this.groupBox1.Controls.Add(this._tonalityRadioButton);
            this.groupBox1.Controls.Add(this._rhythmRadioButton);
            this.groupBox1.Controls.Add(this._normalRadioButton);
            this.groupBox1.ForeColor = System.Drawing.Color.White;
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.TabStop = false;
            // 
            // _tonalityRadioButton
            // 
            resources.ApplyResources(this._tonalityRadioButton, "_tonalityRadioButton");
            this._tonalityRadioButton.Name = "_tonalityRadioButton";
            this._tonalityRadioButton.TabStop = true;
            this.toolTip1.SetToolTip(this._tonalityRadioButton, resources.GetString("_tonalityRadioButton.ToolTip"));
            this._tonalityRadioButton.UseVisualStyleBackColor = true;
            this._tonalityRadioButton.Click += new System.EventHandler(this.OnTonalityProfileClick);
            // 
            // _rhythmRadioButton
            // 
            resources.ApplyResources(this._rhythmRadioButton, "_rhythmRadioButton");
            this._rhythmRadioButton.Name = "_rhythmRadioButton";
            this._rhythmRadioButton.TabStop = true;
            this.toolTip1.SetToolTip(this._rhythmRadioButton, resources.GetString("_rhythmRadioButton.ToolTip"));
            this._rhythmRadioButton.UseVisualStyleBackColor = true;
            this._rhythmRadioButton.Click += new System.EventHandler(this.OnRhythmProfileClick);
            // 
            // _normalRadioButton
            // 
            resources.ApplyResources(this._normalRadioButton, "_normalRadioButton");
            this._normalRadioButton.Name = "_normalRadioButton";
            this._normalRadioButton.TabStop = true;
            this.toolTip1.SetToolTip(this._normalRadioButton, resources.GetString("_normalRadioButton.ToolTip"));
            this._normalRadioButton.UseVisualStyleBackColor = true;
            this._normalRadioButton.Click += new System.EventHandler(this.OnNormalProfileClick);
            // 
            // tabPage2
            // 
            this.tabPage2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(69)))), ((int)(((byte)(69)))));
            this.tabPage2.Controls.Add(this.tableLayoutPanel1);
            this.tabPage2.ForeColor = System.Drawing.Color.White;
            resources.ApplyResources(this.tabPage2, "tabPage2");
            this.tabPage2.Name = "tabPage2";
            // 
            // tableLayoutPanel1
            // 
            resources.ApplyResources(this.tableLayoutPanel1, "tableLayoutPanel1");
            this.tableLayoutPanel1.Controls.Add(this.label4, 0, 4);
            this.tableLayoutPanel1.Controls.Add(this.label3, 0, 3);
            this.tableLayoutPanel1.Controls.Add(this.label2, 0, 2);
            this.tableLayoutPanel1.Controls.Add(this._keyTonalityBar, 1, 2);
            this.tableLayoutPanel1.Controls.Add(this._keyNumberBar, 1, 3);
            this.tableLayoutPanel1.Controls.Add(this._danceabilityBar, 1, 4);
            this.tableLayoutPanel1.Controls.Add(this._bpmBar, 1, 1);
            this.tableLayoutPanel1.Controls.Add(this.label1, 0, 1);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            // 
            // label4
            // 
            resources.ApplyResources(this.label4, "label4");
            this.label4.Name = "label4";
            // 
            // label3
            // 
            resources.ApplyResources(this.label3, "label3");
            this.label3.Name = "label3";
            // 
            // label2
            // 
            resources.ApplyResources(this.label2, "label2");
            this.label2.Name = "label2";
            // 
            // _keyTonalityBar
            // 
            this._keyTonalityBar.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(69)))), ((int)(((byte)(69)))));
            resources.ApplyResources(this._keyTonalityBar, "_keyTonalityBar");
            this._keyTonalityBar.Maximum = 20;
            this._keyTonalityBar.Name = "_keyTonalityBar";
            // 
            // _keyNumberBar
            // 
            this._keyNumberBar.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(69)))), ((int)(((byte)(69)))));
            resources.ApplyResources(this._keyNumberBar, "_keyNumberBar");
            this._keyNumberBar.Maximum = 20;
            this._keyNumberBar.Name = "_keyNumberBar";
            // 
            // _danceabilityBar
            // 
            this._danceabilityBar.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(69)))), ((int)(((byte)(69)))));
            resources.ApplyResources(this._danceabilityBar, "_danceabilityBar");
            this._danceabilityBar.Maximum = 20;
            this._danceabilityBar.Name = "_danceabilityBar";
            // 
            // _bpmBar
            // 
            this._bpmBar.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(69)))), ((int)(((byte)(69)))));
            resources.ApplyResources(this._bpmBar, "_bpmBar");
            this._bpmBar.Maximum = 20;
            this._bpmBar.Name = "_bpmBar";
            // 
            // label1
            // 
            resources.ApplyResources(this.label1, "label1");
            this.label1.Name = "label1";
            // 
            // _applyButton
            // 
            resources.ApplyResources(this._applyButton, "_applyButton");
            this._applyButton.Name = "_applyButton";
            this._applyButton.UseVisualStyleBackColor = true;
            this._applyButton.Click += new System.EventHandler(this.OnApplyButtonClick);
            // 
            // button2
            // 
            resources.ApplyResources(this.button2, "button2");
            this.button2.Name = "button2";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.OnOkButtonClick);
            // 
            // button3
            // 
            resources.ApplyResources(this.button3, "button3");
            this.button3.Name = "button3";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.OnCancelButtonClick);
            // 
            // ParameterForm
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(69)))), ((int)(((byte)(69)))));
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this._applyButton);
            this.Controls.Add(this.tabControl1);
            this.Name = "ParameterForm";
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