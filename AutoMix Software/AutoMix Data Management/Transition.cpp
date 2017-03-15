#include "stdafx.h"
#include "Transition.h"
#include "AudioIO.h"
using namespace AutoMixDataManagement;
using namespace NAudio;
using namespace Wave;
using namespace SampleProviders;

Transition::Transition(TrackCollection^ trackCollection)
{
	_trackList = TrackCollection::CopyFrom(trackCollection);

}

void AutoMixDataManagement::Transition::makeTransition()
{
	Mp3FileReader^ reader;
	Track^ previousTrack = nullptr;
	for each (Track^ track in _trackList) {
		if (previousTrack) {
			fadeInOut(previousTrack, track);
		}
		else {
			fadeOut(track);
		}
		previousTrack = track;
	}
}

void AutoMixDataManagement::Transition::fadeIn(Track ^ track)
{
	_reader = gcnew Mp3FileReader(track->Path);
	FadeInOutSampleProvider^ fade = gcnew FadeInOutSampleProvider(_reader, false);
	fade->BeginFadeIn(10000);
}

void AutoMixDataManagement::Transition::fadeInOut(Track ^ track1, Track ^ track2)
{
	AudioFileReader^ reader1 = gcnew AudioFileReader(track1->Path);
	AudioFileReader^ reader2 = gcnew AudioFileReader(track2->Path);
	FadeInOutSampleProvider^ fade1= gcnew FadeInOutSampleProvider(reader1,false);
	FadeInOutSampleProvider^ fade2 = gcnew FadeInOutSampleProvider(reader2, false);
	fade1->BeginFadeOut(track1->Duration-10000);
	track1->Duration -= 10000;
	fade2->BeginFadeIn(10000*3);
	track2->Duration -= 10000;
}

void AutoMixDataManagement::Transition::fadeOut(Track ^ track)
{
	AudioFileReader^ reader = gcnew AudioFileReader(track->Path);
	FadeInOutSampleProvider^ fade = gcnew FadeInOutSampleProvider(reader, false);
	fade->BeginFadeOut(track->Duration-10000);
	track->Duration -= 10000;
}