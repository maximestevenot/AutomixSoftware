// AutoMix Data Management.h

#pragma once

#include "TrackCollection.h"
#include "AudioDataExtractionProxy.h"

using namespace System;

namespace AutoMixDataManagement {

	public ref class IAudioDataExtraction
	{

	public:
		IAudioDataExtraction() {}

		virtual ~IAudioDataExtraction() {}

		virtual void extractBPM(Track^) = 0;
		virtual void extractBPM(TrackCollection^) = 0;
	};
}
