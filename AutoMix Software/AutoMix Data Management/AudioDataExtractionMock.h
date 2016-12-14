#pragma once

#include "AutoMixDataManagement.h"

namespace AutoMixDataManagement {

	public ref class AudioDataExtractionMock : public IAudioDataExtraction
	{
	public:
		AudioDataExtractionMock();

		void extractBPM(Track^) override;
		void extractBPM(TrackCollection^) override;

		void extractDuration(Track^) override;
		void extractDuration(TrackCollection^) override;

	private:
		System::Random^ _randomGenerator;

	};

}
