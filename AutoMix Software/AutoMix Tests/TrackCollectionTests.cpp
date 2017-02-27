// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "TrackCollectionTests.h"

using namespace Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace AutoMixDataManagement;

void DataManagementTests::TrackCollectionTests::safeAddTest()
{
	TrackCollection^ myCollection = gcnew TrackCollection();
	Track^ myTrack = gcnew Track("test.mp3");
	myTrack->BPM = 128;
	myTrack->Duration = 1000;
	myTrack->Key = "15";
	myTrack->Samplerate = 44100;
	myTrack->Danceability = 1.356555515;
	myTrack->Beats = gcnew array<unsigned int>{0, 1, 2};
	myTrack->FadeIns = gcnew array<unsigned int>{2, 3, 5};
	myTrack->FadeOuts = gcnew array<unsigned int>{3, 4, 6};

	Assert::AreEqual(myCollection->Count, 0);
	myCollection->safeAdd(myTrack);
	Assert::AreEqual(myCollection->Count, 1);
	myCollection->safeAdd(myTrack);
	Assert::AreEqual(myCollection->Count, 1);
}

void DataManagementTests::TrackCollectionTests::isPresentTest()
{
	TrackCollection^ myCollection = gcnew TrackCollection();
	Track^ myTrack = gcnew Track("test.mp3");
	myTrack->BPM = 128;
	myTrack->Duration = 1000;
	myTrack->Key = "15";
	myTrack->Samplerate = 44100;
	myTrack->Danceability = 1.356555515;
	myTrack->Beats = gcnew array<unsigned int>{0, 1, 2};
	myTrack->FadeIns = gcnew array<unsigned int>{2, 3, 5};
	myTrack->FadeOuts = gcnew array<unsigned int>{3, 4, 6};

	Assert::IsFalse(myCollection->isPresent(myTrack));
	myCollection->safeAdd(myTrack);
	Assert::IsTrue(myCollection->isPresent(myTrack));
}

void DataManagementTests::TrackCollectionTests::searchTest()
{
	TrackCollection^ myCollection = gcnew TrackCollection();
	Track^ myTrack = gcnew Track("test.mp3");
	myTrack->BPM = 128;
	myTrack->Duration = 1000;
	myTrack->Key = "15";
	myTrack->Samplerate = 44100;
	myTrack->Danceability = 1.356555515;
	myTrack->Beats = gcnew array<unsigned int>{0, 1, 2};
	myTrack->FadeIns = gcnew array<unsigned int>{2, 3, 5};
	myTrack->FadeOuts = gcnew array<unsigned int>{3, 4, 6};

	myCollection->safeAdd(myTrack);
	Track^ extractedTrack = myCollection->search("test.mp3");
	Assert::AreSame(extractedTrack, myTrack);
}

void DataManagementTests::TrackCollectionTests::CopyfromTest()
{
	TrackCollection^ myCollection = gcnew TrackCollection();
	Track^ myTrack = gcnew Track("test.mp3");
	myTrack->BPM = 128;
	myTrack->Duration = 1000;
	myTrack->Key = "15";
	myTrack->Samplerate = 44100;
	myTrack->Danceability = 1.356555515;
	myTrack->Beats = gcnew array<unsigned int>{0, 1, 2};
	myTrack->FadeIns = gcnew array<unsigned int>{2, 3, 5};
	myTrack->FadeOuts = gcnew array<unsigned int>{3, 4, 6};
	myCollection->safeAdd(myTrack);

	TrackCollection^ copyCollection = TrackCollection::CopyFrom(myCollection);

	Assert::AreNotSame(myCollection, copyCollection);
	Assert::AreNotSame(myCollection[0], copyCollection[0]);

	Assert::AreEqual(myCollection[0]->Duration, copyCollection[0]->Duration);
	Assert::AreEqual(myCollection[0]->BPM, copyCollection[0]->BPM);
	Assert::AreEqual(myCollection[0]->Key, copyCollection[0]->Key);
	Assert::AreEqual(myCollection[0]->Samplerate, copyCollection[0]->Samplerate);
	Assert::AreEqual(myCollection[0]->Danceability, copyCollection[0]->Danceability);
	for (int i = 0; i < 3; i++)
	{
		Assert::AreEqual(myCollection[0]->Beats[i], copyCollection[0]->Beats[i]);
		Assert::AreEqual(myCollection[0]->FadeIns[i], copyCollection[0]->FadeIns[i]);
		Assert::AreEqual(myCollection[0]->FadeOuts[i], copyCollection[0]->FadeOuts[i]);
	}
	Assert::AreNotSame(myCollection[0]->Key, copyCollection[0]->Key);
	Assert::AreNotSame(myCollection[0]->Beats, copyCollection[0]->Beats);
	Assert::AreNotSame(myCollection[0]->Beats, copyCollection[0]->Beats);
}

