#include "stdafx.h"
#include "SimpleDistance.h"

using namespace System;
using namespace AutoMixDataManagement;

namespace AutoMixAI {

	double SimpleDistance::compute(Track ^ track1, Track ^ track2)
	{
		bool haveSameScale;
		double digitalTrack1Key, digitalTrack2Key;
		double track1BPM, track2BPM;
		double track1Danceability, track2Danceability;

		try
		{
			haveSameScale = (track1->Key->Contains("d") == track2->Key->Contains("d"));

			digitalTrack1Key = Double::Parse(track1->Key->Remove(track1->Key->Length - 1));
			digitalTrack2Key = Double::Parse(track2->Key->Remove(track2->Key->Length - 1));

			track1BPM = (double)track1->BPM;
			track2BPM = (double)track2->BPM;
			track1Danceability = (double)track1->Danceability;
			track2Danceability = (double)track2->Danceability;
		}
		catch (...)
		{
			return -1;
		}

		double distance = System::Math::Abs((track2BPM - track1BPM)) * BPM_COEFFICIENT;

		distance += System::Math::Abs((track1Danceability - track2Danceability)) * DANCEABILITY_COEFFICIENT;

		if (haveSameScale)
		{
			int distance_abs = (int)System::Math::Abs(digitalTrack1Key - digitalTrack2Key);
			if (distance_abs > 6) {
				distance_abs = 12 - distance_abs;
			}
			distance += distance_abs * KEY_NUMBER_COEFFICIENT;
		}
		else
		{
			if (!(digitalTrack1Key == digitalTrack2Key)) {
				distance += KEY_TONALITY_COEFFICIENT;
			}

		}
		return distance;
	}

}