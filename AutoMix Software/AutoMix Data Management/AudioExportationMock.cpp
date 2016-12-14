#include "stdafx.h"
#include "AudioExportationMock.h"

using namespace System;
using namespace System::IO;

namespace AutoMixDataManagement {

	AudioExportationMock::AudioExportationMock(System::String^ path)
	{
		_path = path;
	}

	void AudioExportationMock::exportTrackList(TrackCollection^ tracks) 
	{
		StreamWriter^ sw = gcnew StreamWriter(_path + "TEST.txt");

		for each(Track^ t in tracks) 
		{
			sw->WriteLine(t->getName());
		}
		sw->Close();
	}
}