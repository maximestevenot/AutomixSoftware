#pragma once

#include "AutoMixDataManagement.h"

namespace AutoMixDataManagement {

	public ref class AudioDataExtractionMock : public IAudioDataExtraction
	{
	public:
		AudioDataExtractionMock();

		void setPath(System::String ^) override;

		void extractBPM(Track^) override;
		void extractBPM(TrackCollection^) override;

		void extractDuration(Track^) override;
		void extractDuration(TrackCollection^) override;

		void extractKey(Track^) override;
		void extractKey(TrackCollection^) override;

	private:
		System::String^ _textFile;

	};

}
