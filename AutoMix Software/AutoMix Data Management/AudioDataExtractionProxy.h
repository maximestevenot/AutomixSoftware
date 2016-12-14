#pragma once

#include "AutoMixDataManagement.h"

namespace AutoMixDataManagement {

	public ref class AudioDataExtractionProxy : public IAudioDataExtraction
	{
	public:

		AudioDataExtractionProxy();

		void extractBPM(Track^) override;
		void extractBPM(TrackCollection^) override;

		void extractDuration(Track^) override;
		void extractDuration(TrackCollection^) override;

	private:
		IAudioDataExtraction^ _realSubject;
	};
}