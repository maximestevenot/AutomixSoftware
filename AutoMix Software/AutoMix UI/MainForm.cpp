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

	System::Void MainForm::_quitToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		Application::Exit();
	}

	System::Void MainForm::_openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		loadTracksFromDirectory(sender, e);
	}

	System::Void MainForm::_outputButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		exportTrackList(sender, e);
	}

	System::Void MainForm::_imputButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		loadTracksFromDirectory(sender, e);
	}

	System::Void MainForm::_sortButton_click(System::Object^ sender, System::EventArgs^ e)
	{
		sortTracksWithGeneticAlgorithm(sender, e);
	}

	System::Void MainForm::MainForm_FormClosing(System::Object ^ sender, System::Windows::Forms::FormClosingEventArgs ^ e)
	{
		System::IO::Directory::Delete(Path::GetTempPath() + "AutomixSoftware", true);
	}

	System::Void MainForm::backgroundWorker1_DoWork(System::Object ^ sender, System::ComponentModel::DoWorkEventArgs ^ e)
	{
		BackgroundWorker^ bw = (BackgroundWorker^) sender;
		System::String^ path = (System::String^) e->Argument;
		e->Result = _presenter->loadTracks(bw, Directory::GetFiles(path));
		if (bw->CancellationPending)
		{
			e->Cancel = true;
		}
	}

	System::Void MainForm::backgroundWorker1_RunWorkerCompleted(System::Object ^ sender, System::ComponentModel::RunWorkerCompletedEventArgs ^ e)
	{
		if (e->Cancelled)
		{
			MessageBox::Show("Operation was canceled");
		}
		else if (e->Error != nullptr)
		{
			String^ msg = String::Format("An error occurred: {0}", e->Error->Message);
			MessageBox::Show(msg);
		}
		else
		{
			_presenter->notify((TrackCollection^) e->Result);
			// RemoveProgressBar
		}
	}

	System::Void MainForm::_cancelToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		backgroundWorker1->CancelAsync();
		backgroundWorker2->CancelAsync();
	}

	System::Void MainForm::backgroundWorker2_DoWork(System::Object ^ sender, System::ComponentModel::DoWorkEventArgs ^ e)
	{
		BackgroundWorker^ bw = (BackgroundWorker^)sender;
		e->Result = _presenter->sortTrackCollectionWithGeneticAlgorithm(bw);
		if (bw->CancellationPending)
		{
			e->Cancel = true;
		}
	}

	System::Void MainForm::backgroundWorker2_RunWorkerCompleted(System::Object ^ sender, System::ComponentModel::RunWorkerCompletedEventArgs ^ e)
	{
		if (e->Cancelled)
		{
			MessageBox::Show("Operation was canceled");
		}
		else if (e->Error != nullptr)
		{
			String^ msg = String::Format("An error occurred: {0}", e->Error->Message);
			MessageBox::Show(msg);
		}
		else
		{
			_presenter->notify((TrackCollection^)e->Result);
			// RemoveProgressBar
		}
	}

	System::Void MainForm::_musicListView_ColumnClick(System::Object^ sender, ColumnClickEventArgs^ e)
	{
		// NOT IMPLEMENTED YET

	}

	System::Void MainForm::sortTracksWithGeneticAlgorithm(System::Object^ sender, System::EventArgs^ e)
	{
		backgroundWorker2->RunWorkerAsync();
	}

	System::Void MainForm::loadTracksFromDirectory(System::Object ^ sender, System::EventArgs ^ e)
	{
		_inputMusicFolderBrowserDialog->ShowNewFolderButton = false;
		System::Windows::Forms::DialogResult result = _inputMusicFolderBrowserDialog->ShowDialog();

		if (result != System::Windows::Forms::DialogResult::OK) {
			return;
		}

		String^ path = _inputMusicFolderBrowserDialog->SelectedPath;

		if (!Directory::Exists(path))
		{
			return;
		}

		_statusStrip->Items->Add(path);
		backgroundWorker1->RunWorkerAsync(path);
	}

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
			_presenter->exportTrackList(dialog->FileName);
		}
	}
}