// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "AudioDataExtractionMock.h"

using namespace System;

namespace AutoMixDataManagement {

	AudioDataExtractionMock::AudioDataExtractionMock()
	{
	}

	void AudioDataExtractionMock::setPath(Track^ track)
	{
		_textFile = track->Path->Substring(0, track->Path->LastIndexOf("\\")) + "\\samples.txt";
	}

	void AudioDataExtractionMock::extractBPM(Track^ track)
	{
		if (_textFile == "")
		{
			setPath(track);
		}
		IO::StreamReader ^ reader = gcnew IO::StreamReader(_textFile);
		if (!reader)
		{
			throw "Path to data mock not set or cannot open text file.";
		}
		do
		{
			String^ line = reader->ReadLine();
			int nameSize = line->LastIndexOf(".mp3") + 4;
			if (track->Name->Contains(line->Substring(0, nameSize)))
			{
				line = line->Substring(nameSize + 1);
				track->BPM = Convert::ToInt32(line->Split(gcnew array<wchar_t>{ ' ', '\n', '\r'})[1]);
			}
		} while (reader->Peek() >= 0);
		reader->Close();
	}

	void AudioDataExtractionMock::extractBPM(TrackCollection^ trackCollection)
	{
		if (_textFile == "")
		{
			setPath(trackCollection[0]);
		}
		IO::StreamReader ^ reader = gcnew IO::StreamReader(_textFile);
		if (!reader)
		{
			throw "Path to data mock not set or cannot open text file.";
		}
		do
		{
			String^ line = reader->ReadLine();
			int nameSize = line->LastIndexOf(".mp3") + 4;
			Track^ t = trackCollection->searchByName(line->Substring(0, nameSize));
			line = line->Substring(nameSize + 1);
			t->BPM = Convert::ToInt32(line->Split(gcnew array<wchar_t>{ ' ', '\n', '\r'})[1]);
		} while (reader->Peek() >= 0);
		reader->Close();
	}

	void AudioDataExtractionMock::extractDuration(Track^ track)
	{
		if (_textFile == "")
		{
			setPath(track);
		}
		IO::StreamReader ^ reader = gcnew IO::StreamReader(_textFile);
		if (!reader)
		{
			throw "Path to data mock not set or cannot open text file.";
		}
		do
		{
			String^ line = reader->ReadLine();
			int nameSize = line->LastIndexOf(".mp3") + 4;
			if (track->Name->Contains(line->Substring(0, nameSize)))
			{
				line = line->Substring(nameSize + 1);
				track->Duration = Convert::ToInt32(line->Split(gcnew array<wchar_t>{ ' ', '\n', '\r'})[0]);
			}
		} while (reader->Peek() >= 0);
		reader->Close();
	}

	void AudioDataExtractionMock::extractDuration(TrackCollection^ trackCollection)
	{
		if (_textFile == "")
		{
			setPath(trackCollection[0]);
		}
		IO::StreamReader ^ reader = gcnew IO::StreamReader(_textFile);
		if (!reader)
		{
			throw "Path to data mock not set or cannot open text file.";
		}
		do
		{
			String^ line = reader->ReadLine();
			int nameSize = line->LastIndexOf(".mp3") + 4;
			Track^ t = trackCollection->searchByName(line->Substring(0, nameSize));
			line = line->Substring(nameSize + 1);
			t->Duration = Convert::ToInt32(line->Split(gcnew array<wchar_t>{ ' ', '\n', '\r'})[0]);
		} while (reader->Peek() >= 0);
		reader->Close();
	}

	void AudioDataExtractionMock::extractKey(Track^ track)
	{
		if (_textFile == "")
		{
			setPath(track);
		}
		IO::StreamReader ^ reader = gcnew IO::StreamReader(_textFile);
		if (!reader)
		{
			throw "Path to data mock not set or cannot open text file.";
		}
		do
		{
			String^ line = reader->ReadLine();
			int nameSize = line->LastIndexOf(".mp3") + 4;
			if (track->Name->Contains(line->Substring(0, nameSize)))
			{
				line = line->Substring(nameSize + 1);
				track->Key = line->Split(gcnew array<wchar_t>{ ' ', '\n', '\r'})[2];
			}
		} while (reader->Peek() >= 0);
		reader->Close();
	}

	void AudioDataExtractionMock::extractKey(TrackCollection^ trackCollection)
	{
		if (_textFile == "")
		{
			setPath(trackCollection[0]);
		}
		IO::StreamReader ^ reader = gcnew IO::StreamReader(_textFile);
		if (!reader)
		{
			throw "Path to data mock not set or cannot open text file.";
		}
		do
		{
			String^ line = reader->ReadLine();
			int nameSize = line->LastIndexOf(".mp3") + 4;
			Track^ t = trackCollection->searchByName(line->Substring(0, nameSize));
			line = line->Substring(nameSize + 1);
			t->Key = line->Split(gcnew array<wchar_t>{ ' ', '\n', '\r'})[2];
		} while (reader->Peek() >= 0);
		reader->Close();
	}
}