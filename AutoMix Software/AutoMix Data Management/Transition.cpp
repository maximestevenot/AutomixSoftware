#include "stdafx.h"
#include "Transition.h"
#include "AudioIO.h"
using namespace AutoMixDataManagement;
using namespace NAudio;
using namespace Wave;
using namespace SampleProviders;

Transition::Transition()
{
	_trackList = TrackCollection::CopyFrom(_trackList); //TODO

}

void AutoMixDataManagement::Transition::createFile(System::String ^ outputFile)
{
	Mp3FileReader^ reader;
	for (Track^ track : _trackList) {
		reader = gcnew Mp3FileReader(track->Path);

	}
}

void AutoMixDataManagement::Transition::fadeIn(Track ^ track1, Track ^ track2)
{
	AudioFileReader^ reader1 = gcnew AudioFileReader(track1->Path);
	AudioFileReader^ reader2 = gcnew AudioFileReader(track2->Path);
	FadeInOutSampleProvider^ fade1= gcnew FadeInOutSampleProvider(reader1,false);
	FadeInOutSampleProvider^ fade2 = gcnew FadeInOutSampleProvider(reader2, true);
	fade1->BeginFadeOut(track1->Duration-10000);
	fade2->BeginFadeOut(10000);

}

void AutoMixDataManagement::Transition::fadeOut(Track ^ track1, Track ^ track2)
{
	throw gcnew System::NotImplementedException();
}
