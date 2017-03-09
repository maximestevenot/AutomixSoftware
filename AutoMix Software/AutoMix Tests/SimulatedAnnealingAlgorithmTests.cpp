// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "SimulatedAnnealingAlgorithmTests.h"

using namespace System;
using namespace System::IO;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace AutoMixDataManagement;
using namespace AutoMixAI;

namespace SimulatedAnnealingAlgorithmTests {

	void SimulatedAnnealingAlgorithmTestsClass::sortTrackBySimulatedAnnealingAlgorithmTest() {
		Track^ track1 = gcnew Track("test.mp3");
		track1->BPM = 128;
		track1->Key = "6d";
		Track^ track2 = gcnew Track("test2.mp3");
		track2->BPM = 150;
		track2->Key = "6m";

		TrackCollection^ tc = gcnew TrackCollection();
		tc->Add(track1);
		tc->Add(track2);

		SimulatedAnnealingSortAlgorithm^ sa = gcnew SimulatedAnnealingSortAlgorithm(gcnew SimpleDistance());

		ComponentModel::BackgroundWorker^ bw = gcnew ComponentModel::BackgroundWorker();
		bw->WorkerReportsProgress = true;
		bw->WorkerSupportsCancellation = true;

		TrackCollection^ tc1 = sa->sort(bw, tc);
		Assert::IsTrue(tc1->Count == tc->Count);
	}
}