#include "stdafx.h"
#include "Track.h"
#include "Utils.h"

namespace AutoMixDataManagement {

	using namespace System;

	Track::Track()
	{
		Duration = 0;
		BPM = 0;
	}

	Track::Track(String^ path) : Track()
	{
		_path = path;
		_name = nameFromPath(path);
	}

	String^ Track::Name::get() 
	{
		return _name;
	}

	String^ Track::Path::get()
	{
		return _path;
	}

	String^ Track::displayDuration()
	{
		TimeSpan ts = TimeSpan::FromMilliseconds(Duration);
		String^ stringDuration = ts.ToString();
		int dotIndex = stringDuration->LastIndexOf(".");

		return stringDuration->Substring(0, dotIndex);
	}
}