#include "stdafx.h"
#include "TracksComparison.h"

namespace AutoMixDataManagement {
	namespace TracksComparison {

		int compareTracksByDuration(Track^ t1, Track^ t2)
		{
			return t1->Duration.CompareTo(t2->Duration);
		}

		int compareTracksByBPM(Track^ t1, Track^ t2)
		{
			return t1->BPM.CompareTo(t2->BPM);
		}

		int compareTracksByName(Track^ t1, Track^ t2)
		{
			return t1->Name->CompareTo(t2->Name);
		}
	}
}