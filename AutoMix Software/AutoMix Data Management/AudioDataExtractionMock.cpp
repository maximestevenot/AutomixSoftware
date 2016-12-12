#include "stdafx.h"
#include "AudioDataExtractionMock.h"

namespace AutoMixDataManagement {

	AudioDataExtractionMock::AudioDataExtractionMock()
	{
	}

	void AudioDataExtractionMock::extractBPM(Track^ track)
	{
		int bpm = (int)AutoMixWrapper::DataExctractionLibrary::safe_fnDataExctracionLibrary();
		track->setBPM(bpm);
	}

	void AudioDataExtractionMock::extractBPM(TrackCollection^ trackCollection)
	{
		for each (auto t in trackCollection)
		{
			extractBPM(t);
		}
	}

}