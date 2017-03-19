// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "MainForm.h"
#include "UserDocForm.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Threading;
using namespace System::Globalization;
using namespace System::Resources;
using namespace System::Reflection;
using namespace AutoMixDataManagement;

namespace AutoMixUI {

	MainForm::MainForm(void)
	{
		InitializeComponent();

		_presenter = gcnew Presenter(this);
		_resourceManager = gcnew Resources::ResourceManager(L"AutoMixUI.TextResources", Assembly::GetExecutingAssembly());

		_menuStrip->RenderMode = ToolStripRenderMode::Professional;
		_menuStrip->Renderer = gcnew ToolStripProfessionalRenderer(gcnew AutoMixColorTable());
		_trackContextMenu->RenderMode = ToolStripRenderMode::Professional;
		_trackContextMenu->Renderer = gcnew ToolStripProfessionalRenderer(gcnew AutoMixColorTable());
		_insertionLineColor = Color::LightGray;

		_playerbutton->Image = gcnew Bitmap(PlayIcon, 60, 60);
		_skipButton->Image = gcnew Bitmap(SeekIcon, 60, 60);
		_cancelMenuItem->Enabled = false;
		_generateButton->Enabled = false;
		_sortButton->Enabled = false;
		_playerbutton->Enabled = false;
		_toolStripProgressBar->Visible = false;

		AnOperationRunning = false;
	}

	MainForm::~MainForm()
	{
		if (components)
		{
			delete components;
		}
	}

	Bitmap^ MainForm::PlayIcon::get()
	{
		if (!_playIcon)
		{
			Assembly^ myAssembly = Assembly::GetExecutingAssembly();
			Stream^ myStream = myAssembly->GetManifestResourceStream("play_icon.bmp");
			_playIcon = gcnew Bitmap(myStream);
		}
		return _playIcon;
	}

	Bitmap^ MainForm::PauseIcon::get()
	{
		if (!_pauseIcon)
		{
			Assembly^ myAssembly = Assembly::GetExecutingAssembly();
			Stream^ imageStream = myAssembly->GetManifestResourceStream("pause_icon.bmp");
			_pauseIcon = gcnew Bitmap(imageStream);
		}
		return _pauseIcon;
	}

	Bitmap^ MainForm::SeekIcon::get()
	{
		if (!_seekIcon)
		{
			Assembly^ myAssembly = Assembly::GetExecutingAssembly();
			Stream^ imageStream = myAssembly->GetManifestResourceStream("seek_icon.bmp");
			_seekIcon = gcnew Bitmap(imageStream);
		}
		return _seekIcon;
	}

	System::Void MainForm::update(TrackCollection^ collection)
	{
		_musicListView->Items->Clear();

		for each (auto track in collection)
		{
			ListViewItem^ lvitem = gcnew ListViewItem(track->Name);
			_musicListView->Items->Add(lvitem);

			lvitem->SubItems->Add(track->displayDuration());
			lvitem->SubItems->Add(track->BPM.ToString());
			lvitem->SubItems->Add(track->Key);
		}
		_musicListView->Invalidate();
	}

	System::Void MainForm::onCancelMenuItemClick(System::Object ^ sender, System::EventArgs ^ e)
	{
		_importBackgroundWorker->CancelAsync();
		_sortBackgroundWorker->CancelAsync();
		_exportBackgroundWorker->CancelAsync();
		_playerBackgroundWorker->CancelAsync();
		stopPlayer();
	}

	System::Void MainForm::onQuitMenuItemClick(System::Object ^ sender, System::EventArgs ^ e)
	{
		if (showExitDialog())
		{
			exitApplication();
		}
	}

	System::Void MainForm::onMainFormClosing(System::Object ^ sender, System::Windows::Forms::FormClosingEventArgs ^ e)
	{
		if (e->CloseReason == CloseReason::UserClosing)
		{
			if (showExitDialog())
			{
				exitApplication();
			}
			else
			{
				e->Cancel = true;
			}
		}
		else
		{
			exitApplication();
		}
	}

