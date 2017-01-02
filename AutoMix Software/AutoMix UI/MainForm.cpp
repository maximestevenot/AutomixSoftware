#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections;

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

	System::Void MainForm::_musicListView_ColumnClick(System::Object^ sender, ColumnClickEventArgs^ e)
	{
		// NOT IMPLEMENTED YET

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
		_presenter->loadTracks(Directory::GetFiles(path));
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
		Stream^ myStream;
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