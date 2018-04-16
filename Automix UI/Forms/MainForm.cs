// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using System;
using System.IO;
using System.ComponentModel;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;
using Automix_Data_Management.Model;
using Automix_UI.Drawing;
using Automix_UI.Properties;
using Automix_Data_Management.Storage;
using System.Resources;
using System.Reflection;
using System.Collections.Generic;
using System.Diagnostics;
using Automix_AI.Distances;
using Automix_Data_Management;

namespace Automix_UI.Forms
{
    public partial class MainForm : Form, IViewWithTrackCollection
    {
        public bool AnOperationRunning { get; private set; }

        private readonly Presenter _presenter;
        private readonly ListViewDrawer _lvDrawer;

        private bool _isRowDragInProgress;
        private bool _isDragImportInProgress;
        private bool _isPlayerPlaying;
        private bool _playerExists;

        private static readonly string DefaultExportPath = Path.GetTempPath() + "AutomixSoftware\\preview.mp3";
        private string _exportPath;

        private readonly ImageList _lockpadImageList;

        private enum InsertionModeType
        {
            Before,
            After
        };

        private int _insertionIndex;
        private InsertionModeType _insertionMode;

        private ParameterForm _parameterForm;

        public MainForm()
        {
            InitializeComponent();

            AnOperationRunning = false;
            _presenter = new Presenter(this);
            _lvDrawer = new ListViewDrawer(_musicListView, Color.LightGray);
            _exportPath = DefaultExportPath;

            var colorTable = new AutomixColorTable();
            _menuStrip.RenderMode = ToolStripRenderMode.Professional;
            _menuStrip.Renderer = new ToolStripProfessionalRenderer(colorTable);
            _trackContextMenu.RenderMode = ToolStripRenderMode.Professional;
            _trackContextMenu.Renderer = new ToolStripProfessionalRenderer(colorTable);

            _playerbutton.Image = new Bitmap(Resources.PlayIcon, 70, 70);
            _skipButton.Image = new Bitmap(Resources.SeekIcon, 70, 70);
            _reloadButton.Image = new Bitmap(Resources.ReloadIcon, 60, 60);

            _parameterForm = new ParameterForm(this);

            _lockpadImageList = new ImageList();
            _lockpadImageList.Images.Add(Image.FromFile(Path.GetDirectoryName(Process.GetCurrentProcess().MainModule.FileName) + @"..\..\..\Resources\UnlockedIcon.png"));
            _lockpadImageList.Images.Add(Image.FromFile(Path.GetDirectoryName(Process.GetCurrentProcess().MainModule.FileName) + @"..\..\..\Resources\LockedIcon.png"));

            _musicListView.StateImageList = _lockpadImageList;

            _cancelMenuItem.Enabled = false;
            _generateButton.Enabled = false;
            _sortButton.Enabled = false;
            _playerbutton.Enabled = false;
            _skipButton.Enabled = false;
            _reloadButton.Enabled = false;
            _exportMenuItem.Enabled = false;
            _toolStripProgressBar.Visible = false;

            _deleteTrackToolStrip.ShortcutKeys = Keys.Delete;
            _musicListView.ItemSelectionChanged += OnMusicListViewItemSelectionChanged;
        }


        public void Update(TrackCollection trackCollection)
        {
            _musicListView.Items.Clear();
            foreach (var track in trackCollection)
            {
                var lvitem = new ListViewItem(track.Name)
                {
                    UseItemStyleForSubItems = true
                };
                _musicListView.Items.Add(lvitem);
                if (track.IsFixed)
                {
                    lvitem.Checked = true;
                }
                lvitem.SubItems.Add(track.DisplayDuration());
                lvitem.SubItems.Add(track.Bpm.ToString());
                lvitem.SubItems.Add(track.Key);
            }
            _musicListView.Invalidate();
        }

        private void OnImportMenuItemClick(object sender, EventArgs e)
        {
            LoadTracks();
        }

