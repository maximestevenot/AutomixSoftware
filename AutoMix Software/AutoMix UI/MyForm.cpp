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
		String^ currentItem = _musicListBox->SelectedItem->ToString();

		Track selectedTrack = _trackCollection->searchByName(convertString(currentItem));

		_bpmValueTextArea->Text = selectedTrack.getBPM().ToString();
		_durationValueTextArea->Text = selectedTrack.getBPM().ToString();
	}

	System::Void MyForm::_openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		loadTracksFromDirectory(sender, e);
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

		array<String^>^fileEntries = Directory::GetFiles(path);

		IEnumerator^ files = fileEntries->GetEnumerator();

		while (files->MoveNext())
		{

			String^ fileName = safe_cast<String^>(files->Current);

			int last_point = fileName->LastIndexOf(".");
			String^ ext = fileName->Remove(0, last_point + 1);
			ext = ext->ToLower();

			if (ext->Contains("mp3")) {

				Track track = Track(convertString(fileName));

				int last_slash_idx = fileName->LastIndexOf("\\");
				String^ str = fileName->Remove(0, last_slash_idx + 1);

				_musicListBox->Items->Add(str);
				_trackCollection->add(track);
			}
		}
	}
}