#include "stdafx.h"
#include "MainForm.h"

#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

namespace AutoMix_UI {

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
		System::Windows::Forms::DialogResult result = _outputMusicFolderBrowserDialog->ShowDialog();

		if (result != System::Windows::Forms::DialogResult::OK) {
			return;
		}

		String^ path = _outputMusicFolderBrowserDialog->SelectedPath;

		if (!Directory::Exists(path))
		{
			//TODO display error
			return;
		}
	}

	System::Void MainForm::_imputButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		loadTracksFromDirectory(sender, e);
	}

	System::Void MainForm::loadTracksFromDirectory(System::Object ^ sender, System::EventArgs ^ e)
	{

		//System::Windows::Forms::DialogResult result = _inputMusicFolderBrowserDialog->ShowDialog();

		//if (result != System::Windows::Forms::DialogResult::OK) {
		//	return;
		//}

		//String^ path = _inputMusicFolderBrowserDialog->SelectedPath;

		//if (!Directory::Exists(path))
		//{
		//	//TODO display error
		//	return;
		//}

		//_statusStrip->Items->Add(path);

		//array<String^>^fileEntries = Directory::GetFiles(path);

		//IEnumerator^ files = fileEntries->GetEnumerator();

		//while (files->MoveNext())
		//{

		//	String^ filePath = safe_cast<String^>(files->Current);
		//	String^ extension = extractExtension(filePath);

		//	if (extension->Contains("mp3")) { //TODO make it better

		//		Track track = Track(toStdString(filePath));
		//		_trackCollection->add(track);
		//		ListViewItem^ lvitem = gcnew ListViewItem(toManagedString(track.getName()));
		//		lvitem->SubItems->Add(track.getDuration().ToString());
		//		lvitem->SubItems->Add(track.getBPM().ToString());

		//		_musicListView->Items->Add(lvitem);

		//	}
		//}
	}
}