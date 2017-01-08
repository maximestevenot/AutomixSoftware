// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

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

