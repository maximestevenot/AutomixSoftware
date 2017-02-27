// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "TrackTests.h"

using namespace Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace AutoMixDataManagement;

void DataManagementTests::TrackTests::CopyfromTest()
{
	Track^ myTrack = gcnew Track("test.mp3");
	myTrack->BPM = 128;
	myTrack->Duration = 1000;
	myTrack->Key = "15";
	myTrack->Samplerate = 44100;
	myTrack->Danceability = 1.356555515;
	myTrack->Beats = gcnew array<unsigned int>{0, 1, 2};
	myTrack->FadeIns = gcnew array<unsigned int>{2, 3, 5};
	myTrack->FadeOuts = gcnew array<unsigned int>{3, 4, 6};

	Track^ copyTrack = Track::CopyFrom(myTrack);

	Assert::AreNotSame(myTrack, copyTrack);

	Assert::AreEqual(myTrack->Duration, copyTrack->Duration);
	Assert::AreEqual(myTrack->BPM, copyTrack->BPM);
	Assert::AreEqual(myTrack->Key, copyTrack->Key);
	Assert::AreEqual(myTrack->Samplerate, copyTrack->Samplerate);
	Assert::AreEqual(myTrack->Danceability, copyTrack->Danceability);
	for (int i = 0; i < 3; i++)
	{
		Assert::AreEqual(myTrack->Beats[i], copyTrack->Beats[i]);
		Assert::AreEqual(myTrack->FadeIns[i], copyTrack->FadeIns[i]);
		Assert::AreEqual(myTrack->FadeOuts[i], copyTrack->FadeOuts[i]);
	}
	Assert::AreNotSame(myTrack->Key, copyTrack->Key);
	Assert::AreNotSame(myTrack->Beats, copyTrack->Beats);
	Assert::AreNotSame(myTrack->Beats, copyTrack->Beats);
}
