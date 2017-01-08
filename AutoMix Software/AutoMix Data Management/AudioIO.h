#pragma once
#include "TrackCollection.h"

namespace AutoMixDataManagement {
	public ref class AudioIO
	{
	public:
		AudioIO();
		static void Mp3Export(TrackCollection^ trackCollection, System::String^ outputFile);
		static void TextExport(TrackCollection^ trackCollection, System::String^ outputFile);

		static void Mp3ToWav(System::String^ inputFile, System::String^ outputFile);
		static void WavToMp3(System::String^ inputFile, System::String^ outputFile);
	};
}
