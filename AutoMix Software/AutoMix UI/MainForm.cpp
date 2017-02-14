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
		_backgroundWorker1->CancelAsync();
		_backgroundWorker2->CancelAsync();
		_backgroundWorker3->CancelAsync();
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

	System::Void MainForm::_musicListView_ColumnClick(System::Object^ sender, ColumnClickEventArgs^ e)
	{
		// NOT IMPLEMENTED YET

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
		else
		{
			_presenter->notify();
		}
		onWorkerStop();
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
		if (_musicListView->SelectedItems->Count != 0)
		{
			_toolStripDeleteTrack->Enabled = true;
		}
		else
		{
			_toolStripDeleteTrack->Enabled = false;
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
		_backgroundWorker2->RunWorkerAsync();
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
			_backgroundWorker1->RunWorkerAsync(dialog->FileNames);
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
			_backgroundWorker3->RunWorkerAsync(dialog->FileName);
		}
	}

	System::Void MainForm::onWorkerStart()
	{
		_cancelToolStripMenuItem->Enabled = true;

		_outputButton->Enabled = false;
		_imputButton->Enabled = false;
		_sortButton->Enabled = false;
		_openToolStripMenuItem->Enabled = false;
		optionsToolStripMenuItem->Enabled = false;
		_toolStripProgressBar->Value = 0;
		_toolStripProgressBar->Visible = true;
	}

	System::Void MainForm::onWorkerStop()
	{
		_cancelToolStripMenuItem->Enabled = false;

		_outputButton->Enabled = true;
		_imputButton->Enabled = true;
		_sortButton->Enabled = true;
		_openToolStripMenuItem->Enabled = true;
		optionsToolStripMenuItem->Enabled = true;
		_toolStripProgressBar->Visible = false;
		_toolStripProgressBar->Value = 0;
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
		_backgroundWorker1->CancelAsync();
		_backgroundWorker2->CancelAsync();
		_backgroundWorker3->CancelAsync();
		try
		{
			System::IO::Directory::Delete(Path::GetTempPath() + "AutomixSoftware", true);
		}
		catch (...) {}
		Application::Exit();
	}
}