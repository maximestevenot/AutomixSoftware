#include "stdafx.h"
#include "TrackCollection.h"
#include "AudioIO.h"

namespace AutoMixDataManagement {

	using namespace System;

	Track^ TrackCollection::searchByName(String^ name)
	{
		for each (auto t in this)
		{
			if (name->Equals(t->Name))
			{
				return t;
			}
		}

		return nullptr;
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

	void TrackCollection::exportToMP3(String ^ outputFile)
	{
		AudioIO::Mp3Export(this, outputFile);
	}

}