void DataManagementTests::TrackCollectionTests::removeTest()
{
	TrackCollection^ myCollection = gcnew TrackCollection();
	Track^ myTrack = gcnew Track("test.mp3");
	myTrack->BPM = 128;
	myTrack->Duration = 1000;
	myTrack->Key = "15";
	myTrack->Samplerate = 44100;
	myTrack->Danceability = 1.356555515;
	myTrack->Beats = gcnew array<unsigned int>{0, 1, 2};
	myTrack->FadeIns = gcnew array<unsigned int>{2, 3, 5};
	myTrack->FadeOuts = gcnew array<unsigned int>{3, 4, 6};

	myCollection->safeAdd(myTrack);
	myCollection->Remove("test.mp3");
	Assert::IsFalse(myCollection->isPresent(myTrack));
}

void DataManagementTests::TrackCollectionTests::nameSortTest()
{
	TrackCollection^ myCollection = gcnew TrackCollection();

	Track^ myTrack1 = gcnew Track("test1.mp3");
	myTrack1->BPM = 128;
	myTrack1->Duration = 1000;
	myTrack1->Key = "15";
	myTrack1->Samplerate = 44100;
	myTrack1->Danceability = 1.356555515;
	myTrack1->Beats = gcnew array<unsigned int>{0, 1, 2};
	myTrack1->FadeIns = gcnew array<unsigned int>{2, 3, 5};
	myTrack1->FadeOuts = gcnew array<unsigned int>{3, 4, 6};

	Track^ myTrack2 = gcnew Track("test2.mp3");
	myTrack2->BPM = 127;
	myTrack2->Duration = 1001;
	myTrack2->Key = "14";
	myTrack2->Samplerate = 44101;
	myTrack2->Danceability = 2.0455;
	myTrack2->Beats = gcnew array<unsigned int>{0, 2, 3};
	myTrack2->FadeIns = gcnew array<unsigned int>{2, 4, 5};
	myTrack2->FadeOuts = gcnew array<unsigned int>{1, 3, 6};

	Track^ myTrack3 = gcnew Track("test3.mp3");
	myTrack3->BPM = 126;
	myTrack3->Duration = 999;
	myTrack3->Key = "16";
	myTrack3->Samplerate = 44099;
	myTrack3->Danceability = 2.542;
	myTrack3->Beats = gcnew array<unsigned int>{1, 2, 3};
	myTrack3->FadeIns = gcnew array<unsigned int>{2, 4, 5};
	myTrack3->FadeOuts = gcnew array<unsigned int>{0, 5, 6};

	myCollection->safeAdd(myTrack2);
	myCollection->safeAdd(myTrack3);
	myCollection->safeAdd(myTrack1);
	myCollection->sortByName();
	Assert::IsTrue(myCollection[0]->Name->CompareTo(myCollection[1]->Name) < 0);
	Assert::IsTrue(myCollection[1]->Name->CompareTo(myCollection[2]->Name) < 0);
}