        private void LoadTracks()
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

            OnWorkerStart();
            _importBackgroundWorker.RunWorkerAsync(dialog.FileNames);
        }

        private void OnWorkerStart()
        {
            AnOperationRunning = true;

            _cancelMenuItem.Enabled = true;
            _generateButton.Enabled = false;
            _importButton.Enabled = false;
            _sortButton.Enabled = false;
            _playerbutton.Enabled = false;
            _reloadButton.Enabled = false;
            _skipButton.Enabled = false;

            _exportMenuItem.Enabled = false;
            _importMenuItem.Enabled = false;
            _optionsToolStripMenuItem.Enabled = false;
            //_circularProgressBar1.Visible = true;

            _musicListView.AllowDrop = false;
        }


        private void OnWorkerStop()
        {
            AnOperationRunning = false;

            _cancelMenuItem.Enabled = false;
            _generateButton.Enabled = true;
            _importButton.Enabled = true;
            _sortButton.Enabled = true;
            _reloadButton.Enabled = true;
            _playerbutton.Enabled = true;
            _skipButton.Enabled = true;

            _exportMenuItem.Enabled = true;
            _importMenuItem.Enabled = true;
            _optionsToolStripMenuItem.Enabled = true;
            _circularProgressBar.Value = 0;


            _musicListView.AllowDrop = true;
        }

        private void OnGenerateMixMenuItemClick(object sender, EventArgs e) => ExportTrackList();

        private void ExportTrackList()
        {
            var dialog = new SaveFileDialog
            {
                Filter = TextResources.DialogFilters,
                FilterIndex = 1,
                FileName = "My mix",
                DefaultExt = "mp3",
                RestoreDirectory = true
            };

            if (dialog.ShowDialog() != DialogResult.OK)
            {
                return;
            }

            OnWorkerStart();
            _exportPath = dialog.FileName;
            _exportBackgroundWorker.RunWorkerAsync(dialog.FileName);
        }

        private void OnExportTextFileMenuItemClick(object sender, EventArgs e)
        {
            var dialog = new SaveFileDialog
            {
                Filter = TextResources.DialogFiltersText,
                FilterIndex = 1,
                FileName = "My mix",
                DefaultExt = "txt",
                RestoreDirectory = true
            };

            if (dialog.ShowDialog() != DialogResult.OK)
            {
                return;
            }

            _presenter.ExportPlaylistInTextFile(dialog.FileName);
        }

        private void OnCancelMenuItemClick(object sender, EventArgs e)
        {
            _importBackgroundWorker.CancelAsync();
            _sortBackgroundWorker.CancelAsync();
            _exportBackgroundWorker.CancelAsync();
            _playerBackgroundWorker.CancelAsync();
            StopPlayer();
        }

        private void StopPlayer()
        {
            if (!_playerExists)
            {
                return;
            }
            _trackBarTimer.Stop();
            _playerTrackBar.Value = 0;
            _presenter.StopMix();
            _isPlayerPlaying = false;
            _playerExists = false;
            _playerbutton.Image = new Bitmap(Resources.PlayIcon, 70, 70);
        }

        private void OnQuitMenuItemClick(object sender, EventArgs e)
        {
            var exitResult = true;

            if (_presenter.IsTrackCollectionFilled)
            {
                exitResult = ShowExitDialog();
            }
            if (exitResult)
            {
                ExitApplication();
            }
        }

        private void ExitApplication()
        {
            _importBackgroundWorker.CancelAsync();
            _sortBackgroundWorker.CancelAsync();
            _exportBackgroundWorker.CancelAsync();
            _playerBackgroundWorker.CancelAsync();
            StopPlayer();

            try
            {
                Directory.Delete(Path.GetTempPath() + "AutomixSoftware", true);
            }
            catch
            {
                //TODO log this
            }
            Application.Exit();
        }

