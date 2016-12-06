#include "Track.h"
#include <iostream>

namespace AM_Resources {

	using namespace AM_Utils;

	Track::Track() {
		_data = new Data();
	}
	
	Track::Track(std::string path) : Track()
	{
		_path = path;
		_name = AM_Utils::nameFromPath(path);
	}

	std::string Track::getName() const
	{
		return _name;
	}

	unsigned int Track::getBPM() const
	{
		return _data->_bpm;
	}

	unsigned int Track::getDuration() const 
	{
		return _data->_duration;
	}

	std::ostream & operator<<(std::ostream & out, const Track & track) 
	{
		out << track.getName();
		return out;
	}
}