void DataManagementTests::TrackCollectionTests::descNameSortTest()
{
	TrackCollection^ myCollection = gcnew TrackCollection();

	Track^ myTrack1 = gcnew Track("test1.mp3");
	myTrack1->BPM = 128;
	myTrack1->Duration = 1000;
	myTrack1->Key = "15";
	myTrack1->Samplerate = 44100;
	myTrack1->Danceability = 1.356555515;
	myTrack1->Beats = gcnew array<unsigned int>{0, 1, 2};
	myTrack1->FadeIns = gcnew array<unsigned int>{2, 3, 5};
	myTrack1->FadeOuts = gcnew array<unsigned int>{3, 4, 6};

	Track^ myTrack2 = gcnew Track("test2.mp3");
	myTrack2->BPM = 127;
	myTrack2->Duration = 1001;
	myTrack2->Key = "14";
	myTrack2->Samplerate = 44101;
	myTrack2->Danceability = 2.0455;
	myTrack2->Beats = gcnew array<unsigned int>{0, 2, 3};
	myTrack2->FadeIns = gcnew array<unsigned int>{2, 4, 5};
	myTrack2->FadeOuts = gcnew array<unsigned int>{1, 3, 6};

	Track^ myTrack3 = gcnew Track("test3.mp3");
	myTrack3->BPM = 126;
	myTrack3->Duration = 999;
	myTrack3->Key = "16";
	myTrack3->Samplerate = 44099;
	myTrack3->Danceability = 2.542;
	myTrack3->Beats = gcnew array<unsigned int>{1, 2, 3};
	myTrack3->FadeIns = gcnew array<unsigned int>{2, 4, 5};
	myTrack3->FadeOuts = gcnew array<unsigned int>{0, 5, 6};

	myCollection->safeAdd(myTrack2);
	myCollection->safeAdd(myTrack3);
	myCollection->safeAdd(myTrack1);
	myCollection->sortByDescendingName();
	Assert::IsTrue(myCollection[0]->Name->CompareTo(myCollection[1]->Name) > 0);
	Assert::IsTrue(myCollection[1]->Name->CompareTo(myCollection[2]->Name) > 0);
}

void DataManagementTests::TrackCollectionTests::durationSortTest()
{
	TrackCollection^ myCollection = gcnew TrackCollection();

	Track^ myTrack1 = gcnew Track("test1.mp3");
	myTrack1->BPM = 128;
	myTrack1->Duration = 1000;
	myTrack1->Key = "15";
	myTrack1->Samplerate = 44100;
	myTrack1->Danceability = 1.356555515;
	myTrack1->Beats = gcnew array<unsigned int>{0, 1, 2};
	myTrack1->FadeIns = gcnew array<unsigned int>{2, 3, 5};
	myTrack1->FadeOuts = gcnew array<unsigned int>{3, 4, 6};

	Track^ myTrack2 = gcnew Track("test2.mp3");
	myTrack2->BPM = 127;
	myTrack2->Duration = 1001;
	myTrack2->Key = "14";
	myTrack2->Samplerate = 44101;
	myTrack2->Danceability = 2.0455;
	myTrack2->Beats = gcnew array<unsigned int>{0, 2, 3};
	myTrack2->FadeIns = gcnew array<unsigned int>{2, 4, 5};
	myTrack2->FadeOuts = gcnew array<unsigned int>{1, 3, 6};

	Track^ myTrack3 = gcnew Track("test3.mp3");
	myTrack3->BPM = 126;
	myTrack3->Duration = 999;
	myTrack3->Key = "16";
	myTrack3->Samplerate = 44099;
	myTrack3->Danceability = 2.542;
	myTrack3->Beats = gcnew array<unsigned int>{1, 2, 3};
	myTrack3->FadeIns = gcnew array<unsigned int>{2, 4, 5};
	myTrack3->FadeOuts = gcnew array<unsigned int>{0, 5, 6};

	myCollection->safeAdd(myTrack2);
	myCollection->safeAdd(myTrack3);
	myCollection->safeAdd(myTrack1);
	myCollection->sortByDuration();
	Assert::IsTrue(myCollection[0]->Duration < myCollection[1]->Duration);
	Assert::IsTrue(myCollection[1]->Duration < myCollection[2]->Duration);
}

void DataManagementTests::TrackCollectionTests::descDurationSortTest()
{
	TrackCollection^ myCollection = gcnew TrackCollection();

	Track^ myTrack1 = gcnew Track("test1.mp3");
	myTrack1->BPM = 128;
	myTrack1->Duration = 1000;
	myTrack1->Key = "15";
	myTrack1->Samplerate = 44100;
	myTrack1->Danceability = 1.356555515;
	myTrack1->Beats = gcnew array<unsigned int>{0, 1, 2};
	myTrack1->FadeIns = gcnew array<unsigned int>{2, 3, 5};
	myTrack1->FadeOuts = gcnew array<unsigned int>{3, 4, 6};

	Track^ myTrack2 = gcnew Track("test2.mp3");
	myTrack2->BPM = 127;
	myTrack2->Duration = 1001;
	myTrack2->Key = "14";
	myTrack2->Samplerate = 44101;
	myTrack2->Danceability = 2.0455;
	myTrack2->Beats = gcnew array<unsigned int>{0, 2, 3};
	myTrack2->FadeIns = gcnew array<unsigned int>{2, 4, 5};
	myTrack2->FadeOuts = gcnew array<unsigned int>{1, 3, 6};

	Track^ myTrack3 = gcnew Track("test3.mp3");
	myTrack3->BPM = 126;
	myTrack3->Duration = 999;
	myTrack3->Key = "16";
	myTrack3->Samplerate = 44099;
	myTrack3->Danceability = 2.542;
	myTrack3->Beats = gcnew array<unsigned int>{1, 2, 3};
	myTrack3->FadeIns = gcnew array<unsigned int>{2, 4, 5};
	myTrack3->FadeOuts = gcnew array<unsigned int>{0, 5, 6};

	myCollection->safeAdd(myTrack2);
	myCollection->safeAdd(myTrack3);
	myCollection->safeAdd(myTrack1);
	myCollection->sortByDescendingDuration();
	Assert::IsTrue(myCollection[0]->Duration > myCollection[1]->Duration);
	Assert::IsTrue(myCollection[1]->Duration > myCollection[2]->Duration);
}

