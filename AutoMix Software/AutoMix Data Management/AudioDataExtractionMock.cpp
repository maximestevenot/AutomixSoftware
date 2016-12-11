#include "stdafx.h"
#include "AudioDataExtractionMock.h"

namespace AutoMixDataManagement {

	AudioDataExtractionMock::AudioDataExtractionMock()
	{
	}

	void AudioDataExtractionMock::extractBPM(Track & track)
	{
		track.setBPM(128);
	}

	void AudioDataExtractionMock::extractBPM(TrackCollection & trackCollection)
	{
		for (Track t : trackCollection)
		{
			extractBPM(t);
		}
	}

}