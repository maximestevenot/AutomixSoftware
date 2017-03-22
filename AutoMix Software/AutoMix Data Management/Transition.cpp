// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "Transition.h"
#include "AudioIO.h"

using namespace AutoMixDataManagement;
using namespace NAudio;
using namespace Wave;
using namespace SampleProviders;
using namespace System;

Transition::Transition(TrackCollection^ trackCollection)
{
	_trackList = TrackCollection::CopyFrom(trackCollection);
	_time = 0;
}

void AutoMixDataManagement::Transition::makeTransition()
{
	Track^ previousTrack = nullptr;
	for each (Track^ track in _trackList) {
		if (previousTrack) {
			fadeInOut(track);
		}
		else {
			fadeOut(track);
		}
		previousTrack = track;
	}

}

void AutoMixDataManagement::Transition::fadeIn(Track ^ track)
{
	Mp3FileReader^ fileReader = gcnew Mp3FileReader(track->Path);
	long size = (long)fileReader->Length /2;
	array<float>^ bytes = gcnew array<float>(size);

	FadeInOutSampleProvider^ fade = gcnew FadeInOutSampleProvider(WaveExtensionMethods::ToSampleProvider(fileReader), false);
	fade->BeginFadeIn(10000);
	fade->Read(bytes, 0, size);
	_waveFileWriter->WriteSamples(bytes, 0, size);
	_waveFileWriter->Flush();
}

void AutoMixDataManagement::Transition::fadeInOut(Track ^ track)
{

	Mp3FileReader^ fileReader = gcnew Mp3FileReader(track->Path);
	ISampleProvider^ sample = WaveExtensionMethods::ToSampleProvider(fileReader);
	long size = fileReader->Length /2;
	array<float>^ bytes = gcnew array<float>(size);
	FadeInOutSampleProvider^ fade = gcnew FadeInOutSampleProvider(WaveExtensionMethods::ToSampleProvider(fileReader), false);
	fade->BeginFadeIn(10000);
	int bytems = fade->WaveFormat->AverageBytesPerSecond/4;

	fade->Read(bytes, 0, size - 10* bytems);

	fade->BeginFadeOut(10000);

	fade->Read(bytes, size - 10* bytems, size);
	_waveFileWriter->WriteSamples(bytes, 0, size);
	_waveFileWriter->Flush();
}

void AutoMixDataManagement::Transition::fadeOut(Track ^ track)
{

	Mp3FileReader^ fileReader = gcnew Mp3FileReader(track->Path);

	_waveFileWriter = gcnew WaveFileWriter(System::IO::Path::GetTempPath() + "AutomixSoftware/" + "AutoMix.wav", fileReader->WaveFormat);
	long size = (long)fileReader->Length /2;
	
	array<float>^ bytes = gcnew array<float>(size);
	FadeInOutSampleProvider^ fade = gcnew FadeInOutSampleProvider(WaveExtensionMethods::ToSampleProvider(fileReader), false);
	int bytems = fade->WaveFormat->AverageBytesPerSecond/4;
	fade->Read(bytes, 0, size - 10*bytems);
	fade->BeginFadeOut(10000);

	fade->Read(bytes, size - 10* bytems, size);
	_waveFileWriter->WriteSamples(bytes, 0, size);
	_waveFileWriter->Flush();
}