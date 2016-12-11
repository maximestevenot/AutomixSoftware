#include "stdafx.h"
#include "Track.h"

namespace AutoMixDataManagement {

	Track::Track()
	{
		_data = new Data();
	}

	Track::Track(std::string path)
	{
		_path = path;
	}


	Track::~Track()
	{
	}

	std::string Track::getName() const
	{
		return _name;
	}

	unsigned int Track::getBPM() const
	{
		return _data->bpm;
	}

	unsigned int Track::getDuration() const
	{
		return _data->duration;
	}

	void Track::setBPM(unsigned int value)
	{
		_data->bpm = value;
	}

}