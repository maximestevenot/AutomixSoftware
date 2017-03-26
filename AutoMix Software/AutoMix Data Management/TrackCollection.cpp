// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "IExportation.h"
#include "TrackCollection.h"
#include "SimpleConcatenation.h"
#include "SmoothMix.h"
#include "AudioIO.h"

namespace AutoMixDataManagement {

	using namespace System;
	
	void TrackCollection::safeAdd(Track^ track)
	{
		if (!isPresent(track) && !String::IsNullOrEmpty(track->Checksum))
		{
			Add(track);
		}
	}

	bool TrackCollection::isPresent(Track^ track)
	{
		for each (Track^ t in this)
		{
			if (track->Checksum->Equals(t->Checksum) || track->Checksum->Equals(t->Checksum))
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

	TrackCollection ^ TrackCollection::CopyFrom(TrackCollection ^ old)
	{
		TrackCollection^ newCollection = gcnew TrackCollection();
		for each (Track^ t in old)
		{
			newCollection->Add(Track::CopyFrom(t));
		}
		return newCollection;
	}

	bool TrackCollection::IsNull(Track ^ t)
	{
		return (t->Duration == 0 || String::IsNullOrEmpty(t->Checksum));
	}

	void TrackCollection::purge()
	{
		RemoveAll(gcnew Predicate<Track^>(IsNull));
	}

	void TrackCollection::concat(TrackCollection ^ orig)
	{
		for each (Track^ t in orig)
		{
			safeAdd(t);
		}
	}

	void TrackCollection::exportToMP3(System::ComponentModel::BackgroundWorker^ bw, String ^ outputFile)
	{
		IExportation^ exportEngine = gcnew SmoothMix();
		exportEngine->exportMix(bw, this, outputFile);
	}

	void TrackCollection::exportToText(System::String ^ outputFile)
	{
		AudioIO::TextExport(this, outputFile);
	}

	void TrackCollection::Remove(System::String^ name)
	{
		Track^ temp = search(name);
		if (temp)
		{
			Remove(temp);
		}
	}

	Track^ TrackCollection::search(String^ name)
	{
		for each (Track^ t in this)
		{
			if (t->Name->Equals(name))
			{
				return t;
			}
		}
		return nullptr;
	}
}