#pragma once
#include "TrackCollection.h"

namespace AutoMixDataManagement {

	public ref class Transition
	{
	public:
		Transition();
		void createFile(System::String^ outputFile);

	private:
		void fadeIn(Track^ track1, Track^ track2);
		void fadeOut(Track^ track1, Track^ track2);

		Mp3FileReader^ _reader;
		TrackCollection^ _trackList;
		NAudio::Wave::SampleProviders::FadeInOutSampleProvider^ _finalWave;
		NAudio::Wave::WaveStream^ _stream;
	};
}