#pragma once

#include "AutoMixDataManagement.h"
#include "AudioDataExtractionMock.h"

namespace AutoMixDataManagement {

	ref class AudioDataExtractionProxy : public IAudioDataExtraction
	{
	public:

		AudioDataExtractionProxy();
		void extractBPM(Track &) override;
		void extractBPM(TrackCollection &) override;

	private:
		IAudioDataExtraction^ _realSubject;
	};

}