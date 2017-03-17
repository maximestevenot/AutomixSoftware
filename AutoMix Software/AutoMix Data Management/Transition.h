#pragma once
#include "TrackCollection.h"

namespace AutoMixDataManagement {

	public ref class Transition
	{
	public:
		Transition(TrackCollection^ trackCollection);
		void makeTransition();

	private:
		void fadeIn(Track^ track);
		void fadeOut(Track^ track);
		void fadeInOut(Track^ track);

		NAudio::Wave::AudioFileReader^ _reader;
		TrackCollection^ _trackList;
		NAudio::Wave::SampleProviders::FadeInOutSampleProvider^ _finalWave;
		NAudio::Wave::WaveStream^ _stream;
		NAudio::Wave::WaveFileWriter^ _waveFileWriter;
		int _time=0;
	};
}