#include "stdafx.h"
#include "AudioDataExportationProxy.h"


namespace AutoMixDataManagement {

	AudioDataExportationProxy::AudioDataExportationProxy(System::String ^ path)
	{
		_path = path;
		_realSubject = gcnew AudioDataExportationMock(_path);
	}

	void AudioDataExportationProxy::exportTrackList(TrackCollection^ tracks) {
		_realSubject->exportTrackList(tracks);
	}

}