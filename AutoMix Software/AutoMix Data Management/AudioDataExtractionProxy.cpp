#include "stdafx.h"

#include "AudioDataExtractionProxy.h"
#include "AudioDataExtractionMock.h"

namespace AutoMixDataManagement {

	AudioDataExtractionProxy::AudioDataExtractionProxy()
	{
		_realSubject = gcnew AudioDataExtractionMock();
	}

	void AudioDataExtractionProxy::setPath(System::String^ path)
	{
		_realSubject->setPath(path);
	}

	void AudioDataExtractionProxy::extractBPM(Track^ track)
	{
		_realSubject->extractBPM(track);
	}

	void AudioDataExtractionProxy::extractBPM(TrackCollection^ trackCollection)
	{
		_realSubject->extractBPM(trackCollection);
	}

	void AudioDataExtractionProxy::extractDuration(Track^ track)
	{
		_realSubject->extractDuration(track);
	}

	void AudioDataExtractionProxy::extractDuration(TrackCollection^ trackCollection)
	{
		_realSubject->extractDuration(trackCollection);
	}

	void AudioDataExtractionProxy::extractKey(Track^ track)
	{
		_realSubject->extractKey(track);
	}

	void AudioDataExtractionProxy::extractKey(TrackCollection^ trackCollection)
	{
		_realSubject->extractKey(trackCollection);
	}

}
