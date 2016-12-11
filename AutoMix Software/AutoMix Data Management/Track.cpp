#include "stdafx.h"
#include "Track.h"

namespace AutoMixDataManagement {

	Track::Track()
	{
		_data = gcnew Data();
	}

	Track::Track(String^ path)
	{
		_path = path;
	}
	
	Track::~Track()
	{
	}

	String^ Track::getName() 
	{
		return _name;
	}

	unsigned int Track::getBPM() 
	{
		return _data->bpm;
	}

	unsigned int Track::getDuration() 
	{
		return _data->duration;
	}

	void Track::setBPM(unsigned int value)
	{
		_data->bpm = value;
	}

}