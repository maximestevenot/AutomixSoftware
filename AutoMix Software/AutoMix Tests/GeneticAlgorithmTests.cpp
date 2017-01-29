#include "stdafx.h"
#include "GeneticAlgorithmTests.h"

using namespace System;
using namespace System::IO;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace AutoMixDataManagement;
using namespace AutoMixAI;

namespace GeneticAlgorithmTests
{
	void GeneticAlgorithmTestsClass::computeTracksDistanceTest()
	{
		Track^ track1 = gcnew Track("test.mp3");
		track1->BPM = 128;
		track1->Key = "6d";
		Track^ track2 = gcnew Track("test2.mp3");
		track1->BPM = 150;
		track1->Key = "6m";
		int distance = AutoMixAI::GeneticAlgorithm::computeTracksDistance(track1, track2);
		Assert::IsTrue(distance >= 0);
	}
	
}