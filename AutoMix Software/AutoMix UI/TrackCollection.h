#pragma once

#include <vector>
#include "Track.h"

namespace AM_Resources {

	typedef std::vector<Track> track_collection;

	public class TrackCollection : public track_collection
	{

	public:
		void add(Track);
		//friend std::ostream & operator<<(std::ostream &, const TrackCollection &);
	};
}