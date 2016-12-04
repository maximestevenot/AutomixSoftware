#pragma once

#include <string>
#include <vector>
#include "Track.h"

namespace AMResources {

	public class TrackCollection
	{

	private:

		std::vector<Track> * _trackCollection;

	public:

		void add(Track track) {
			_trackCollection->push_back(track);
		}


		friend std::ostream & operator<<(std::ostream &, const TrackCollection &);


		TrackCollection()
		{
			_trackCollection = new std::vector<Track>();
		}

	};
	
	
	std::ostream & operator<<(std::ostream & out, const TrackCollection & trackCollection) {
		for (Track t : *(trackCollection._trackCollection)) {
			out << t;
		}
		return out;
	}

}