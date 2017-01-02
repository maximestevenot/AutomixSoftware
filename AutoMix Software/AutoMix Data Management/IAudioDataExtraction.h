#pragma once

#include "TrackCollection.h"

namespace AutoMixDataManagement {

	public ref class IAudioDataExtraction abstract
	{

	public:
		//IAudioDataExtraction() {}

		//virtual ~IAudioDataExtraction() {}

		virtual void setPath(System::String^) abstract;

		virtual void extractBPM(Track^) abstract;
		virtual void extractBPM(TrackCollection^) abstract;

		virtual void extractDuration(Track^) abstract;
		virtual void extractDuration(TrackCollection^) abstract;

		virtual void extractKey(Track^) abstract;
		virtual void extractKey(TrackCollection^) abstract;
	};

}