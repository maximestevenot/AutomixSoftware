#pragma once
#include "TrackCollection.h"

namespace AutoMixDataManagement {
	public ref class AudioIO
	{
	public:
		AudioIO();
		static void simpleMP3Export(TrackCollection^ trackCollection, System::String^ outputFile);
	};
}
