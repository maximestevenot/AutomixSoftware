#pragma once

#include "Track.h"
#include "TrackCollection.h"

namespace AutoMixDataManagement {
	namespace TracksComparison {

		int compareTracksByName(Track^, Track^);

		int compareTracksByDuration(Track^, Track^);
		int compareTracksByBPM(Track^, Track^);
		
	}
}

