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
		unsigned int duration = _data->duration;
		int seconds = 0;
		int minutes = 0;
		int hours = 0;
		String^ stringDuration = gcnew String("");

		while (duration >= 3600)
		{
			hours++;
			duration = duration - 3600;
		}
		
		while (duration >= 60)
		{
			minutes++;
			duration = duration - 60;
		}

		seconds = duration;

		String^ stringSeconds;
		String^ stringMinutes;
		String^ stringHours;

		if (seconds < 10)
		{
			stringSeconds = stringSeconds->Concat("0", seconds.ToString());
		} else
		{
			stringSeconds = gcnew String(seconds.ToString());
		}

		if (minutes < 10)
		{
			stringMinutes = stringMinutes->Concat("0", minutes.ToString());
		}
		else
		{
			stringMinutes = gcnew String(minutes.ToString());
		}

		if (hours < 10)
		{
			stringHours = stringHours->Concat("0", hours.ToString());
		}
		else
		{
			stringHours = gcnew String(hours.ToString());
		}

		stringDuration = stringDuration->Concat(stringHours, ":", stringMinutes, ":", stringSeconds);
		
		return stringDuration;
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