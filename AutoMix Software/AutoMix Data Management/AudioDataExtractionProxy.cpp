#include "stdafx.h"
#include "AudioDataExtractionProxy.h"

namespace AutoMixDataManagement {

	AudioDataExtractionProxy::AudioDataExtractionProxy()
	{
		_realSubject = gcnew AudioDataExtractionMock();
	}

	void AudioDataExtractionProxy::extractBPM(Track & track)
	{
		_realSubject->extractBPM(track);
	}

	void AudioDataExtractionProxy::extractBPM(TrackCollection & trackCollection)
	{
		_realSubject->extractBPM(trackCollection);
	}

}
