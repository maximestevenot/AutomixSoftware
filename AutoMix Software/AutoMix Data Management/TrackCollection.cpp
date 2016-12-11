#include "stdafx.h"
#include "TrackCollection.h"

namespace AutoMixDataManagement {

	void TrackCollection::add(Track^ track)
	{
		Add(track);
	}

	Track^ TrackCollection::searchByName(String^ name)
	{
		for each (auto t in this)
		{
			if (name->CompareTo(t->getName()))
			{
				return t;
			}
		}

		return nullptr;
	}

}