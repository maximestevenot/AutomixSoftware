#pragma once

#include "Track.h"
#include <vector>

namespace AutoMixDataManagement {

	typedef std::vector<Track> track_collection;

	class TrackCollection : public track_collection
	{
	public:
		void add(Track);
		Track searchByName(std::string name);
	};

}