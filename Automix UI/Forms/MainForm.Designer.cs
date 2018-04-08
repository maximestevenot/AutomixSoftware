namespace Automix_UI.Forms
{
    partial class MainForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this._menuStrip = new System.Windows.Forms.MenuStrip();
            this._fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this._importMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this._exportMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this._generateMixMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this._exportTextFileMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this._cancelMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator = new System.Windows.Forms.ToolStripSeparator();
            this._quitMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this._optionsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this._dataBaseToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this._clearDBMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this._importDBMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this._exportDBMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this._stopMixToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this._chooseTempDirToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.preferencesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this._helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this._aboutCharacteristicsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this._aboutMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this._statusStrip = new System.Windows.Forms.StatusStrip();
            this._toolStripProgressBar = new System.Windows.Forms.ToolStripProgressBar();
            this._toolStripCurrentDir = new System.Windows.Forms.ToolStripStatusLabel();
            this._musicListView = new System.Windows.Forms.ListView();
            this.collectionName = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.collectionDuration = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.collectionBPM = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.collectionKey = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this._trackContextMenu = new System.Windows.Forms.ContextMenuStrip(this.components);
            this._deleteTrackToolStrip = new System.Windows.Forms.ToolStripMenuItem();
            this._selectAllToolStrip = new System.Windows.Forms.ToolStripMenuItem();
            this._lockTrackToolStrip = new System.Windows.Forms.ToolStripMenuItem();
            this._importButton = new System.Windows.Forms.Button();
            this._generateButton = new System.Windows.Forms.Button();
            this._logo = new System.Windows.Forms.PictureBox();
            this._sortButton = new System.Windows.Forms.Button();
            this._importBackgroundWorker = new System.ComponentModel.BackgroundWorker();
            this._sortBackgroundWorker = new System.ComponentModel.BackgroundWorker();
            this._exportBackgroundWorker = new System.ComponentModel.BackgroundWorker();
            this._toolTip = new System.Windows.Forms.ToolTip(this.components);
            this._playerbutton = new System.Windows.Forms.Button();
            this._skipButton = new System.Windows.Forms.Button();
            this._reloadButton = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this._playerTrackBar = new System.Windows.Forms.TrackBar();
            this._playerBackgroundWorker = new System.ComponentModel.BackgroundWorker();
            this.bindingSource1 = new System.Windows.Forms.BindingSource(this.components);
            this._trackBarTimer = new System.Windows.Forms.Timer(this.components);
            this._circularProgressBar = new AltoControls.CircularPB();
            this._menuStrip.SuspendLayout();
            this._statusStrip.SuspendLayout();
            this._trackContextMenu.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this._logo)).BeginInit();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this._playerTrackBar)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.bindingSource1)).BeginInit();
            this.SuspendLayout();
            // 
            // _menuStrip
            // 
            this._menuStrip.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(69)))), ((int)(((byte)(69)))));
            this._menuStrip.ImageScalingSize = new System.Drawing.Size(20, 20);
            this._menuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this._fileToolStripMenuItem,
            this._optionsToolStripMenuItem,
            this._helpToolStripMenuItem});
            resources.ApplyResources(this._menuStrip, "_menuStrip");
            this._menuStrip.Name = "_menuStrip";
            // 
            // _fileToolStripMenuItem
            // 
            this._fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this._importMenuItem,
            this._exportMenuItem,
            this._cancelMenuItem,
            this.toolStripSeparator,
            this._quitMenuItem});
            this._fileToolStripMenuItem.ForeColor = System.Drawing.Color.White;
            this._fileToolStripMenuItem.Name = "_fileToolStripMenuItem";
            resources.ApplyResources(this._fileToolStripMenuItem, "_fileToolStripMenuItem");
            // 
            // _importMenuItem
            // 
            this._importMenuItem.ForeColor = System.Drawing.Color.White;
            this._importMenuItem.Name = "_importMenuItem";
            resources.ApplyResources(this._importMenuItem, "_importMenuItem");
            this._importMenuItem.Click += new System.EventHandler(this.OnImportMenuItemClick);
            // 
            // _exportMenuItem
            // 
            this._exportMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this._generateMixMenuItem,
            this._exportTextFileMenuItem});
            this._exportMenuItem.ForeColor = System.Drawing.Color.White;
            this._exportMenuItem.Name = "_exportMenuItem";
            resources.ApplyResources(this._exportMenuItem, "_exportMenuItem");
            // 
            // _generateMixMenuItem
            // 
            this._generateMixMenuItem.ForeColor = System.Drawing.Color.White;
            this._generateMixMenuItem.Name = "_generateMixMenuItem";
            resources.ApplyResources(this._generateMixMenuItem, "_generateMixMenuItem");
            this._generateMixMenuItem.Click += new System.EventHandler(this.OnGenerateMixMenuItemClick);
            // 
            // _exportTextFileMenuItem
            // 
            this._exportTextFileMenuItem.ForeColor = System.Drawing.Color.White;
            this._exportTextFileMenuItem.Name = "_exportTextFileMenuItem";
            resources.ApplyResources(this._exportTextFileMenuItem, "_exportTextFileMenuItem");
            this._exportTextFileMenuItem.Click += new System.EventHandler(this.OnExportTextFileMenuItemClick);
            // 
            // _cancelMenuItem
            // 
            this._cancelMenuItem.ForeColor = System.Drawing.Color.White;
            this._cancelMenuItem.Name = "_cancelMenuItem";
            resources.ApplyResources(this._cancelMenuItem, "_cancelMenuItem");
            this._cancelMenuItem.Click += new System.EventHandler(this.OnCancelMenuItemClick);
            // 
            // toolStripSeparator
            // 
            this.toolStripSeparator.Name = "toolStripSeparator";
            resources.ApplyResources(this.toolStripSeparator, "toolStripSeparator");
            // 
            // _quitMenuItem
            // 
            this._quitMenuItem.ForeColor = System.Drawing.Color.White;
            this._quitMenuItem.Name = "_quitMenuItem";
            resources.ApplyResources(this._quitMenuItem, "_quitMenuItem");
            this._quitMenuItem.Click += new System.EventHandler(this.OnQuitMenuItemClick);
            // 
            // _optionsToolStripMenuItem
            // 
            this._optionsToolStripMenuItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
            this._optionsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this._dataBaseToolStripMenuItem,
            this._stopMixToolStripMenuItem,
            this._chooseTempDirToolStripMenuItem,
            this.preferencesToolStripMenuItem});
            this._optionsToolStripMenuItem.ForeColor = System.Drawing.Color.White;
            this._optionsToolStripMenuItem.Name = "_optionsToolStripMenuItem";
            resources.ApplyResources(this._optionsToolStripMenuItem, "_optionsToolStripMenuItem");
            // 
            // _dataBaseToolStripMenuItem
            // 
            this._dataBaseToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this._clearDBMenuItem,
            this._importDBMenuItem,
            this._exportDBMenuItem});
            this._dataBaseToolStripMenuItem.ForeColor = System.Drawing.Color.White;
            this._dataBaseToolStripMenuItem.Name = "_dataBaseToolStripMenuItem";
            resources.ApplyResources(this._dataBaseToolStripMenuItem, "_dataBaseToolStripMenuItem");
            // 
            // _clearDBMenuItem
            // 
            this._clearDBMenuItem.ForeColor = System.Drawing.Color.White;
            this._clearDBMenuItem.Name = "_clearDBMenuItem";
            resources.ApplyResources(this._clearDBMenuItem, "_clearDBMenuItem");
            this._clearDBMenuItem.Click += new System.EventHandler(this.OnClearDbMenuItemClick);
            // 
            // _importDBMenuItem
            // 
            this._importDBMenuItem.ForeColor = System.Drawing.Color.White;
            this._importDBMenuItem.Name = "_importDBMenuItem";
            resources.ApplyResources(this._importDBMenuItem, "_importDBMenuItem");
            this._importDBMenuItem.Click += new System.EventHandler(this.OnChooseImportDBMenuItemClick);
            // 
            // _exportDBMenuItem
            // 
            this._exportDBMenuItem.ForeColor = System.Drawing.Color.White;
            this._exportDBMenuItem.Name = "_exportDBMenuItem";
            resources.ApplyResources(this._exportDBMenuItem, "_exportDBMenuItem");
            this._exportDBMenuItem.Click += new System.EventHandler(this.OnChooseExportDBMenuItemClick);
            // 
            // _stopMixToolStripMenuItem
            // 
            this._stopMixToolStripMenuItem.ForeColor = System.Drawing.Color.White;
            this._stopMixToolStripMenuItem.Name = "_stopMixToolStripMenuItem";
            resources.ApplyResources(this._stopMixToolStripMenuItem, "_stopMixToolStripMenuItem");
            this._stopMixToolStripMenuItem.Click += new System.EventHandler(this.OnStopMixToolStripMenuItemClick);
            // 
            // _chooseTempDirToolStripMenuItem
            // 
            this._chooseTempDirToolStripMenuItem.ForeColor = System.Drawing.Color.White;
            this._chooseTempDirToolStripMenuItem.Name = "_chooseTempDirToolStripMenuItem";
            resources.ApplyResources(this._chooseTempDirToolStripMenuItem, "_chooseTempDirToolStripMenuItem");
            this._chooseTempDirToolStripMenuItem.Click += new System.EventHandler(this.OnChooseTempDirButtonClick);
            // 
            // preferencesToolStripMenuItem
            // 
            this.preferencesToolStripMenuItem.ForeColor = System.Drawing.Color.White;
            this.preferencesToolStripMenuItem.Name = "preferencesToolStripMenuItem";
            resources.ApplyResources(this.preferencesToolStripMenuItem, "preferencesToolStripMenuItem");
            this.preferencesToolStripMenuItem.Click += new System.EventHandler(this.OnPreferencesToolStripMenuItemClick);
            // 
            // _helpToolStripMenuItem
            // 
            this._helpToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this._aboutCharacteristicsToolStripMenuItem,
            this.toolStripSeparator1,
            this._aboutMenuItem});
            this._helpToolStripMenuItem.ForeColor = System.Drawing.Color.White;
            this._helpToolStripMenuItem.Name = "_helpToolStripMenuItem";
            resources.ApplyResources(this._helpToolStripMenuItem, "_helpToolStripMenuItem");
            // 
            // _aboutCharacteristicsToolStripMenuItem
            // 
            this._aboutCharacteristicsToolStripMenuItem.ForeColor = System.Drawing.Color.White;
            this._aboutCharacteristicsToolStripMenuItem.Name = "_aboutCharacteristicsToolStripMenuItem";
            resources.ApplyResources(this._aboutCharacteristicsToolStripMenuItem, "_aboutCharacteristicsToolStripMenuItem");
            this._aboutCharacteristicsToolStripMenuItem.Click += new System.EventHandler(this.OnAboutCharacteristicsMenuItemClick);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            resources.ApplyResources(this.toolStripSeparator1, "toolStripSeparator1");
            // 
            // _aboutMenuItem
            // 
            this._aboutMenuItem.ForeColor = System.Drawing.Color.White;
            this._aboutMenuItem.Name = "_aboutMenuItem";
            resources.ApplyResources(this._aboutMenuItem, "_aboutMenuItem");
            this._aboutMenuItem.Click += new System.EventHandler(this.OnAboutMenuItemClick);
            // 
            // _statusStrip
            // 
            resources.ApplyResources(this._statusStrip, "_statusStrip");
            this._statusStrip.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(69)))), ((int)(((byte)(69)))));
            this._statusStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this._toolStripProgressBar,
            this._toolStripCurrentDir});
            this._statusStrip.Name = "_statusStrip";
            // 
            // _toolStripProgressBar
            // 
            this._toolStripProgressBar.Margin = new System.Windows.Forms.Padding(3, 3, 1, 3);
            this._toolStripProgressBar.Maximum = 1000;
            this._toolStripProgressBar.Name = "_toolStripProgressBar";
            resources.ApplyResources(this._toolStripProgressBar, "_toolStripProgressBar");
            // 
            // _toolStripCurrentDir
            // 
            this._toolStripCurrentDir.Margin = new System.Windows.Forms.Padding(5, 3, 0, 2);
            this._toolStripCurrentDir.Name = "_toolStripCurrentDir";
            resources.ApplyResources(this._toolStripCurrentDir, "_toolStripCurrentDir");
            // 
            // _musicListView
            // 
            resources.ApplyResources(this._musicListView, "_musicListView");
            this._musicListView.AllowDrop = true;
            this._musicListView.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(69)))), ((int)(((byte)(69)))));
            this._musicListView.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this._musicListView.CheckBoxes = true;
            this._musicListView.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.collectionName,
            this.collectionDuration,
            this.collectionBPM,
            this.collectionKey});
            this._musicListView.ContextMenuStrip = this._trackContextMenu;
            this._musicListView.ForeColor = System.Drawing.Color.White;
            this._musicListView.FullRowSelect = true;
            this._musicListView.HeaderStyle = System.Windows.Forms.ColumnHeaderStyle.Nonclickable;
            this._musicListView.LabelEdit = true;
            this._musicListView.Name = "_musicListView";
            this._musicListView.UseCompatibleStateImageBehavior = false;
            this._musicListView.View = System.Windows.Forms.View.Details;
            this._musicListView.DrawColumnHeader += new System.Windows.Forms.DrawListViewColumnHeaderEventHandler(this.MusicListView_DrawColumnHeader);
            this._musicListView.DrawItem += new System.Windows.Forms.DrawListViewItemEventHandler(this.MusicListView_DrawItem);
            this._musicListView.DrawSubItem += new System.Windows.Forms.DrawListViewSubItemEventHandler(this.MusicListView_DrawSubItem);
            this._musicListView.ItemDrag += new System.Windows.Forms.ItemDragEventHandler(this.MusicListView_ItemDrag);
            this._musicListView.DragDrop += new System.Windows.Forms.DragEventHandler(this.MusicListView_DragDrop);
            this._musicListView.DragEnter += new System.Windows.Forms.DragEventHandler(this.MusicListView_DragEnter);
            this._musicListView.DragOver += new System.Windows.Forms.DragEventHandler(this.MusicListView_DragOver);
            // 
            // collectionName
            // 
            resources.ApplyResources(this.collectionName, "collectionName");
            // 
            // collectionDuration
            // 
            resources.ApplyResources(this.collectionDuration, "collectionDuration");
            // 
            // collectionBPM
            // 
            resources.ApplyResources(this.collectionBPM, "collectionBPM");
            // 
            // collectionKey
            // 
            resources.ApplyResources(this.collectionKey, "collectionKey");
            // 
            // _trackContextMenu
            // 
            this._trackContextMenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this._deleteTrackToolStrip,
            this._selectAllToolStrip,
            this._lockTrackToolStrip});
            this._trackContextMenu.Name = "_listViewcontextMenu";
            resources.ApplyResources(this._trackContextMenu, "_trackContextMenu");
            this._trackContextMenu.Opening += new System.ComponentModel.CancelEventHandler(this.OnTrackContextMenuOpening);
            // 
            // _deleteTrackToolStrip
            // 
            this._deleteTrackToolStrip.ForeColor = System.Drawing.Color.White;
            resources.ApplyResources(this._deleteTrackToolStrip, "_deleteTrackToolStrip");
            this._deleteTrackToolStrip.Name = "_deleteTrackToolStrip";
            this._deleteTrackToolStrip.Click += new System.EventHandler(this.OnDeleteTrackToolStripClick);
            // 
            // _selectAllToolStrip
            // 
            this._selectAllToolStrip.ForeColor = System.Drawing.Color.White;
            this._selectAllToolStrip.Name = "_selectAllToolStrip";
            resources.ApplyResources(this._selectAllToolStrip, "_selectAllToolStrip");
            this._selectAllToolStrip.Click += new System.EventHandler(this.OnSelectAllMenuItemClick);
            // 
            // _lockTrackToolStrip
            // 
            this._lockTrackToolStrip.ForeColor = System.Drawing.Color.White;
            this._lockTrackToolStrip.Name = "_lockTrackToolStrip";
            resources.ApplyResources(this._lockTrackToolStrip, "_lockTrackToolStrip");
            this._lockTrackToolStrip.Click += new System.EventHandler(this.OnLockTrackToolStripClick);
            // 
            // _importButton
            // 
            resources.ApplyResources(this._importButton, "_importButton");
            this._importButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(163)))), ((int)(((byte)(38)))), ((int)(((byte)(56)))));
            this._importButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this._importButton.FlatAppearance.BorderSize = 0;
            this._importButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(176)))), ((int)(((byte)(23)))), ((int)(((byte)(46)))));
            this._importButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(214)))), ((int)(((byte)(28)))), ((int)(((byte)(56)))));
            this._importButton.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this._importButton.Name = "_importButton";
            this._toolTip.SetToolTip(this._importButton, resources.GetString("_importButton.ToolTip"));
            this._importButton.UseVisualStyleBackColor = false;
            this._importButton.EnabledChanged += new System.EventHandler(this.OnButtonEnabledChanged);
            this._importButton.Click += new System.EventHandler(this.OnImportButtonClick);
            // 
            // _generateButton
            // 
            resources.ApplyResources(this._generateButton, "_generateButton");
            this._generateButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(163)))), ((int)(((byte)(38)))), ((int)(((byte)(56)))));
            this._generateButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this._generateButton.FlatAppearance.BorderSize = 0;
            this._generateButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(176)))), ((int)(((byte)(23)))), ((int)(((byte)(46)))));
            this._generateButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(214)))), ((int)(((byte)(28)))), ((int)(((byte)(56)))));
            this._generateButton.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this._generateButton.Name = "_generateButton";
            this._toolTip.SetToolTip(this._generateButton, resources.GetString("_generateButton.ToolTip"));
            this._generateButton.UseVisualStyleBackColor = false;
            this._generateButton.EnabledChanged += new System.EventHandler(this.OnButtonEnabledChanged);
            this._generateButton.Click += new System.EventHandler(this.OnExportButtonClick);
            // 
            // _logo
            // 
            resources.ApplyResources(this._logo, "_logo");
            this._logo.Name = "_logo";
            this._logo.TabStop = false;
            // 
            // _sortButton
            // 
            resources.ApplyResources(this._sortButton, "_sortButton");
            this._sortButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(163)))), ((int)(((byte)(38)))), ((int)(((byte)(56)))));
            this._sortButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this._sortButton.FlatAppearance.BorderSize = 0;
            this._sortButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(176)))), ((int)(((byte)(23)))), ((int)(((byte)(46)))));
            this._sortButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(214)))), ((int)(((byte)(28)))), ((int)(((byte)(56)))));
            this._sortButton.ForeColor = System.Drawing.Color.White;
            this._sortButton.Name = "_sortButton";
            this._toolTip.SetToolTip(this._sortButton, resources.GetString("_sortButton.ToolTip"));
            this._sortButton.UseVisualStyleBackColor = false;
            this._sortButton.EnabledChanged += new System.EventHandler(this.OnButtonEnabledChanged);
            this._sortButton.Click += new System.EventHandler(this.OnSortButtonClick);
            // 
            // _importBackgroundWorker
            // 
            this._importBackgroundWorker.WorkerReportsProgress = true;
            this._importBackgroundWorker.WorkerSupportsCancellation = true;
            this._importBackgroundWorker.DoWork += new System.ComponentModel.DoWorkEventHandler(this.ImportBW_DoWork);
            this._importBackgroundWorker.ProgressChanged += new System.ComponentModel.ProgressChangedEventHandler(this.ImportBW_ProgressChanged);
            this._importBackgroundWorker.RunWorkerCompleted += new System.ComponentModel.RunWorkerCompletedEventHandler(this.ImportBW_RunWorkerCompleted);
            // 
            // _sortBackgroundWorker
            // 
            this._sortBackgroundWorker.WorkerReportsProgress = true;
            this._sortBackgroundWorker.WorkerSupportsCancellation = true;
            this._sortBackgroundWorker.DoWork += new System.ComponentModel.DoWorkEventHandler(this.SortBW_DoWork);
            this._sortBackgroundWorker.ProgressChanged += new System.ComponentModel.ProgressChangedEventHandler(this.SortBW_ProgressChanged);
            this._sortBackgroundWorker.RunWorkerCompleted += new System.ComponentModel.RunWorkerCompletedEventHandler(this.SortBW_RunWorkerCompleted);
            // 
            // _exportBackgroundWorker
            // 
            this._exportBackgroundWorker.WorkerReportsProgress = true;
            this._exportBackgroundWorker.WorkerSupportsCancellation = true;
            this._exportBackgroundWorker.DoWork += new System.ComponentModel.DoWorkEventHandler(this.ExportBW_DoWork);
            this._exportBackgroundWorker.ProgressChanged += new System.ComponentModel.ProgressChangedEventHandler(this.ExportBW_ProgressChanged);
            this._exportBackgroundWorker.RunWorkerCompleted += new System.ComponentModel.RunWorkerCompletedEventHandler(this.ExportBW_RunWorkerCompleted);
            // 
            // _playerbutton
            // 
            resources.ApplyResources(this._playerbutton, "_playerbutton");
            this._playerbutton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(163)))), ((int)(((byte)(38)))), ((int)(((byte)(56)))));
            this._playerbutton.Cursor = System.Windows.Forms.Cursors.Hand;
            this._playerbutton.FlatAppearance.BorderSize = 0;
            this._playerbutton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(176)))), ((int)(((byte)(23)))), ((int)(((byte)(46)))));
            this._playerbutton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(214)))), ((int)(((byte)(28)))), ((int)(((byte)(56)))));
            this._playerbutton.ForeColor = System.Drawing.Color.White;
            this._playerbutton.Name = "_playerbutton";
            this._toolTip.SetToolTip(this._playerbutton, resources.GetString("_playerbutton.ToolTip"));
            this._playerbutton.UseVisualStyleBackColor = false;
            this._playerbutton.EnabledChanged += new System.EventHandler(this.OnButtonEnabledChanged);
            this._playerbutton.Click += new System.EventHandler(this.OnPlayerButtonClick);
            // 
            // _skipButton
            // 
            resources.ApplyResources(this._skipButton, "_skipButton");
            this._skipButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(163)))), ((int)(((byte)(38)))), ((int)(((byte)(56)))));
            this._skipButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this._skipButton.FlatAppearance.BorderSize = 0;
            this._skipButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(176)))), ((int)(((byte)(23)))), ((int)(((byte)(46)))));
            this._skipButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(214)))), ((int)(((byte)(28)))), ((int)(((byte)(56)))));
            this._skipButton.ForeColor = System.Drawing.Color.White;
            this._skipButton.Name = "_skipButton";
            this._toolTip.SetToolTip(this._skipButton, resources.GetString("_skipButton.ToolTip"));
            this._skipButton.UseVisualStyleBackColor = false;
            this._skipButton.EnabledChanged += new System.EventHandler(this.OnButtonEnabledChanged);
            this._skipButton.Click += new System.EventHandler(this.OnSkipButtonClick);
            // 
            // _reloadButton
            // 
            resources.ApplyResources(this._reloadButton, "_reloadButton");
            this._reloadButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(163)))), ((int)(((byte)(38)))), ((int)(((byte)(56)))));
            this._reloadButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this._reloadButton.FlatAppearance.BorderSize = 0;
            this._reloadButton.FlatAppearance.MouseDownBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(176)))), ((int)(((byte)(23)))), ((int)(((byte)(46)))));
            this._reloadButton.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(214)))), ((int)(((byte)(28)))), ((int)(((byte)(56)))));
            this._reloadButton.ForeColor = System.Drawing.Color.White;
            this._reloadButton.Name = "_reloadButton";
            this._toolTip.SetToolTip(this._reloadButton, resources.GetString("_reloadButton.ToolTip"));
            this._reloadButton.UseVisualStyleBackColor = false;
            this._reloadButton.EnabledChanged += new System.EventHandler(this.OnButtonEnabledChanged);
            this._reloadButton.Click += new System.EventHandler(this.OnReloadButtonClick);
            // 
            // panel1
            // 
            resources.ApplyResources(this.panel1, "panel1");
            this.panel1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(53)))), ((int)(((byte)(57)))), ((int)(((byte)(57)))));
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add(this._reloadButton);
            this.panel1.Controls.Add(this._skipButton);
            this.panel1.Controls.Add(this._playerTrackBar);
            this.panel1.Controls.Add(this._playerbutton);
            this.panel1.Name = "panel1";
            // 
            // _playerTrackBar
            // 
            resources.ApplyResources(this._playerTrackBar, "_playerTrackBar");
            this._playerTrackBar.Maximum = 10000;
            this._playerTrackBar.Name = "_playerTrackBar";
            this._playerTrackBar.TickStyle = System.Windows.Forms.TickStyle.None;
            // 
            // _playerBackgroundWorker
            // 
            this._playerBackgroundWorker.WorkerReportsProgress = true;
            this._playerBackgroundWorker.WorkerSupportsCancellation = true;
            this._playerBackgroundWorker.DoWork += new System.ComponentModel.DoWorkEventHandler(this.PlayerBackgroundWorker_DoWork);
            this._playerBackgroundWorker.ProgressChanged += new System.ComponentModel.ProgressChangedEventHandler(this.PlayerBackgroundWorker_ProgressChanged);
            this._playerBackgroundWorker.RunWorkerCompleted += new System.ComponentModel.RunWorkerCompletedEventHandler(this.PlayerBackgroundWorker_RunWorkerCompleted);
            // 
            // _trackBarTimer
            // 
            this._trackBarTimer.Interval = 500;
            this._trackBarTimer.Tick += new System.EventHandler(this.TrackBarTimer_Tick);
            // 
            // _circularProgressBar
            // 
            this._circularProgressBar.AllowText = true;
            this._circularProgressBar.AutomaticFontCalculation = true;
            this._circularProgressBar.BackColor = System.Drawing.Color.Transparent;
            this._circularProgressBar.ForeColor = System.Drawing.Color.Transparent;
            resources.ApplyResources(this._circularProgressBar, "_circularProgressBar");
            this._circularProgressBar.MaxValue = 1000;
            this._circularProgressBar.MinValue = 0;
            this._circularProgressBar.Name = "_circularProgressBar";
            this._circularProgressBar.ProgressColor = System.Drawing.Color.Lime;
            this._circularProgressBar.Stroke = 10;
            this._circularProgressBar.Transparency = true;
            this._circularProgressBar.Value = 0;
            // 
            // MainForm
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(69)))), ((int)(((byte)(69)))));
            this.Controls.Add(this._circularProgressBar);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this._sortButton);
            this.Controls.Add(this._importButton);
            this.Controls.Add(this._musicListView);
            this.Controls.Add(this._statusStrip);
            this.Controls.Add(this._menuStrip);
            this.Controls.Add(this._generateButton);
            this.Controls.Add(this._logo);
            this.MainMenuStrip = this._menuStrip;
            this.Name = "MainForm";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.OnMainFormClosing);
            this._menuStrip.ResumeLayout(false);
            this._menuStrip.PerformLayout();
            this._statusStrip.ResumeLayout(false);
            this._statusStrip.PerformLayout();
            this._trackContextMenu.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this._logo)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this._playerTrackBar)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.bindingSource1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip _menuStrip;
        private System.Windows.Forms.ToolStripMenuItem _fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator;
        private System.Windows.Forms.ToolStripMenuItem _quitMenuItem;
        private System.Windows.Forms.ToolStripMenuItem _helpToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem _aboutMenuItem;
        private System.Windows.Forms.StatusStrip _statusStrip;
        private System.Windows.Forms.ListView _musicListView;
        private System.Windows.Forms.ColumnHeader collectionDuration;
        private System.Windows.Forms.ColumnHeader collectionBPM;
        private System.Windows.Forms.ColumnHeader collectionName;
        private System.Windows.Forms.Button _importButton;
        private System.Windows.Forms.Button _generateButton;
        private System.Windows.Forms.PictureBox _logo;
        private System.Windows.Forms.ColumnHeader collectionKey;
        private System.Windows.Forms.Button _sortButton;
        private System.Windows.Forms.ToolStripMenuItem _cancelMenuItem;
        private System.ComponentModel.BackgroundWorker _importBackgroundWorker;
        private System.ComponentModel.BackgroundWorker _sortBackgroundWorker;
        private System.Windows.Forms.ToolStripProgressBar _toolStripProgressBar;
        private System.Windows.Forms.ToolStripStatusLabel _toolStripCurrentDir;
        private System.Windows.Forms.ToolStripMenuItem _optionsToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem _dataBaseToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem _clearDBMenuItem;
        private System.ComponentModel.BackgroundWorker _exportBackgroundWorker;
        private System.Windows.Forms.ToolTip _toolTip;
        private System.Windows.Forms.ContextMenuStrip _trackContextMenu;
        private System.Windows.Forms.ToolStripMenuItem _deleteTrackToolStrip;
        private System.Windows.Forms.ToolStripMenuItem _selectAllToolStrip;
        private System.Windows.Forms.ToolStripMenuItem _aboutCharacteristicsToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.ComponentModel.BackgroundWorker _playerBackgroundWorker;
        private System.Windows.Forms.ToolStripMenuItem _importMenuItem;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button _playerbutton;
        private System.Windows.Forms.BindingSource bindingSource1;
        private System.Windows.Forms.TrackBar _playerTrackBar;
        private System.Windows.Forms.Timer _trackBarTimer;
        private System.Windows.Forms.Button _skipButton;
        private System.Windows.Forms.ToolStripMenuItem _stopMixToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem _exportMenuItem;
        private System.Windows.Forms.ToolStripMenuItem _generateMixMenuItem;
        private System.Windows.Forms.ToolStripMenuItem _exportTextFileMenuItem;
        private System.Windows.Forms.Button _reloadButton;
        private System.Windows.Forms.ToolStripMenuItem _chooseTempDirToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem _importDBMenuItem;
        private System.Windows.Forms.ToolStripMenuItem _exportDBMenuItem;
        private System.Windows.Forms.ToolStripMenuItem _lockTrackToolStrip;
        private System.Windows.Forms.ToolStripMenuItem preferencesToolStripMenuItem;
        private AltoControls.CircularPB _circularProgressBar;
    }
}
