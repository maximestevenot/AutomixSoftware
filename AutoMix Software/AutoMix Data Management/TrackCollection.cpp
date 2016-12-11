#include "stdafx.h"
#include "TrackCollection.h"

namespace AutoMixDataManagement {

	void TrackCollection::add(Track track)
	{
		this->push_back(track);
	}

	Track TrackCollection::searchByName(std::string name)
	{
		for (Track t : *this)
		{
			if (name.compare(t.getName()) == 0)
			{
				return t;
			}
		}

		return Track();
	}

}