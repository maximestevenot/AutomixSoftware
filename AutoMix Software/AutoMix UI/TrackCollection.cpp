#include <string>
#include "TrackCollection.h"

using namespace std;

namespace AM_Resources {
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

	std::ostream & operator<<(std::ostream & out, const TrackCollection & trackCollection) {

		out << "-----\n";
		for (Track t : trackCollection)
		{
			out << t.getName() << endl;
		}
		out << "-----\n";

		return out;
	}
}