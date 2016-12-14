#include "stdafx.h"
#include "AudioDataExportationProxy.h"


namespace AutoMixDataManagement {

	AudioDataExportationProxy::AudioDataExportationProxy(System::String ^ path)
	{
		_path = path;
	}

	void AudioDataExportationProxy::exportTrackList(TrackCollection^) {
		//TODO
	}

}