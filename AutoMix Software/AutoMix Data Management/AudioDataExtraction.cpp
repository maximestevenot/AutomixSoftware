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

using namespace System::Diagnostics;
using namespace System::IO;
using namespace System;

namespace AutoMixDataManagement {

	AudioDataExtraction::AudioDataExtraction()
	{
		String^ extractorpath = System::IO::Directory::GetCurrentDirectory() + "\\essentia_streaming_extractor_music.exe";
		String^ temppath = Path::GetTempPath() + "AutomixSoftware";
		if (!Directory::Exists(temppath)) {
			_tempDirectory = Directory::CreateDirectory(temppath);
		}
		_startInfo = gcnew ProcessStartInfo(extractorpath);
		_startInfo->UseShellExecute = false;
		_startInfo->WorkingDirectory = _tempDirectory->FullName;
		_startInfo->WindowStyle = ProcessWindowStyle::Hidden;
	}

	AudioDataExtraction::~AudioDataExtraction()
	{
		_tempDirectory->Delete();
	}

	void AudioDataExtraction::extractData(Track^ track)
	{
	}

	void AudioDataExtraction::extractData(TrackCollection^ trackCollection)
	{
	}
}