void DataManagementTests::TrackCollectionTests::BPMSortTest()
{
	TrackCollection^ myCollection = gcnew TrackCollection();

	Track^ myTrack1 = gcnew Track("test1.mp3");
	myTrack1->BPM = 128;
	myTrack1->Duration = 1000;
	myTrack1->Key = "15";
	myTrack1->Samplerate = 44100;
	myTrack1->Danceability = 1.356555515;
	myTrack1->Beats = gcnew array<unsigned int>{0, 1, 2};
	myTrack1->FadeIns = gcnew array<unsigned int>{2, 3, 5};
	myTrack1->FadeOuts = gcnew array<unsigned int>{3, 4, 6};

	Track^ myTrack2 = gcnew Track("test2.mp3");
	myTrack2->BPM = 127;
	myTrack2->Duration = 1001;
	myTrack2->Key = "14";
	myTrack2->Samplerate = 44101;
	myTrack2->Danceability = 2.0455;
	myTrack2->Beats = gcnew array<unsigned int>{0, 2, 3};
	myTrack2->FadeIns = gcnew array<unsigned int>{2, 4, 5};
	myTrack2->FadeOuts = gcnew array<unsigned int>{1, 3, 6};

	Track^ myTrack3 = gcnew Track("test3.mp3");
	myTrack3->BPM = 126;
	myTrack3->Duration = 999;
	myTrack3->Key = "16";
	myTrack3->Samplerate = 44099;
	myTrack3->Danceability = 2.542;
	myTrack3->Beats = gcnew array<unsigned int>{1, 2, 3};
	myTrack3->FadeIns = gcnew array<unsigned int>{2, 4, 5};
	myTrack3->FadeOuts = gcnew array<unsigned int>{0, 5, 6};

	myCollection->safeAdd(myTrack2);
	myCollection->safeAdd(myTrack3);
	myCollection->safeAdd(myTrack1);
	myCollection->sortByBPM();
	Assert::IsTrue(myCollection[0]->BPM < myCollection[1]->BPM);
	Assert::IsTrue(myCollection[1]->BPM < myCollection[2]->BPM);
}

void DataManagementTests::TrackCollectionTests::descBPMSortTest()
{
	TrackCollection^ myCollection = gcnew TrackCollection();

	Track^ myTrack1 = gcnew Track("test1.mp3");
	myTrack1->BPM = 128;
	myTrack1->Duration = 1000;
	myTrack1->Key = "15";
	myTrack1->Samplerate = 44100;
	myTrack1->Danceability = 1.356555515;
	myTrack1->Beats = gcnew array<unsigned int>{0, 1, 2};
	myTrack1->FadeIns = gcnew array<unsigned int>{2, 3, 5};
	myTrack1->FadeOuts = gcnew array<unsigned int>{3, 4, 6};

	Track^ myTrack2 = gcnew Track("test2.mp3");
	myTrack2->BPM = 127;
	myTrack2->Duration = 1001;
	myTrack2->Key = "14";
	myTrack2->Samplerate = 44101;
	myTrack2->Danceability = 2.0455;
	myTrack2->Beats = gcnew array<unsigned int>{0, 2, 3};
	myTrack2->FadeIns = gcnew array<unsigned int>{2, 4, 5};
	myTrack2->FadeOuts = gcnew array<unsigned int>{1, 3, 6};

	Track^ myTrack3 = gcnew Track("test3.mp3");
	myTrack3->BPM = 126;
	myTrack3->Duration = 999;
	myTrack3->Key = "16";
	myTrack3->Samplerate = 44099;
	myTrack3->Danceability = 2.542;
	myTrack3->Beats = gcnew array<unsigned int>{1, 2, 3};
	myTrack3->FadeIns = gcnew array<unsigned int>{2, 4, 5};
	myTrack3->FadeOuts = gcnew array<unsigned int>{0, 5, 6};

	myCollection->safeAdd(myTrack2);
	myCollection->safeAdd(myTrack3);
	myCollection->safeAdd(myTrack1);
	myCollection->sortByDescendingBPM();
	Assert::IsTrue(myCollection[0]->BPM > myCollection[1]->BPM);
	Assert::IsTrue(myCollection[1]->BPM > myCollection[2]->BPM);
}

