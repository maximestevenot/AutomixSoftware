#include "stdafx.h"
#include "ExecutableExtraction.h"

using namespace System::Threading::Tasks;
using namespace System::Diagnostics;
using namespace System::IO;
using namespace System;
using namespace Newtonsoft::Json;

namespace AutoMixDataManagement {

	ExecutableExtraction::ExecutableExtraction(System::IO::DirectoryInfo^ tempDirectory)
	{
		_tempDirectory = tempDirectory;

		String^ extractorpath = Directory::GetCurrentDirectory() + "\\essentia_streaming_extractor_music.exe";

		_startInfo = gcnew ProcessStartInfo(extractorpath);
		_startInfo->UseShellExecute = false;
		_startInfo->WorkingDirectory = _tempDirectory->FullName;
		_startInfo->WindowStyle = ProcessWindowStyle::Hidden;
		_startInfo->CreateNoWindow = true;
	}

	void ExecutableExtraction::extractData(Track ^ track)
	{
		_startInfo->Arguments = "\"" + track->Path + "\" \"" + track->Name + ".json\" \"" + _tempDirectory->FullName + "\\profile.yaml\"";
		Process^ extractor = gcnew Process;
		extractor->StartInfo = _startInfo;
		extractor->Start();
		extractor->WaitForExit();
		Threading::Thread::Sleep(50);

		try
		{
			StreamReader^ file = File::OpenText(_tempDirectory->FullName + "\\" + track->Name + ".json");
			JsonTextReader^ reader = gcnew JsonTextReader(file);
			Linq::JObject^ obj = (Linq::JObject^)Linq::JToken::ReadFrom(reader);

			track->Duration = Convert::ToUInt32((double)obj["metadata"]["audio_properties"]["length"] * 1000);
			track->BPM = Convert::ToUInt32((int)(obj["rhythm"]["bpm"]));
			track->Key = (String^)(obj["tonal"]["key_key"]) + (String^)(obj["tonal"]["key_scale"]);

			reader->Close();
			file->Close();

			DataBase^ db = gcnew DataBase();
			db->addTrack(track);
		}
		catch (FileNotFoundException^ e)
		{
			e->Message;
		}
	}

}