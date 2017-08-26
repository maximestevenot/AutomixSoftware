namespace Automix_UI.Forms
{
    partial class UserDocForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(GetType());
            this.tableLayoutPanel1 = (new System.Windows.Forms.TableLayoutPanel());
            this.tabControl1 = (new System.Windows.Forms.TabControl());
            this._bpmTab = (new System.Windows.Forms.TabPage());
            this.richTextBox1 = (new System.Windows.Forms.RichTextBox());
            this._keyPage = (new System.Windows.Forms.TabPage());
            this.tableLayoutPanel2 = (new System.Windows.Forms.TableLayoutPanel());
            this.pictureBox1 = (new System.Windows.Forms.PictureBox());
            this._keyDescription = (new System.Windows.Forms.RichTextBox());
            this.okButton = (new System.Windows.Forms.Button());
            this.tableLayoutPanel1.SuspendLayout();
            this.tabControl1.SuspendLayout();
            this._bpmTab.SuspendLayout();
            this._keyPage.SuspendLayout();
            this.tableLayoutPanel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)this.pictureBox1).BeginInit();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            resources.ApplyResources(this.tableLayoutPanel1, "tableLayoutPanel1");
            this.tableLayoutPanel1.Controls.Add(this.tabControl1, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.okButton, 1, 1);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            // 
            // tabControl1
            // 
            this.tableLayoutPanel1.SetColumnSpan(this.tabControl1, 2);
            this.tabControl1.Controls.Add(this._bpmTab);
            this.tabControl1.Controls.Add(this._keyPage);
            resources.ApplyResources(this.tabControl1, "tabControl1");
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.SizeMode = System.Windows.Forms.TabSizeMode.FillToRight;
            // 
            // _bpmTab
            // 
            this._bpmTab.Controls.Add(this.richTextBox1);
            resources.ApplyResources(this._bpmTab, "_bpmTab");
            this._bpmTab.Name = "_bpmTab";
            this._bpmTab.UseVisualStyleBackColor = true;
            // 
            // richTextBox1
            // 
            this.richTextBox1.BackColor = System.Drawing.SystemColors.Window;
            this.richTextBox1.BorderStyle = System.Windows.Forms.BorderStyle.None;
            resources.ApplyResources(this.richTextBox1, "richTextBox1");
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.ReadOnly = true;
            this.richTextBox1.ShortcutsEnabled = false;
            // 
            // _keyPage
            // 
            resources.ApplyResources(this._keyPage, "_keyPage");
            this._keyPage.Controls.Add(this.tableLayoutPanel2);
            this._keyPage.Name = "_keyPage";
            this._keyPage.UseVisualStyleBackColor = true;
            // 
            // tableLayoutPanel2
            // 
            resources.ApplyResources(this.tableLayoutPanel2, "tableLayoutPanel2");
            this.tableLayoutPanel2.Controls.Add(this.pictureBox1, 0, 0);
            this.tableLayoutPanel2.Controls.Add(this._keyDescription, 1, 0);
            this.tableLayoutPanel2.Name = "tableLayoutPanel2";
            // 
            // pictureBox1
            // 
            resources.ApplyResources(this.pictureBox1, "pictureBox1");
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.TabStop = false;
            // 
            // _keyDescription
            // 
            this._keyDescription.BackColor = System.Drawing.SystemColors.Window;
            this._keyDescription.BorderStyle = System.Windows.Forms.BorderStyle.None;
            resources.ApplyResources(this._keyDescription, "_keyDescription");
            this._keyDescription.Name = "_keyDescription";
            this._keyDescription.ReadOnly = true;
            this._keyDescription.ShortcutsEnabled = false;
            // 
            // okButton
            // 
            resources.ApplyResources(this.okButton, "okButton");
            this.okButton.Name = "okButton";
            this.okButton.UseVisualStyleBackColor = true;
            this.okButton.Click += new System.EventHandler(this.OnOkButtonClick);
            // 
            // UserDocForm
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.tableLayoutPanel1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "UserDocForm";
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tabControl1.ResumeLayout(false);
            this._bpmTab.ResumeLayout(false);
            this._keyPage.ResumeLayout(false);
            this.tableLayoutPanel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)this.pictureBox1).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();
        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage _bpmTab;
        private System.Windows.Forms.TabPage _keyPage;
        private System.Windows.Forms.Button okButton;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel2;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.RichTextBox _keyDescription;
        private System.Windows.Forms.RichTextBox richTextBox1;
    }
}