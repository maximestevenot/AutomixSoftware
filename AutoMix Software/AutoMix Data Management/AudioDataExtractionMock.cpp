#include "stdafx.h"
#include "AudioDataExtractionMock.h"

using namespace System;

namespace AutoMixDataManagement {

	AudioDataExtractionMock::AudioDataExtractionMock()
	{
	}

	void AudioDataExtractionMock::setPath(String^ path)
	{
		_textFile = path + "\\samples.txt";
	}

	void AudioDataExtractionMock::extractBPM(Track^ track)
	{
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