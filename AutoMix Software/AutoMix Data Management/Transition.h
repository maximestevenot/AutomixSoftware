#pragma once
#include "TrackCollection.h"

namespace AutoMixDataManagement {

	public ref class Transition
	{
	public:
		Transition();
		void fadeIn(Track^ track1, Track^ track2);
		void fadeOut(Track^ track1, Track^ track2);
	private:
		NAudio::Wave::SampleProviders::FadeInOutSampleProvider^ _transition;
	};
}

