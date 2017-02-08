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
using namespace System::Threading;
using namespace System::Diagnostics;
using namespace System::IO;
using namespace System;
using namespace Newtonsoft::Json;

namespace AutoMixDataManagement {

	AudioDataExtraction::AudioDataExtraction()
	{
		gcnew DataBase();
		initExecConfiguration();
	}

	void AudioDataExtraction::extractData(System::ComponentModel::BackgroundWorker^ bw, TrackCollection^ trackCollection)
	{
		CancellationTokenSource^ cts = gcnew CancellationTokenSource();
		DelegateAudioDataExtraction^ d = gcnew DelegateAudioDataExtraction(bw, trackCollection->Count,cts, _tempDirectory);
		ParallelOptions^ po = gcnew ParallelOptions();
		po->CancellationToken = cts->Token;
		po->MaxDegreeOfParallelism = (int) Math::Ceiling(System::Environment::ProcessorCount / 2.);
		try
		{
			Parallel::ForEach(trackCollection, po, gcnew Action<Track^>(d, &DelegateAudioDataExtraction::delegateExtraction));
		}
		catch (OperationCanceledException^)
		{
			return;
		}
	}

	void AudioDataExtraction::initExecConfiguration()
	{

		String^ temppath = Path::GetTempPath() + "AutomixSoftware";

		if (!Directory::Exists(temppath))
		{
			_tempDirectory = Directory::CreateDirectory(temppath);
		}
		else
		{
			System::IO::Directory::Delete(temppath, true);
			_tempDirectory = Directory::CreateDirectory(temppath);
		}

		String^ profileName = _tempDirectory->FullName + "\\profile.yaml";
		StreamWriter^ sw = gcnew StreamWriter(profileName);
		sw->Write("outputFormat: json\noutputFrames: 0\nlowlevel:\n    stats: [ \"mean\" ]\n    mfccStats: [\"mean\"]\n\
    gfccStats : [\"mean\"]\nrhythm :\n    stats : [\"mean\", \"var\", \"median\", \"min\", \"max\"]\ntonal :\n\
    stats : [\"mean\", \"var\", \"median\", \"min\", \"max\"]");
		sw->Close();
	}
}