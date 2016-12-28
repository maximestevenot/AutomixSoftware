#include "stdafx.h"
#include "TrackCollection.h"

namespace AutoMixDataManagement {

	using namespace System;

	void TrackCollection::add(Track^ track)
	{
		Add(track);
	}

	Track^ TrackCollection::searchByName(String^ name)
	{
		for each (auto t in this)
		{
			if (name->CompareTo(t->Name))
			{
				return t;
			}
		}

		return nullptr;
	}

	void TrackCollection::orderByName()
	{
		Sort(gcnew Comparison<Track^>(TracksComparison::compareTracksByName));
	}

	void TrackCollection::orderByDescendingName()
	{
		orderByName();
		Reverse();
	}

	void TrackCollection::orderByDuration()
	{
		Sort(gcnew Comparison<Track^>(TracksComparison::compareTracksByDuration));
	}

	void TrackCollection::orderByDescendingDuration()
	{
		orderByDuration();
		Reverse();
	}

	void TrackCollection::orderByBPM()
	{
		Sort(gcnew Comparison<Track^>(TracksComparison::compareTracksByBPM));
	}

	void TrackCollection::orderByDescendingBPM()
	{
		orderByBPM();
		Reverse();
	}

}