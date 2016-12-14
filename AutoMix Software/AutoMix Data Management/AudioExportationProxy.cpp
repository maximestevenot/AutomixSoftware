#include "stdafx.h"

#include "AutoMixDataManagement.h"
#include "AudioExportationMock.h"

namespace AutoMixDataManagement {

	AudioExportationProxy::AudioExportationProxy(System::String ^ path)
	{
		_path = path;
		_realSubject = gcnew AudioExportationMock(_path);
	}

	void AudioExportationProxy::exportTrackList(TrackCollection^ tracks) 
	{
		_realSubject->exportTrackList(tracks);
	}

}