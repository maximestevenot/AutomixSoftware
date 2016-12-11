#pragma once

#include "AutoMixDataManagement.h"

namespace AutoMixDataManagement {

	ref class AudioDataExtractionMock : public IAudioDataExtraction
	{
	public:
		AudioDataExtractionMock();

		void extractBPM(Track &) override;
		void extractBPM(TrackCollection &) override;

	};

}
