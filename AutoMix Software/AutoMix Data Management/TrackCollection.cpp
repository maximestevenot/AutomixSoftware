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

}