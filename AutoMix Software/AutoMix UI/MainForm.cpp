// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "MainForm.h"

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
			lvitem->SubItems->Add(track->displayDuration());
			lvitem->SubItems->Add(track->BPM.ToString());
			lvitem->SubItems->Add(track->Key);

			_musicListView->Items->Add(lvitem);
		}
	}

	System::Void MainForm::_cancelToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		_importBackgroundWorker->CancelAsync();
		_sortBackgroundWorker->CancelAsync();
		_exportBackgroundWorker->CancelAsync();
	}

	System::Void MainForm::_quitToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		if (showExitDialog())
		{
			exitApplication();
		}
	}

	System::Void MainForm::MainForm_FormClosing(System::Object ^ sender, System::Windows::Forms::FormClosingEventArgs ^ e)
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

	System::Void MainForm::_openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		loadTracks(sender, e);
	}

	System::Void MainForm::_imputButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		loadTracks(sender, e);
	}

	System::Void MainForm::_outputButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		exportTrackList(sender, e);
	}

	System::Void MainForm::_sortButton_click(System::Object^ sender, System::EventArgs^ e)
	{
		sortTracksWithGeneticAlgorithm(sender, e);
	}

	System::Void MainForm::_aboutToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		String^ msg = "AutoMix Software Beta 1.0\n\n";
		msg += "Copyright © 2016-2017 LesProjecteurs - All Rights Reserved\n\n";
		msg += "Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT,\nLouis CARLIER, Pierre GABON";

		String^ caption = "About";
		MessageBox::Show(msg, caption, MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	System::Void MainForm::_clearDBToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		_presenter->clearDataBase();
	}

	System::Void MainForm::_backgroundWorker1_DoWork(System::Object ^ sender, System::ComponentModel::DoWorkEventArgs ^ e)
	{
		BackgroundWorker^ bw = (BackgroundWorker^)sender;
		array<String^>^ fileNames = (array<String^>^) e->Argument;
		e->Result = _presenter->loadTracks(bw, fileNames);

		if (bw->CancellationPending)
		{
			e->Cancel = true;
		}
	}

	System::Void MainForm::_backgroundWorker1_ProgressChanged(System::Object ^ sender, System::ComponentModel::ProgressChangedEventArgs ^ e)
	{
		_toolStripProgressBar->Value += e->ProgressPercentage;
		_presenter->notify();
	}

	System::Void MainForm::_backgroundWorker1_RunWorkerCompleted(System::Object ^ sender, System::ComponentModel::RunWorkerCompletedEventArgs ^ e)
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

	System::Void MainForm::_backgroundWorker2_DoWork(System::Object ^ sender, System::ComponentModel::DoWorkEventArgs ^ e)
	{
		BackgroundWorker^ bw = (BackgroundWorker^)sender;
		e->Result = _presenter->sortTrackCollectionWithGeneticAlgorithm(bw);
		if (bw->CancellationPending)
		{
			e->Cancel = true;
		}
	}

	System::Void MainForm::_backgroundWorker2_ProgressChanged(System::Object ^ sender, System::ComponentModel::ProgressChangedEventArgs ^ e)
	{
		_toolStripProgressBar->Value = e->ProgressPercentage;
	}

	System::Void MainForm::_backgroundWorker2_RunWorkerCompleted(System::Object ^ sender, System::ComponentModel::RunWorkerCompletedEventArgs ^ e)
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

	System::Void MainForm::_backgroundWorker3_DoWork(System::Object ^ sender, System::ComponentModel::DoWorkEventArgs ^ e)
	{
		BackgroundWorker^ bw = (BackgroundWorker^)sender;
		System::String^ fileName = (System::String^) e->Argument;
		_presenter->exportTrackList(bw, fileName);
		if (bw->CancellationPending)
		{
			e->Cancel = true;
		}
	}

	System::Void MainForm::_backgroundWorker3_ProgressChanged(System::Object ^ sender, System::ComponentModel::ProgressChangedEventArgs ^ e)
	{
		_toolStripProgressBar->Value = e->ProgressPercentage;
	}

	System::Void MainForm::toolStripDeleteTrack_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		Generic::List<String^>^ selection = gcnew Generic::List<String^>();

		for each (ListViewItem^ item in _musicListView->SelectedItems)
		{
			selection->Add(item->Text);
		}
		_presenter->removeTracks(selection);
	}

	System::Void MainForm::_listViewcontextMenu_Opening(System::Object ^ sender, System::ComponentModel::CancelEventArgs ^ e)
	{
		if (!AnOperationRunning && _musicListView->SelectedItems->Count != 0)
		{
			_toolStripDeleteTrack->Enabled = true;
		}
		else
		{
			_toolStripDeleteTrack->Enabled = false;
		}
	}

	System::Void MainForm::selectAllToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		for each(ListViewItem^ item in _musicListView->Items)
		{
			item->Selected = true;
		}
	}

	System::Void MainForm::_musicListView_DragEnter(System::Object ^ sender, System::Windows::Forms::DragEventArgs ^ e)
	{
		if (e->Data->GetDataPresent(DataFormats::FileDrop))
		{
			e->Effect = DragDropEffects::Copy;
			IsDragImportInProgress = true;
		}
	}

	System::Void MainForm::_musicListView_DragDrop(System::Object ^ sender, System::Windows::Forms::DragEventArgs ^ drgevent)
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
				ListViewItem^ dropItem = InsertionIndex != -1 ? _musicListView->Items[InsertionIndex] : nullptr;
				if (dropItem != nullptr)
				{
					ListViewItem^ dragItem = (ListViewItem^)drgevent->Data->GetData(ListViewItem::typeid);
					int dropIndex = dropItem->Index;

					if (dragItem->Index < dropIndex)
					{
						dropIndex--;
					}
					if (InsertionMode == InsertionModeType::After && dragItem->Index < _musicListView->Items->Count - 1)
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
				InsertionIndex = -1;
				IsRowDragInProgress = false;
				_musicListView->Invalidate();
			}
		}
	}

	System::Void MainForm::_musicListView_ItemDrag(System::Object ^ sender, System::Windows::Forms::ItemDragEventArgs ^ e)
	{
		if (_musicListView->Items->Count > 1)
		{
			IsRowDragInProgress = true;
			DoDragDrop(e->Item, DragDropEffects::Move);
		}
	}

	System::Void MainForm::_musicListView_DragOver(System::Object ^ sender, System::Windows::Forms::DragEventArgs ^ drgevent)
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
				DrawInsertionLine();
			}

			else
			{
				insertionIndex = -1;
				insertionMode = this->InsertionMode;
				drgevent->Effect = DragDropEffects::None;
			}

			if (insertionIndex != this->InsertionIndex || insertionMode != this->InsertionMode)
			{
				InsertionMode = insertionMode;
				InsertionIndex = insertionIndex;
				_musicListView->Invalidate();
			}
		}
	}

	System::Void MainForm::_backgroundWorker3_RunWorkerCompleted(System::Object ^ sender, System::ComponentModel::RunWorkerCompletedEventArgs ^ e)
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

	System::Void MainForm::sortTracksWithGeneticAlgorithm(System::Object^ sender, System::EventArgs^ e)
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
		MessageBox::Show(msg, caption, MessageBoxButtons::OK, MessageBoxIcon::Stop);
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

	System::Void MainForm::DrawInsertionLine()
	{
		if (InsertionIndex != -1)
		{
			int index;

			index = InsertionIndex;

			if (index >= 0 && index < _musicListView->Items->Count)
			{
				Rectangle bounds;
				int x;
				int y;
				int width;

				bounds = _musicListView->Items[index]->GetBounds(ItemBoundsPortion::Entire);
				x = 0;
				y = InsertionMode == InsertionModeType::Before ? bounds.Top : bounds.Bottom;
				width = Math::Min(bounds.Width - bounds.Left, ClientSize.Width);

				this->DrawInsertionLine(x, y, width);
			}
		}
	}

	System::Void MainForm::DrawInsertionLine(int x1, int y, int width)
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

		Pen^ pen = gcnew Pen(this->InsertionLineColor);

		g->DrawLine(pen, x1, y, x2 - 1, y);
		SolidBrush^ brush = gcnew SolidBrush(this->InsertionLineColor);
		g->FillPolygon(brush, leftArrowHead);
		g->FillPolygon(brush, rightArrowHead);
	}
}