	System::Void MainForm::onImportMenuItemClick(System::Object^  sender, System::EventArgs^  e)
	{
		loadTracks(sender, e);
	}

	System::Void MainForm::onImportButtonClick(System::Object^  sender, System::EventArgs^  e)
	{
		loadTracks(sender, e);
	}

	System::Void MainForm::onExportButtonClick(System::Object^  sender, System::EventArgs^  e)
	{
		exportTrackList(sender, e);
	}

	System::Void MainForm::onSortButtonClick(System::Object^ sender, System::EventArgs^ e)
	{
		sortTrackList(sender, e);
	}

	System::Void MainForm::onAboutMenuItemClick(System::Object ^ sender, System::EventArgs ^ e)
	{
		String^ msg = "AutoMix Software Beta 3.0\n\n";
		msg += "Copyright © 2016-2017 LesProjecteurs - All Rights Reserved\n\n";
		msg += "Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT,\nLouis CARLIER, Pierre GABON";

		String^ caption = _resourceManager->GetString("about_caption");
		MessageBox::Show(msg, caption, MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	System::Void AutoMixUI::MainForm::onAboutCharacteristicsMenuItemClick(System::Object ^ sender, System::EventArgs ^ e)
	{
		UserDocForm().ShowDialog();
	}

	System::Void MainForm::onClearDBMenuItemClick(System::Object ^ sender, System::EventArgs ^ e)
	{
		_presenter->clearDataBase();
	}

	System::Void MainForm::importBW_DoWork(System::Object ^ sender, System::ComponentModel::DoWorkEventArgs ^ e)
	{
		BackgroundWorker^ bw = (BackgroundWorker^)sender;
		array<String^>^ fileNames = (array<String^>^) e->Argument;
		e->Result = _presenter->loadTracks(bw, fileNames);

		if (bw->CancellationPending)
		{
			e->Cancel = true;
		}
	}

	System::Void MainForm::importBW_ProgressChanged(System::Object ^ sender, System::ComponentModel::ProgressChangedEventArgs ^ e)
	{
		_toolStripProgressBar->Value = e->ProgressPercentage;
		_presenter->notify();
	}

	System::Void MainForm::importBW_RunWorkerCompleted(System::Object ^ sender, System::ComponentModel::RunWorkerCompletedEventArgs ^ e)
	{
		if (e->Cancelled)
		{
			showCancelDialog();
		}
		else if (e->Error != nullptr)
		{
			showErrorDialog(e->Error->Message);
		}

		onWorkerStop();
		stopPlayer();
		_exportPath = _defaultExportPath;
		_presenter->notify();
	}

	System::Void MainForm::sortBW_DoWork(System::Object ^ sender, System::ComponentModel::DoWorkEventArgs ^ e)
	{
		BackgroundWorker^ bw = (BackgroundWorker^)sender;
		e->Result = _presenter->sortTrackCollectionWithGeneticAlgorithm(bw);
		if (bw->CancellationPending)
		{
			e->Cancel = true;
		}
	}

	System::Void MainForm::sortBW_ProgressChanged(System::Object ^ sender, System::ComponentModel::ProgressChangedEventArgs ^ e)
	{
		_toolStripProgressBar->Value = e->ProgressPercentage;
	}

	System::Void MainForm::sortBW_RunWorkerCompleted(System::Object ^ sender, System::ComponentModel::RunWorkerCompletedEventArgs ^ e)
	{
		if (e->Cancelled)
		{
			showCancelDialog();
		}
		else if (e->Error != nullptr)
		{
			showErrorDialog(e->Error->Message);
		}
		else
		{
			_exportPath = _defaultExportPath;
			_presenter->notify();
		}
		onWorkerStop();
		stopPlayer();
	}

	System::Void MainForm::exportBW_DoWork(System::Object ^ sender, System::ComponentModel::DoWorkEventArgs ^ e)
	{
		BackgroundWorker^ bw = (BackgroundWorker^)sender;
		System::String^ fileName = (System::String^) e->Argument;
		_presenter->exportTrackList(bw, fileName);
		if (bw->CancellationPending)
		{
			e->Cancel = true;
		}
	}

	System::Void MainForm::exportBW_ProgressChanged(System::Object ^ sender, System::ComponentModel::ProgressChangedEventArgs ^ e)
	{
		_toolStripProgressBar->Value = e->ProgressPercentage;
	}

	System::Void MainForm::exportBW_RunWorkerCompleted(System::Object ^ sender, System::ComponentModel::RunWorkerCompletedEventArgs ^ e)
	{
		if (e->Cancelled)
		{
			_exportPath = _defaultExportPath;
			showCancelDialog();
		}
		else if (e->Error != nullptr)
		{
			showErrorDialog(e->Error->Message);
		}
		onWorkerStop();
	}

	System::Void MainForm::onDeleteTrackToolStripClick(System::Object ^ sender, System::EventArgs ^ e)
	{
		Generic::List<String^>^ selection = gcnew Generic::List<String^>();

		for each (ListViewItem^ lvitem in _musicListView->SelectedItems)
		{
			selection->Add(lvitem->Text);
		}
		_presenter->removeTracks(selection);
	}

	System::Void MainForm::onTrackContextMenuOpening(System::Object ^ sender, System::ComponentModel::CancelEventArgs ^ e)
	{
		if (!AnOperationRunning && _musicListView->SelectedItems->Count != 0)
		{
			_deleteTrackToolStrip->Enabled = true;
		}
		else
		{
			_deleteTrackToolStrip->Enabled = false;
		}
	}

	System::Void MainForm::onSelectAllMenuItemClick(System::Object ^ sender, System::EventArgs ^ e)
	{
		for each(ListViewItem^ lvitem in _musicListView->Items)
		{
			lvitem->Selected = true;
		}
	}

	System::Void MainForm::musicListView_DragEnter(System::Object ^ sender, System::Windows::Forms::DragEventArgs ^ e)
	{
		if (e->Data->GetDataPresent(DataFormats::FileDrop))
		{
			e->Effect = DragDropEffects::Copy;
			IsDragImportInProgress = true;
		}
	}

	System::Void MainForm::musicListView_DragDrop(System::Object ^ sender, System::Windows::Forms::DragEventArgs ^ drgevent)
	{
		if (IsDragImportInProgress)
		{
			try
			{
				array<String^>^ fileNames = (array<String^>^) drgevent->Data->GetData(DataFormats::FileDrop);
				onWorkerStart();
				_importBackgroundWorker->RunWorkerAsync(fileNames);
			}
			finally
			{
				IsDragImportInProgress = false;
			}
		}
		else if (IsRowDragInProgress)
		{
			try
			{
				ListViewItem^ dropItem = _insertionIndex != -1 ? _musicListView->Items[_insertionIndex] : nullptr;
				if (dropItem != nullptr)
				{
					ListViewItem^ dragItem = (ListViewItem^)drgevent->Data->GetData(ListViewItem::typeid);
					int dropIndex = dropItem->Index;

					if (dragItem->Index < dropIndex)
					{
						dropIndex--;
					}
					if (_insertionMode == InsertionModeType::After && dragItem->Index < _musicListView->Items->Count - 1)
					{
						dropIndex++;
					}
					if (dropIndex != dragItem->Index)
					{
						Point clientPoint = _musicListView->PointToClient(Point(drgevent->X, drgevent->Y));

						_musicListView->Items->Remove(dragItem);
						_musicListView->Items->Insert(dropIndex, dragItem);
						_presenter->moveTrack(dropIndex, dragItem->Text);
					}
				}
			}
			finally
			{
				_insertionIndex = -1;
				IsRowDragInProgress = false;
				_musicListView->Invalidate();
			}
		}
	}

	System::Void MainForm::musicListView_ItemDrag(System::Object ^ sender, System::Windows::Forms::ItemDragEventArgs ^ e)
	{
		if (_musicListView->Items->Count > 1)
		{
			IsRowDragInProgress = true;
			DoDragDrop(e->Item, DragDropEffects::Move);
		}
	}

	System::Void MainForm::musicListView_DragOver(System::Object ^ sender, System::Windows::Forms::DragEventArgs ^ drgevent)
	{

		if (IsRowDragInProgress)
		{
			int insertionIndex;
			InsertionModeType insertionMode;

			Point clientPoint = _musicListView->PointToClient(Point(drgevent->X, drgevent->Y));

			ListViewItem^ dropItem = _musicListView->GetItemAt(0, Math::Min(clientPoint.Y, _musicListView->Items[_musicListView->Items->Count - 1]->GetBounds(ItemBoundsPortion::Entire).Bottom - 1));
			if (dropItem != nullptr)
			{
				Rectangle bounds = dropItem->GetBounds(ItemBoundsPortion::Entire);
				insertionIndex = dropItem->Index;
				insertionMode = clientPoint.Y < bounds.Top + (bounds.Height / 2) ? InsertionModeType::Before : InsertionModeType::After;

				drgevent->Effect = DragDropEffects::Move;
				drawInsertionLine();
			}

			else
			{
				insertionIndex = -1;
				insertionMode = this->_insertionMode;
				drgevent->Effect = DragDropEffects::None;
			}

			if (insertionIndex != this->_insertionIndex || insertionMode != this->_insertionMode)
			{
				_insertionMode = insertionMode;
				_insertionIndex = insertionIndex;
				_musicListView->Invalidate();
			}
		}
	}

	System::Void MainForm::onPlayerButtonClick(System::Object ^ sender, System::EventArgs ^ e)
	{
		onWorkerStart();
		_playerbutton->Enabled = true;

		if (!_isPlayerPlaying)
		{
			_playerbutton->Image = gcnew Bitmap(PauseIcon, 60, 60);
		}
		else
		{
			_playerbutton->Image = gcnew Bitmap(PlayIcon, 60, 60);
		}
		_playerBackgroundWorker->RunWorkerAsync();
	}

	System::Void MainForm::playerBackgroundWorker_DoWork(System::Object ^ sender, System::ComponentModel::DoWorkEventArgs ^ e)
	{
		BackgroundWorker^ bw = (BackgroundWorker^)sender;
		if (!_isPlayerPlaying)
		{
			try
			{
				if (_exportPath->Equals(_defaultExportPath))
				{
					_presenter->exportTrackList(bw, _exportPath);
				}
				_presenter->playMix(_exportPath);
			}
			catch (System::IO::IOException^)
			{
				_presenter->resumeMix();
			}
			_isPlayerPlaying = true;
			_playerExists = true;
		}
		else
		{
			_presenter->pauseMix();
			_isPlayerPlaying = false;
		}
		if (bw->CancellationPending)
		{
			e->Cancel = true;
		}
	}

	System::Void MainForm::playerBackgroundWorker_ProgressChanged(System::Object ^ sender, System::ComponentModel::ProgressChangedEventArgs ^ e)
	{
		_toolStripProgressBar->Value = e->ProgressPercentage;
	}

	System::Void MainForm::playerBackgroundWorker_RunWorkerCompleted(System::Object ^ sender, System::ComponentModel::RunWorkerCompletedEventArgs ^ e)
	{
		if (e->Cancelled)
		{
			showCancelDialog();
		}
		else if (e->Error != nullptr)
		{
			showErrorDialog(e->Error->Message);
		}
		else
		{
			if (_isPlayerPlaying)
			{
				_trackBarTimer->Start();
			}
			else
			{
				_trackBarTimer->Stop();
			}
		}
		onWorkerStop();
	}

	System::Void MainForm::trackBarTimer_Tick(System::Object ^ sender, System::EventArgs ^ e)
	{
		__int64 normalize = ((__int64)10000 * _presenter->getPosition()) / _presenter->getLength();
		_playerTrackBar->Value = (int) System::Math::Min( normalize, (__int64) 10000);
	}

	System::Void MainForm::onSkipButtonClick(System::Object ^ sender, System::EventArgs ^ e)
	{
		if (_playerExists)
		{
			_presenter->seek(30.);
		}
	}

	System::Void MainForm::onStopMixToolStripMenuItemClick(System::Object ^ sender, System::EventArgs ^ e)
	{
		stopPlayer();
	}

	System::Void MainForm::stopPlayer()
	{
		if (_playerExists)
		{
			_trackBarTimer->Stop();
			_playerTrackBar->Value = 0;
			_presenter->stopMix();
			_isPlayerPlaying = false;
			_playerExists = false;
			_playerbutton->Image = gcnew Bitmap(PlayIcon, 60, 60);
		}
	}

	System::Void MainForm::onButtonEnabledChanged(System::Object ^ sender, System::EventArgs ^ e)
	{
		Button^ modifiedButton = (Button^)sender;
		if (!modifiedButton->Enabled)
		{
			modifiedButton->BackColor = Color::FromArgb(100, 0, 100);
		}
		else
		{
			modifiedButton->BackColor = Color::DarkViolet;
		}
	}

	System::Void MainForm::musicListView_DrawItem(System::Object ^ sender, System::Windows::Forms::DrawListViewItemEventArgs ^ e)
	{
		if (e->Item->Selected)
		{
			e->Graphics->FillRectangle(gcnew SolidBrush(AutoMixColorTable::SelectionColor), e->Bounds);
		}
	}

	System::Void MainForm::musicListView_DrawColumnHeader(System::Object ^ sender, System::Windows::Forms::DrawListViewColumnHeaderEventArgs ^ e)
	{
		e->DrawBackground();
		e->DrawText(TextFormatFlags::TextBoxControl);
	}

	System::Void MainForm::musicListView_DrawSubItem(System::Object ^ sender, System::Windows::Forms::DrawListViewSubItemEventArgs ^ e)
	{
		if (e->Item->Selected)
		{
			e->Graphics->FillRectangle(gcnew SolidBrush(AutoMixColorTable::SelectionColor), e->Bounds);
		}
		e->DrawText(TextFormatFlags::TextBoxControl);
	}

	System::Void MainForm::sortTrackList(System::Object^ sender, System::EventArgs^ e)
	{
		onWorkerStart();
		_sortBackgroundWorker->RunWorkerAsync();
	}

	System::Void MainForm::loadTracks(System::Object ^ sender, System::EventArgs ^ e)
	{
		OpenFileDialog^ dialog = gcnew OpenFileDialog();
		dialog->Filter = _resourceManager->GetString("dialog_filters");
		dialog->FilterIndex = 1;
		dialog->Multiselect = true;

		if (dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			onWorkerStart();
			_importBackgroundWorker->RunWorkerAsync(dialog->FileNames);
		}
	}

	System::Void MainForm::exportTrackList(System::Object^  sender, System::EventArgs^  e)
	{
		SaveFileDialog^ dialog = gcnew SaveFileDialog;
		dialog->Filter = _resourceManager->GetString("dialog_filters");
		dialog->FilterIndex = 1;
		dialog->FileName = "Auto Mix";
		dialog->DefaultExt = "mp3";
		dialog->RestoreDirectory = true;

		if (dialog->ShowDialog() == ::DialogResult::OK)
		{
			onWorkerStart();
			_exportPath = dialog->FileName;
			_exportBackgroundWorker->RunWorkerAsync(dialog->FileName);
		}
	}

	System::Void MainForm::onWorkerStart()
	{
		AnOperationRunning = true;

		_cancelMenuItem->Enabled = true;
		_generateButton->Enabled = false;
		_importButton->Enabled = false;
		_sortButton->Enabled = false;
		_playerbutton->Enabled = false;

		_importMenuItem->Enabled = false;
		_optionsToolStripMenuItem->Enabled = false;
		_toolStripProgressBar->Value = 0;
		_toolStripProgressBar->Visible = true;

		_musicListView->AllowDrop = false;
	}

	System::Void MainForm::onWorkerStop()
	{
		AnOperationRunning = false;

		_cancelMenuItem->Enabled = false;
		_generateButton->Enabled = true;
		_importButton->Enabled = true;
		_sortButton->Enabled = true;
		_playerbutton->Enabled = true;

		_importMenuItem->Enabled = true;
		_optionsToolStripMenuItem->Enabled = true;
		_toolStripProgressBar->Visible = false;
		_toolStripProgressBar->Value = 0;

		_musicListView->AllowDrop = true;
	}

	System::Void MainForm::showCancelDialog()
	{
		String^ msg = _resourceManager->GetString("cancel_msg");
		String^ caption = _resourceManager->GetString("cancel_caption");
		MessageBox::Show(msg, caption, MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	System::Void MainForm::showErrorDialog(String^ errorMessage)
	{
		String^ msg = String::Format(_resourceManager->GetString("error_msg"), errorMessage);
		String^ caption = _resourceManager->GetString("error_caption");
		MessageBox::Show(msg, caption, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	bool MainForm::showExitDialog()
	{
		String^ msg = _resourceManager->GetString("exit_msg");
		String^ caption = _resourceManager->GetString("exit_caption");;
		return MessageBox::Show(msg, caption, MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::DialogResult::Yes;
	}

	System::Void MainForm::exitApplication()
	{
		_importBackgroundWorker->CancelAsync();
		_sortBackgroundWorker->CancelAsync();
		_exportBackgroundWorker->CancelAsync();
		_playerBackgroundWorker->CancelAsync();
		stopPlayer();

		try
		{
			System::IO::Directory::Delete(Path::GetTempPath() + "AutomixSoftware", true);
		}
		catch (...) {}
		Application::Exit();
	}

	System::Void MainForm::drawInsertionLine()
	{
		if (_insertionIndex != -1)
		{
			int index;

			index = _insertionIndex;

			if (index >= 0 && index < _musicListView->Items->Count)
			{
				Rectangle bounds;
				int x;
				int y;
				int width;

				bounds = _musicListView->Items[index]->GetBounds(ItemBoundsPortion::Entire);
				x = 0;
				y = _insertionMode == InsertionModeType::Before ? bounds.Top : bounds.Bottom;
				width = Math::Min(bounds.Width - bounds.Left, ClientSize.Width);

				this->drawInsertionLine(x, y, width);
			}
		}
	}

	System::Void MainForm::drawInsertionLine(int x1, int y, int width)
	{
		Graphics^ g = _musicListView->CreateGraphics();
		array<Point>^ leftArrowHead;
		array<Point>^ rightArrowHead;
		int arrowHeadSize;
		int x2;

		x2 = x1 + width;
		arrowHeadSize = 7;
		leftArrowHead = gcnew array<Point>
		{
			Point(x1, y - (arrowHeadSize / 2)), Point(x1 + arrowHeadSize, y), Point(x1, y + (arrowHeadSize / 2))
		};
		rightArrowHead = gcnew array<Point>
		{
			Point(x2, y - (arrowHeadSize / 2)), Point(x2 - arrowHeadSize, y), Point(x2, y + (arrowHeadSize / 2))
		};

		Pen^ pen = gcnew Pen(this->_insertionLineColor);

		g->DrawLine(pen, x1, y, x2 - 1, y);
		SolidBrush^ brush = gcnew SolidBrush(this->_insertionLineColor);
		g->FillPolygon(brush, leftArrowHead);
		g->FillPolygon(brush, rightArrowHead);
	}
}