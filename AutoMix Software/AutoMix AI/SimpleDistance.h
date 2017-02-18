#pragma once
#include "TrackDistance.h"

namespace AutoMixAI {

	public ref class SimpleDistance : public TrackDistance
	{
	public:
		static int BPM_COEFFICIENT = 1200;
		static int KEY_NUMBER_COEFFICIENT = 30;
		static int KEY_TONALITY_COEFFICIENT = 800;
		static int DANCEABILITY_COEFFICIENT = 10;

		double compute(AutoMixDataManagement::Track^ t1, AutoMixDataManagement::Track^ t2) override;
	};

}

