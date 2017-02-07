// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "TrackCollection.h"
#include "AudioIO.h"

namespace AutoMixDataManagement {

	using namespace System;

	void TrackCollection::safeAdd(Track^ track)
	{
		if (!search(track))
		{
			Add(track);
		}
	}

	bool TrackCollection::search(Track^ track)
	{
		for each (Track^ t in this)
		{
			if (track->Path->Equals(t->Path))
			{
				return true;
			}
		}

		return false;
	}

	void TrackCollection::sortByName()
	{
		Sort(gcnew Comparison<Track^>(TracksComparison::compareTracksByName));
	}

	void TrackCollection::sortByDescendingName()
	{
		sortByName();
		Reverse();
	}

	void TrackCollection::sortByDuration()
	{
		Sort(gcnew Comparison<Track^>(TracksComparison::compareTracksByDuration));
	}

	void TrackCollection::sortByDescendingDuration()
	{
		sortByDuration();
		Reverse();
	}

	void TrackCollection::sortByBPM()
	{
		Sort(gcnew Comparison<Track^>(TracksComparison::compareTracksByBPM));
	}

	void TrackCollection::sortByDescendingBPM()
	{
		sortByBPM();
		Reverse();
	}

	void TrackCollection::purge()
	{
		for each (Track^ t in this)
		{
			if (t->Duration == 0)
			{
				this->Remove(t);
			}
		}
	}

	void TrackCollection::exportToMP3(String ^ outputFile)
	{
		AudioIO::Mp3Export(this, outputFile);
	}

}