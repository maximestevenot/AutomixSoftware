#include "stdafx.h"
#include "AudioDataExtractionMock.h"

using namespace System;

namespace AutoMixDataManagement {

	AudioDataExtractionMock::AudioDataExtractionMock()
	{
		_randomGenerator = gcnew Random();
	}

	void AudioDataExtractionMock::extractBPM(Track^ track)
	{
		track->setBPM(_randomGenerator->Next(95, 150));
	}

	void AudioDataExtractionMock::extractBPM(TrackCollection^ trackCollection)
	{
		for each (auto t in trackCollection)
		{
			extractBPM(t);
		}
	}

	void AudioDataExtractionMock::extractDuration(Track^ track)
	{
		track->setDuration(_randomGenerator->Next(90000, 300000));
	}

	void AudioDataExtractionMock::extractDuration(TrackCollection^ trackCollection)
	{
		for each (auto t in trackCollection)
		{
			extractDuration(t);
		}
	}

}