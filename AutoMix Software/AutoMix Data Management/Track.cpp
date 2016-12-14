#include "stdafx.h"
#include "Track.h"
#include "Utils.h"

namespace AutoMixDataManagement {

	using namespace System;
	using namespace AutomixDataManagement;

	Track::Track()
	{
		_data = gcnew Data();
	}

	Track::Track(String^ path) : Track()
	{
		_path = path;
		_name = nameFromPath(path);
	}

	Track::~Track()
	{
	}

	String^ Track::getName()
	{
		return _name;
	}

	String^ Track::displayDuration()
	{
		TimeSpan ts = TimeSpan::FromMilliseconds(_data->duration);
		String^ stringDuration = ts.ToString();
		int dotIndex = stringDuration->LastIndexOf(".");

		return stringDuration->Substring(0, dotIndex);
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

	void Track::setDuration(unsigned int value)
	{
		_data->duration = value;
	}

}