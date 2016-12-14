
#include "stdafx.h"
#include "AudioDataExportationMock.h"

#include <Windows.h>
#include <afx.h>

using namespace System;
using namespace System::IO;

namespace AutoMixDataManagement {

	AudioDataExportationMock::AudioDataExportationMock(System::String^ path)
	{
		_path = path;
	}

	void AudioDataExportationMock::exportTrackList(TrackCollection^ tracks) {
		StreamWriter^ sw = gcnew StreamWriter(_path);
		for each(Track^ t in tracks) {
				sw->WriteLine(t->getName());
			}
		sw->Close();
	}
}