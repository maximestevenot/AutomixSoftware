using System;
using System.Resources;
using System.IO;
using System.ComponentModel;
using System.Drawing;
using System.Reflection;
using System.Windows.Forms;
using Automix_Data_Management.Model;
using Automix_UI.Properties;

namespace Automix_UI.Forms
{
    public partial class MainForm : Form, IViewWithTrackCollection
    {
        public bool AnOperationRunning { get; }

        private Presenter _presenter;
        private ResourceManager _resourceManager;

        private bool IsRowDragInProgress;
        private bool IsDragImportInProgress;
        private bool _isPlayerPlaying;
        private bool _playerExists;

        private static readonly string DefaultExportPath = Path.GetTempPath() + "AutomixSoftware\\preview.mp3";
        private string _exportPath;

        private enum InsertionModeType
        {
            Before,
            After
        };

        private int _insertionIndex;
        private InsertionModeType _insertionMode;
        private Color _insertionLineColor;

        public MainForm()
        {
            InitializeComponent();

            AnOperationRunning = false;
            _presenter = new Presenter(this);
            _resourceManager = new ResourceManager("Automix_UI.Ressources.TextResources", Assembly.GetExecutingAssembly());
            _exportPath = DefaultExportPath;

            var colorTable = new AutomixColorTable();
            _menuStrip.RenderMode = ToolStripRenderMode.Professional;
            _menuStrip.Renderer = new ToolStripProfessionalRenderer(colorTable);
            _trackContextMenu.RenderMode = ToolStripRenderMode.Professional;
            _trackContextMenu.Renderer = new ToolStripProfessionalRenderer(colorTable);
            _insertionLineColor = Color.LightGray;

            _playerbutton.Image = new Bitmap(Resources.PlayIcon, 70, 70);
            _skipButton.Image = new Bitmap(Resources.SeekIcon, 70, 70);
            _reloadButton.Image = new Bitmap(Resources.ReloadIcon, 60, 60);
            _cancelMenuItem.Enabled = false;
            _generateButton.Enabled = false;
            _sortButton.Enabled = false;
            _playerbutton.Enabled = false;
            _skipButton.Enabled = false;
            _reloadButton.Enabled = false;
            _exportMenuItem.Enabled = false;
            _toolStripProgressBar.Visible = false;
        }

        public void Update(TrackCollection trackCollection)
        {
            _musicListView.Items.Clear();
            foreach (var track in trackCollection)
            {
                var lvitem = new ListViewItem(track.Name);
                _musicListView.Items.Add(lvitem);
                lvitem.SubItems.Add(track.DisplayDuration());
                lvitem.SubItems.Add(track.Bpm.ToString());
                lvitem.SubItems.Add(track.Key);
            }
            _musicListView.Invalidate();
        }

        private void OnImportMenuItemClick(object sender, EventArgs e)
        {
            LoadTracks(sender, e);
        }

        private void LoadTracks(object sender, EventArgs eventArgs)
        {
            var dialog = new OpenFileDialog
            {
                Filter = TextResources.DialogFilters,
                FilterIndex = 1,
                Multiselect = true
            };

            if (dialog.ShowDialog() != DialogResult.OK)
            {
                return;
            }

            //OnWorkerStart();
            _importBackgroundWorker.RunWorkerAsync(dialog.FileNames);
        }

        private void OnGenerateMixMenuItemClick(object sender, EventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void OnExportTextFileMenuItemClick(object sender, EventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void OnCancelMenuItemClick(object sender, EventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void OnQuitMenuItemClick(object sender, EventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void OnClearDBMenuItemClick(object sender, EventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void OnStopMixToolStripMenuItemClick(object sender, EventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void OnAboutCharacteristicsMenuItemClick(object sender, EventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void OnAboutMenuItemClick(object sender, EventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void MusicListView_DrawColumnHeader(object sender, DrawListViewColumnHeaderEventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void MusicListView_DrawItem(object sender, DrawListViewItemEventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void MusicListView_DrawSubItem(object sender, DrawListViewSubItemEventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void MusicListView_ItemDrag(object sender, ItemDragEventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void MusicListView_DragDrop(object sender, DragEventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void MusicListView_DragEnter(object sender, DragEventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void MusicListView_DragOver(object sender, DragEventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void OnTrackContextMenuOpening(object sender, CancelEventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void OnDeleteTrackToolStripClick(object sender, EventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void OnSelectAllMenuItemClick(object sender, EventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void OnButtonEnabledChanged(object sender, EventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void OnImportButtonClick(object sender, EventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void OnExportButtonClick(object sender, EventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void OnSortButtonClick(object sender, EventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void ImportBW_DoWork(object sender, DoWorkEventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void ImportBW_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void ImportBW_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void SortBW_DoWork(object sender, DoWorkEventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void SortBW_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void SortBW_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void ExportBW_DoWork(object sender, DoWorkEventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void ExportBW_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void ExportBW_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void OnPlayerButtonClick(object sender, EventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void OnSkipButtonClick(object sender, EventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void OnReloadButtonClick(object sender, EventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void PlayerBackgroundWorker_DoWork(object sender, DoWorkEventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void PlayerBackgroundWorker_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void PlayerBackgroundWorker_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void TrackBarTimer_Tick(object sender, EventArgs e)
        {
            //throw new NotImplementedException();
        }

        private void OnMainFormClosing(object sender, FormClosingEventArgs e)
        {
            //throw new NotImplementedException();
        }

        private Bitmap LoadIcon(string img)
        {
            var myAssembly = Assembly.GetExecutingAssembly();
            var myStream = myAssembly.GetManifestResourceStream(img);
            return new Bitmap(myStream);
        }
    }
}
