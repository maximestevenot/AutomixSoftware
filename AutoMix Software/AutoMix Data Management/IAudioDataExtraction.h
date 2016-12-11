#pragma once

#include "TrackCollection.h"

namespace AutoMixDataManagement {

	public ref class IAudioDataExtraction abstract
	{

	public:
		//IAudioDataExtraction() {}

		//virtual ~IAudioDataExtraction() {}

		virtual void extractBPM(Track^) abstract;
		virtual void extractBPM(TrackCollection^) abstract;
	};

}