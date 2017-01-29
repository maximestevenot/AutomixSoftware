// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "AudioDataExtraction.h"

#undef GetTempPath

using namespace System::Threading::Tasks;
using namespace System::Diagnostics;
using namespace System::IO;
using namespace System;
using namespace Newtonsoft::Json;

namespace AutoMixDataManagement {

	AudioDataExtraction::AudioDataExtraction()
	{
		String^ extractorpath = Directory::GetCurrentDirectory() + "\\essentia_streaming_extractor_music.exe";
		String^ temppath = Path::GetTempPath() + "AutomixSoftware";
		if (!Directory::Exists(temppath)) {
			_tempDirectory = Directory::CreateDirectory(temppath);
		} else {
			System::IO::Directory::Delete(temppath, true);
			_tempDirectory = Directory::CreateDirectory(temppath);
		}
		_startInfo = gcnew ProcessStartInfo(extractorpath);
		_startInfo->UseShellExecute = false;
		_startInfo->WorkingDirectory = _tempDirectory->FullName;
		_startInfo->WindowStyle = ProcessWindowStyle::Hidden;
		_startInfo->CreateNoWindow = true;

		String^ profileName = _tempDirectory->FullName + "\\profile.yaml";
		StreamWriter^ sw = gcnew StreamWriter(profileName);
		sw->Write("outputFormat: json\noutputFrames: 0\nlowlevel:\n    stats: [ \"mean\" ]\n    mfccStats: [\"mean\"]\n\
    gfccStats : [\"mean\"]\nrhythm :\n    stats : [\"mean\", \"var\", \"median\", \"min\", \"max\"]\ntonal :\n\
    stats : [\"mean\", \"var\", \"median\", \"min\", \"max\"]");
		sw->Close();
	}

	void AudioDataExtraction::extractData(Track^ track)
	{
		String^ parameters = "\"" + track->Path + "\" \"" + track->Name + ".json\" \"" + _tempDirectory->FullName + "\\profile.yaml\"";
		_startInfo->Arguments = parameters;
		Process^ extractor = gcnew Process;
		extractor->StartInfo = _startInfo;
		extractor->Start();
		extractor->WaitForExit();
		StreamReader^ file = File::OpenText(_tempDirectory->FullName + track->Name + ".json");
		JsonTextReader^ reader = gcnew JsonTextReader(file);
		Linq::JObject^ object = (Linq::JObject^)Linq::JToken::ReadFrom(reader);
		track->Duration = Convert::ToInt32(Convert::ToSingle((String^)(object["metadata"]["audio_properties"]["length"]))*1000);
		track->BPM = Convert::ToInt32((String^)(object["rhythm"]["bpm"]));
		track->Key = (String^)(object["tonal"]["key_key"]) + (String^)(object["tonal"]["key_scale"]);
	}
	
	void AudioDataExtraction::extractData(TrackCollection^ trackCollection)
	{
		DelegateAudioDataExtraction^ d = gcnew DelegateAudioDataExtraction(_startInfo, _tempDirectory);
		ParallelOptions^ po = gcnew ParallelOptions();
		po->MaxDegreeOfParallelism = 4;
		Parallel::ForEach(trackCollection, po, gcnew Action<Track^>(d, &DelegateAudioDataExtraction::extractDelegate));
	}
}