        private static bool ShowExitDialog()
        {
            return MessageBox.Show(TextResources.ExitMessage, TextResources.ExitCaption,
                MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes;
        }

        private void OnClearDbMenuItemClick(object sender, EventArgs e) => _presenter.ClearDataBase();

        private void OnStopMixToolStripMenuItemClick(object sender, EventArgs e) => StopPlayer();

        private void OnAboutCharacteristicsMenuItemClick(object sender, EventArgs e) => new UserDocForm().ShowDialog();

        private void OnAboutMenuItemClick(object sender, EventArgs e) => new AboutForm().ShowDialog();

        private void OnPreferencesToolStripMenuItemClick(object sender, EventArgs e) => _parameterForm.ShowDialog();

        private void MusicListView_DrawColumnHeader(object sender, DrawListViewColumnHeaderEventArgs e) => _lvDrawer.DrawColumnHeader(e);

        private void MusicListView_DrawItem(object sender, DrawListViewItemEventArgs e) => _lvDrawer.DrawItem(e);

        private void MusicListView_DrawSubItem(object sender, DrawListViewSubItemEventArgs e) => _lvDrawer.DrawSubItem(e);

        private void MusicListView_ItemDrag(object sender, ItemDragEventArgs e)
        {
            if (_musicListView.Items.Count <= 1)
            {
                return;
            }
            _isRowDragInProgress = true;
            DoDragDrop(e.Item, DragDropEffects.Move);
        }

        private void MusicListView_DragDrop(object sender, DragEventArgs e)
        {
            if (_isDragImportInProgress)
            {
                try
                {
                    var fileNames = (string[])e.Data.GetData(DataFormats.FileDrop);
                    OnWorkerStart();
                    _importBackgroundWorker.RunWorkerAsync(fileNames);
                }
                finally
                {
                    _isDragImportInProgress = false;
                }
            }
            else if (_isRowDragInProgress)
            {
                try
                {
                    var dropItem = _insertionIndex != -1 ? _musicListView.Items[_insertionIndex] : null;
                    if (dropItem == null)
                    {
                        return;
                    }

                    var dragItem = (ListViewItem)e.Data.GetData(typeof(ListViewItem));
                    var dropIndex = dropItem.Index;

                    if (dragItem.Index < dropIndex)
                    {
                        dropIndex--;
                    }
                    if (_insertionMode == InsertionModeType.After && dragItem.Index < _musicListView.Items.Count - 1)
                    {
                        dropIndex++;
                    }
                    if (dropIndex != dragItem.Index)
                    {
                        _musicListView.PointToClient(new Point(e.X, e.Y));
                        _musicListView.Items.Remove(dragItem);
                        _musicListView.Items.Insert(dropIndex, dragItem);
                        _presenter.MoveTrack(dropIndex, dragItem.Text);
                    }
                }
                finally
                {
                    _insertionIndex = -1;
                    _isRowDragInProgress = false;
                    _musicListView.Invalidate();
                }
            }
        }

        private void MusicListView_DragEnter(object sender, DragEventArgs e)
        {
            if (!e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                return;
            }
            e.Effect = DragDropEffects.Copy;
            _isDragImportInProgress = true;
        }

        private void MusicListView_DragOver(object sender, DragEventArgs e)
        {
            if (!_isRowDragInProgress)
            {
                return;
            }

            int insertionIndex;
            InsertionModeType insertionMode;

            var clientPoint = _musicListView.PointToClient(new Point(e.X, e.Y));
            var dropItem = _musicListView.GetItemAt(0, Math.Min(clientPoint.Y, _musicListView.Items[_musicListView.Items.Count - 1].GetBounds(ItemBoundsPortion.Entire).Bottom - 1));

            if (dropItem != null)
            {
                var bounds = dropItem.GetBounds(ItemBoundsPortion.Entire);
                insertionIndex = dropItem.Index;
                insertionMode = clientPoint.Y < bounds.Top + (bounds.Height / 2) ? InsertionModeType.Before : InsertionModeType.After;

                e.Effect = DragDropEffects.Move;
                DrawInsertionLine();
            }
            else
            {
                insertionIndex = -1;
                insertionMode = _insertionMode;
                e.Effect = DragDropEffects.None;
            }

            if (insertionIndex == _insertionIndex && insertionMode == _insertionMode) return;
            _insertionMode = insertionMode;
            _insertionIndex = insertionIndex;
            _musicListView.Invalidate();
        }

        private void DrawInsertionLine()
        {

            if (_insertionIndex < 0 || _insertionIndex >= _musicListView.Items.Count)
            {
                return;
            }

            var bounds = _musicListView.Items[_insertionIndex].GetBounds(ItemBoundsPortion.Entire);
            const int x = 0;
            var y = _insertionMode == InsertionModeType.Before ? bounds.Top : bounds.Bottom;
            var width = Math.Min(bounds.Width - bounds.Left, ClientSize.Width);

            _lvDrawer.DrawInsertionLine(x, y, width);
        }

        private void OnTrackContextMenuOpening(object sender, CancelEventArgs e)
        {
            ToogleToolStripItems();
        }

        private void OnMusicListViewItemSelectionChanged(object sender, ListViewItemSelectionChangedEventArgs listViewItemSelectionChangedEventArgs)
        {
            ToogleToolStripItems();
        }

        private void ToogleToolStripItems()
        {
            if (!AnOperationRunning && _musicListView.SelectedItems.Count != 0)
            {
                _deleteTrackToolStrip.Enabled = true;
                _lockTrackToolStrip.Enabled = true;
            }
            else
            {
                _deleteTrackToolStrip.Enabled = false;
                _lockTrackToolStrip.Enabled = false;
            }
        }

        private void OnDeleteTrackToolStripClick(object sender, EventArgs e)
        {
            var selection = (from ListViewItem item in _musicListView.SelectedItems select item.Text).ToList();
            _presenter.RemoveTracks(selection);
        }

        private void OnSelectAllMenuItemClick(object sender, EventArgs e)
        {
            foreach (ListViewItem item in _musicListView.Items)
            {
                item.Selected = true;
            }
        }

        private void OnLockTrackToolStripClick(object sender, EventArgs e)
        {
            var selection = (from ListViewItem item in _musicListView.SelectedItems select item.Text).ToList();
            _presenter.LockTracks(selection);
            foreach (ListViewItem lockedItem in _musicListView.SelectedItems)
            {
                lockedItem.Checked = !lockedItem.Checked;
                lockedItem.ImageIndex = (_musicListView.Items[0].ImageIndex + 1) % 2;
            }
            _musicListView.Invalidate();
        }

        private void OnButtonEnabledChanged(object sender, EventArgs e)
        {
            var button = (Button)sender;
            button.BackColor = button.Enabled ? AutomixColorTable.MainColor : AutomixColorTable.DisabledColor;
        }

        private void OnImportButtonClick(object sender, EventArgs e) => LoadTracks();

        private void OnExportButtonClick(object sender, EventArgs e)
        {
            ExportTrackList();
        }

        private void OnSortButtonClick(object sender, EventArgs e)
        {
            UpdateLockedTracks();
            SortTrackList();
        }

        private void SortTrackList()
        {
            OnWorkerStart();
            _sortBackgroundWorker.RunWorkerAsync();
        }

        private void UpdateLockedTracks()
        {
            List<String> checkedTracks = new List<String>();
            List<String> uncheckedTracks = new List<String>();

            foreach (ListViewItem item in _musicListView.Items)
            {
                if (item.Checked)
                {
                    checkedTracks.Add(item.Text);
                }
                else
                {
                    uncheckedTracks.Add(item.Text);
                }
            }

            _presenter.LockTracks(checkedTracks);
            _presenter.UnlockTracks(uncheckedTracks);
        }
        private void ImportBW_DoWork(object sender, DoWorkEventArgs e)
        {
            var backgroundWorker = (BackgroundWorker)sender;
            var fileNames = (string[])e.Argument;
            e.Result = _presenter.LoadTracks(backgroundWorker, fileNames);

            if (backgroundWorker.CancellationPending)
            {
                e.Cancel = true;
            }
        }

        private void ImportBW_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            _circularProgressBar.Value = e.ProgressPercentage;
            _presenter.Notify();
        }

