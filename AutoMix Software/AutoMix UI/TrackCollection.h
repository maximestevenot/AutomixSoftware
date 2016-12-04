#pragma once

#include <string>
#include <vector>
#include "Track.h"

namespace AMResources {

	public class TrackCollection
	{

	private:

		std::vector<Track> * _trackCollection;

		static TrackCollection *_singleton;

	public:

		void add(Track track) {
			_trackCollection->push_back(track);
		}

		static TrackCollection *getInstance()
		{
			if (NULL == _singleton)
			{
				_singleton = new TrackCollection();
			}

			return _singleton;
		}

		std::vector<Track>* getCollection()
		{
			return _trackCollection;
		}

		static void kill()
		{
			if (NULL != _singleton)
			{
				delete _singleton;
				_singleton = NULL;
			}
		}

		friend std::ostream & operator<<(std::ostream &, const TrackCollection &);


		TrackCollection()
		{
			_trackCollection = new std::vector<Track>();
		}

	};

	TrackCollection *TrackCollection::_singleton = NULL;
	
	
	std::ostream & operator<<(std::ostream & out, const TrackCollection & trackCollection) {
		for (Track t : *(trackCollection._trackCollection)) {
			out << t;
		}
		return out;
	}

}