void DataManagementTests::TrackCollectionTests::purgeTest()
{
	TrackCollection^ myCollection = gcnew TrackCollection();

	Track^ myTrack1 = gcnew Track("test1.mp3");
	myTrack1->BPM = 0;
	myTrack1->Duration = 0;
	myTrack1->Key = "";
	myTrack1->Samplerate = 0;
	myTrack1->Danceability = 0;
	myTrack1->Beats = gcnew array<unsigned int>{0, 1, 2};
	myTrack1->FadeIns = gcnew array<unsigned int>{2, 3, 5};
	myTrack1->FadeOuts = gcnew array<unsigned int>{3, 4, 6};

	Track^ myTrack2 = gcnew Track("test2.mp3");
	myTrack2->BPM = 0;
	myTrack2->Duration = 1001;
	myTrack2->Key = "14";
	myTrack2->Samplerate = 44101;
	myTrack2->Danceability = 2.0455;
	myTrack2->Beats = gcnew array<unsigned int>{0, 2, 3};
	myTrack2->FadeIns = gcnew array<unsigned int>{2, 4, 5};
	myTrack2->FadeOuts = gcnew array<unsigned int>{1, 3, 6};

	myCollection->safeAdd(myTrack2);
	myCollection->safeAdd(myTrack1);
	myCollection->purge();
	Assert::IsTrue(myCollection->isPresent(myTrack2));
	Assert::IsFalse(myCollection->isPresent(myTrack1));
}

void DataManagementTests::TrackCollectionTests::concatTest()
{
	TrackCollection^ myCollection1 = gcnew TrackCollection();
	TrackCollection^ myCollection2 = gcnew TrackCollection();

	Track^ myTrack1 = gcnew Track("test1.mp3");
	myTrack1->BPM = 128;
	myTrack1->Duration = 1000;
	myTrack1->Key = "15";
	myTrack1->Samplerate = 44100;
	myTrack1->Danceability = 1.356555515;
	myTrack1->Beats = gcnew array<unsigned int>{0, 1, 2};
	myTrack1->FadeIns = gcnew array<unsigned int>{2, 3, 5};
	myTrack1->FadeOuts = gcnew array<unsigned int>{3, 4, 6};

	Track^ myTrack2 = gcnew Track("test2.mp3");
	myTrack2->BPM = 127;
	myTrack2->Duration = 1001;
	myTrack2->Key = "14";
	myTrack2->Samplerate = 44101;
	myTrack2->Danceability = 2.0455;
	myTrack2->Beats = gcnew array<unsigned int>{0, 2, 3};
	myTrack2->FadeIns = gcnew array<unsigned int>{2, 4, 5};
	myTrack2->FadeOuts = gcnew array<unsigned int>{1, 3, 6};

	Track^ myTrack3 = gcnew Track("test3.mp3");
	myTrack3->BPM = 126;
	myTrack3->Duration = 999;
	myTrack3->Key = "16";
	myTrack3->Samplerate = 44099;
	myTrack3->Danceability = 2.542;
	myTrack3->Beats = gcnew array<unsigned int>{1, 2, 3};
	myTrack3->FadeIns = gcnew array<unsigned int>{2, 4, 5};
	myTrack3->FadeOuts = gcnew array<unsigned int>{0, 5, 6};

	myCollection1->safeAdd(myTrack2);
	myCollection2->safeAdd(myTrack3);
	myCollection2->safeAdd(myTrack1);
	myCollection1->concat(myCollection2);
	Assert::IsTrue(myCollection1->isPresent(myTrack1));
	Assert::IsTrue(myCollection1->isPresent(myTrack2));
	Assert::IsTrue(myCollection1->isPresent(myTrack3));
}