        private void ImportBW_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            if (e.Cancelled)
            {
                _presenter.ClearMusicList();

                ShowCancelDialog();
            }
            else if (e.Error != null)
            {
                ShowErrorDialog(e.Error.Message);
            }
            else
            {
                _exportPath = DefaultExportPath;
                _presenter.Notify();
            }
            OnWorkerStop();
            StopPlayer();

        }

        private static void ShowErrorDialog(string errorMessage)
        {
            var msg = string.Format(TextResources.ErrorMessage, errorMessage);
            MessageBox.Show(msg, TextResources.ErrorCaption, MessageBoxButtons.OK, MessageBoxIcon.Error);
        }

        private static void ShowCancelDialog()
        {
            MessageBox.Show(TextResources.CancelMessage, TextResources.CancelCaption, MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void SortBW_DoWork(object sender, DoWorkEventArgs e)
        {
            var backgroundWorker = (BackgroundWorker)sender;
            e.Result = _presenter.SortTrackCollection(backgroundWorker);

            if (backgroundWorker.CancellationPending)
            {
                _presenter.ClearMusicList();
                e.Cancel = true;
            }
        }

        private void SortBW_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            _circularProgressBar.Value = e.ProgressPercentage;
        }

        private void SortBW_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            if (e.Cancelled)
            {
                ShowCancelDialog();
            }
            else if (e.Error != null)
            {
                ShowErrorDialog(e.Error.Message);
            }
            else
            {
                _exportPath = DefaultExportPath;
                _presenter.Notify();
            }
            OnWorkerStop();
            StopPlayer();
        }

        private void ExportBW_DoWork(object sender, DoWorkEventArgs e)
        {
            var backgroundWorker = (BackgroundWorker)sender;
            var fileName = (string)e.Argument;
            _presenter.ExportTrackList(backgroundWorker, fileName);

            if (backgroundWorker.CancellationPending)
            {
                e.Cancel = true;
            }
        }

        private void ExportBW_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            _circularProgressBar.Value = e.ProgressPercentage;
        }

        private void ExportBW_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            if (e.Cancelled)
            {
                _exportPath = DefaultExportPath;
                ShowCancelDialog();
            }
            else if (e.Error != null)
            {
                ShowErrorDialog(e.Error.Message);
            }
            OnWorkerStop();
        }

        private void OnPlayerButtonClick(object sender, EventArgs e)
        {
            OnWorkerStart();
            _playerbutton.Enabled = true;

            _playerbutton.Image = _isPlayerPlaying ? new Bitmap(Resources.PlayIcon, 70, 70) : new Bitmap(Resources.PauseIcon, 70, 70);
            _playerBackgroundWorker.RunWorkerAsync();
        }

        private void OnSkipButtonClick(object sender, EventArgs e)
        {
            if (_playerExists)
            {
                _presenter.Seek(30.0);
            }
        }

        private void OnReloadButtonClick(object sender, EventArgs e)
        {
            StopPlayer();
        }

        private void PlayerBackgroundWorker_DoWork(object sender, DoWorkEventArgs e)
        {
            var backgroundWorker = (BackgroundWorker)sender;
            if (!_isPlayerPlaying)
            {
                try
                {
                    if (_exportPath.Equals(DefaultExportPath))
                    {
                        _presenter.ExportTrackList(backgroundWorker, _exportPath);
                    }
                    _presenter.PlayMix(_exportPath);
                }
                catch (IOException)
                {
                    _presenter.ResumeMix();
                }
                _isPlayerPlaying = true;
                _playerExists = true;
            }
            else
            {
                _presenter.PauseMix();
                _isPlayerPlaying = false;
            }
            if (backgroundWorker.CancellationPending)
            {
                e.Cancel = true;
            }
        }

        private void PlayerBackgroundWorker_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            _circularProgressBar.Value = e.ProgressPercentage;
        }

        private void PlayerBackgroundWorker_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            if (e.Cancelled)
            {
                ShowCancelDialog();
            }
            else if (e.Error != null)
            {
                ShowErrorDialog(e.Error.Message);
            }
            else
            {
                if (_isPlayerPlaying)
                {
                    _trackBarTimer.Start();
                }
                else
                {
                    _trackBarTimer.Stop();
                }
            }
            OnWorkerStop();
        }

        private void TrackBarTimer_Tick(object sender, EventArgs e)
        {
            var normalize = 10000 * _presenter.GetPlayerPosition() / _presenter.GetPlayerLength();
            _playerTrackBar.Value = (int)Math.Min(normalize, 10000);
        }

        private void OnMainFormClosing(object sender, FormClosingEventArgs e)
        {
            if (e.CloseReason == CloseReason.UserClosing)
            {
                var exitResult = true;

                if (_presenter.IsTrackCollectionFilled)
                {
                    exitResult = ShowExitDialog();
                }
                if (exitResult)
                {
                    ExitApplication();
                }
                else
                {
                    e.Cancel = true;
                }
            }
            else
            {
                ExitApplication();
            }
        }

        private void OnChooseTempDirButtonClick(object sender, EventArgs e)
        {
            var dialog = new FolderBrowserDialog
            {
                ShowNewFolderButton = true
            };

            if (dialog.ShowDialog() != DialogResult.OK)
            {
                return;
            }

            new SettingsManager().SetSetting(SettingsManager.SettingTypes.TempDir, dialog.SelectedPath);

            ResourceManager rm = new ResourceManager("Automix_UI.Properties.TextResources", Assembly.GetExecutingAssembly());
            string msg = rm.GetString("ChooseTempDir");
            MessageBox.Show(msg);
        }

        private void OnChooseImportDBMenuItemClick(object sender, EventArgs e)
        {
            var dialog = new OpenFileDialog
            {
                Filter = "db files (*.db)|*.db|All files (*.*)|*.*",
                FilterIndex = 1,
                Multiselect = false
            };

            if (dialog.ShowDialog() != DialogResult.OK)
            {
                return;
            }

            var dataBase = new DataBase();
            dataBase.ImportDataBase(dialog.FileName);

            ResourceManager rm = new ResourceManager("Automix_UI.Properties.TextResources", Assembly.GetExecutingAssembly());
            string msg = rm.GetString("ImportDbMessagePart1") + dialog.SafeFileName + rm.GetString("ImportDbMessagePart2");
            string legend = rm.GetString("ImportDbLegend");
            MessageBox.Show(msg, legend);
        }

        private void OnChooseExportDBMenuItemClick(object sender, EventArgs e)
        {
            var dialog = new SaveFileDialog
            {
                Filter = "db files (*.db)|*.db|All files (*.*)|*.*",
                FilterIndex = 1
            };

            if (dialog.ShowDialog() != DialogResult.OK)
            {
                return;
            }

            var dataBase = new DataBase();
            dataBase.ExportDataBase(dialog.FileName);

            ResourceManager rm = new ResourceManager("Automix_UI.Properties.TextResources", Assembly.GetExecutingAssembly());
            string msg = rm.GetString("ExportDbMessage");
            string legend = rm.GetString("ExportDbLegend");
            MessageBox.Show(msg, legend);
        }

        public void UpdateSortProfile(IProfileDistance profileChosen)
        {
            _presenter.UpdateSortAlgorithm(profileChosen);
        }


    }
}


