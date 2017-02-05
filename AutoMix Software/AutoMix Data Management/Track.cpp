// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "Track.h"
#include "Utils.h"

namespace AutoMixDataManagement {

	using namespace System;

	Track::Track()
	{
		Duration = 0;
		BPM = 0;
		Key = "";
	}

	Track::Track(String^ path) : Track()
	{
		_path = path;
		_name = Utils::nameFromPath(path);
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

		if (dotIndex > 0)
		{
			stringDuration = stringDuration->Substring(0, dotIndex);
		}
		return stringDuration;
	}
}