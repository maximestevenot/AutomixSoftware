#include <string>
#include <iostream>

#include "MyForm.h"
#include "Track.h"
#include "TrackCollection.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace AM_Resources;

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	AutoMix_UI::MyForm form;
	Application::Run(%form);
}

namespace AutoMix_UI {

	System::Void MyForm::_quitToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e)
	{
		Application::Exit();
	}




	System::Void MyForm::_musicListBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		/*String^ currentItem = _musicListView->SelectedItem->ToString();

		Track selectedTrack = _trackCollection->searchByName(toStdString(currentItem));

		_bpmValueTextArea->Text = selectedTrack.getBPM().ToString();
		_durationValueTextArea->Text = selectedTrack.getBPM().ToString();*/
	}

	System::Void MyForm::_openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		loadTracksFromDirectory(sender, e);
	}

	System::Void MyForm::_extractionButton_Click(System::Object^  sender, System::EventArgs^  e)
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

	System::Void MyForm::loadTracksFromDirectory(System::Object ^ sender, System::EventArgs ^ e)
	{

		System::Windows::Forms::DialogResult result = _inputMusicFolderBrowserDialog->ShowDialog();

		if (result != System::Windows::Forms::DialogResult::OK) {
			return;
		}

		String^ path = _inputMusicFolderBrowserDialog->SelectedPath;

		if (!Directory::Exists(path))
		{
			//TODO display error
			return;
		}

		_statusStrip->Items->Add(path);

		array<String^>^fileEntries = Directory::GetFiles(path);

		IEnumerator^ files = fileEntries->GetEnumerator();

		while (files->MoveNext())
		{

			String^ filePath = safe_cast<String^>(files->Current);
			String^ extension = extractExtension(filePath);

			if (extension->Contains("mp3")) { //TODO make it better

				Track track = Track(toStdString(filePath));
				_trackCollection->add(track);
				ListViewItem^ lvitem = gcnew ListViewItem(toManagedString(track.getName()));
				lvitem->SubItems->Add(track.getDuration().ToString());
				lvitem->SubItems->Add(track.getBPM().ToString());

				_musicListView->Items->Add(lvitem);

			}
		}
	}
}