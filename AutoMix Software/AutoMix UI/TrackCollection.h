#pragma once

#include <vector>
#include "Track.h"

namespace AM_Resources {

	typedef std::vector<Track> track_collection;

	public class TrackCollection : public track_collection
	{

	public:
		void add(Track);
		Track searchByName(std::string name);

	};

	std::ostream & operator<<(std::ostream &, const TrackCollection &);
}