// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

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

	void ExecutableExtraction::extractData(System::ComponentModel::BackgroundWorker^ bw, int nbTracks, System::Threading::CancellationTokenSource^ cts, Track ^ track)
	{
		_startInfo->Arguments = "\"" + track->Path + "\" \"" + track->Id + ".json\" \"" + _tempDirectory->FullName + "\\profile.yaml\"";
		Process^ extractor = gcnew Process;
		extractor->StartInfo = _startInfo;
		extractor->Start();
		while (!bw->CancellationPending && !extractor->HasExited)
		{
			System::Threading::Thread::Sleep(100);
		}
		if (bw->CancellationPending && !extractor->HasExited)
		{
			extractor->Kill();
			cts->Cancel();
		}
		else if (!bw->CancellationPending)
		{
			Threading::Thread::Sleep(50);

			try
			{
				StreamReader^ file = File::OpenText(_tempDirectory->FullName + "\\" + track->Id + ".json");
				JsonTextReader^ reader = gcnew JsonTextReader(file);
				Linq::JObject^ obj = (Linq::JObject^)Linq::JToken::ReadFrom(reader);

				track->Duration = Convert::ToUInt32((double)obj["metadata"]["audio_properties"]["length"] * 1000);
				track->BPM = Convert::ToUInt32((int)(obj["rhythm"]["bpm"]));

				String^ key = (String^)(obj["tonal"]["key_key"]);
				String^ scale = (String^)(obj["tonal"]["key_scale"]);
				track->Key = Utils::convertToOpenKey(key, scale);

				reader->Close();
				file->Close();

				if (track->BPM > 0 && track->Duration > 0)
				{
					DataBase^ db = gcnew DataBase();
					db->addTrack(track);
				}
			}
			catch (FileNotFoundException^ e)
			{
				e->Message;
			}
		}
		bw->ReportProgress((int)100 / nbTracks);
	}

}