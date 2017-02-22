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
#include "AudioIO.h"

using namespace System;

namespace AutoMixDataManagement {

	Track::Track()
	{
		Duration = 0;
		BPM = 0;
		Key = "";
		Danceability = 0;
		Samplerate = 0;
		Beats = gcnew array<unsigned int>(1);
		FadeIns = gcnew array<unsigned int>(1);
		FadeOuts = gcnew array<unsigned int>(1);
		_id = TRACKS_COUNT++;
	}

	Track::Track(String^ path) : Track()
	{
		_path = path;
		_name = Utils::nameFromPath(path);
		_checksum = AudioIO::Mp3Md5Hash(this);
	}

	Track ^ Track::CopyFrom(Track ^ old)
	{
		Track^ newTrack = gcnew Track(String::Copy(old->Path));
		newTrack->Duration = old->Duration;
		newTrack->BPM = old->BPM;
		newTrack->Key = String::Copy(old->Key);
		newTrack->Danceability = old->Danceability;
		newTrack->Samplerate = old->Samplerate;
		newTrack->Beats = gcnew array<unsigned int>(old->Beats->Length);
		newTrack->FadeIns = gcnew array<unsigned int>(old->FadeIns->Length);
		newTrack->FadeOuts = gcnew array<unsigned int>(old->FadeOuts->Length);
		Array::Copy(old->Beats, newTrack->Beats, old->Beats->Length);
		Array::Copy(old->FadeIns, newTrack->FadeIns, old->FadeIns->Length);
		Array::Copy(old->FadeOuts, newTrack->FadeOuts, old->FadeOuts->Length);
		return newTrack;
	}

	String^ Track::Name::get() 
	{
		return _name;
	}

	String^ Track::Path::get()
	{
		return _path;
	}

	String^ Track::Checksum::get()
	{
		return _checksum;
	}

	unsigned int Track::Id::get()
	{
		return _id;
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