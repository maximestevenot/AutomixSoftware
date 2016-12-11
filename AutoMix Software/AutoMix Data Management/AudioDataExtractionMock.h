#pragma once

#include "AutoMixDataManagement.h"

namespace AutoMixDataManagement {

	public ref class AudioDataExtractionMock : public IAudioDataExtraction
	{
	public:
		AudioDataExtractionMock();

		void extractBPM(Track^) override;
		void extractBPM(TrackCollection^) override;

	};

}
