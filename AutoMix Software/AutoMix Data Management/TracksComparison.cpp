// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

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