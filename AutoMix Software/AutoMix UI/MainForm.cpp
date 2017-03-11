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
using namespace System::Windows::Forms;
using namespace System::Collections;
using namespace System::ComponentModel;
using namespace System::Threading;

namespace AutoMixUI {

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
		String^ msg = "AutoMix Software Beta 1.0\n\n";
		msg += "Copyright © 2016-2017 LesProjecteurs - All Rights Reserved\n\n";
		msg += "Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT,\nLouis CARLIER, Pierre GABON";

		String^ caption = "About";
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
			_presenter->notify();
		}
		onWorkerStop();
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

	System::Void MainForm::onDeleteTrackToolStripClick(System::Object ^ sender, System::EventArgs ^ e)
	{
		Generic::List<String^>^ selection = gcnew Generic::List<String^>();

		for each (ListViewItem^ item in _musicListView->SelectedItems)
		{
			selection->Add(item->Text);
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
		for each(ListViewItem^ item in _musicListView->Items)
		{
			item->Selected = true;
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
				for each (auto s in fileNames) {
					Diagnostics::Debug::WriteLine(s);
				}
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

	System::Void MainForm::exportBW_RunWorkerCompleted(System::Object ^ sender, System::ComponentModel::RunWorkerCompletedEventArgs ^ e)
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
	}

	System::Void MainForm::sortTrackList(System::Object^ sender, System::EventArgs^ e)
	{
		onWorkerStart();
		_sortBackgroundWorker->RunWorkerAsync();
	}

	System::Void MainForm::loadTracks(System::Object ^ sender, System::EventArgs ^ e)
	{
		OpenFileDialog^ dialog = gcnew OpenFileDialog();
		dialog->Filter = "MP3 files (*.mp3)|*.mp3|All files (*.*)|*.*";
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
		dialog->Filter = "MP3 files (*.mp3)|*.mp3|All files (*.*)|*.*";
		dialog->FilterIndex = 1;
		dialog->FileName = "Auto Mix";
		dialog->DefaultExt = "mp3";
		dialog->RestoreDirectory = true;

		if (dialog->ShowDialog() == ::DialogResult::OK)
		{
			onWorkerStart();
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

		_importMenuItem->Enabled = true;
		_optionsToolStripMenuItem->Enabled = true;
		_toolStripProgressBar->Visible = false;
		_toolStripProgressBar->Value = 0;

		_musicListView->AllowDrop = true;
	}

	System::Void MainForm::showCancelDialog()
	{
		String^ msg = "Operation was canceled";
		String^ caption = "Cancel";
		MessageBox::Show(msg, caption, MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	System::Void MainForm::showErrorDialog(String^ errorMessage)
	{
		String^ msg = String::Format("An error occurred: {0}", errorMessage);
		String^ caption = "Error";
		MessageBox::Show(msg, caption, MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	bool MainForm::showExitDialog()
	{
		String^ msg = "Are you sure you want to quit ?";
		String^ caption = "Exit";
		return MessageBox::Show(msg, caption, MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::DialogResult::Yes;
	}

	System::Void MainForm::exitApplication()
	{
		_importBackgroundWorker->CancelAsync();
		_sortBackgroundWorker->CancelAsync();
		_exportBackgroundWorker->CancelAsync();

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