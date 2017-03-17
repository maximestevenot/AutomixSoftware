// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

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
		int _time;
	};
}