#pragma once
#include "TrackCollection.h"

namespace AutoMixDataManagement {
	public ref class AudioIO
	{
	public:
		AudioIO();
		static void MP3Export(TrackCollection^ trackCollection, System::String^ outputFile);
		static void TextExport(TrackCollection^ trackCollection, System::String^ outputFile);
	};
}
