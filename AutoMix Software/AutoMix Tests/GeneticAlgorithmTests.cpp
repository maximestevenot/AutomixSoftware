// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

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
		track2->BPM = 150;
		track2->Key = "6m";
		GeneticAlgorithm^ ga = gcnew GeneticAlgorithm();
		int distance = ga->computeTracksDistance(track1, track2);
		Assert::IsTrue(distance >= 0);
	}
	

	void GeneticAlgorithmTestsClass::computeIndividualEvaluationTest()
	{
		Track^ track1 = gcnew Track("test.mp3");
		track1->BPM = 128;
		track1->Key = "6d";
		Track^ track2 = gcnew Track("test2.mp3");
		track2->BPM = 150;
		track2->Key = "6m";
		TrackCollection^ tc = gcnew TrackCollection();
		tc->Add(track1);
		tc->Add(track2);
		GeneticAlgorithm^ ga = gcnew GeneticAlgorithm();
		int score = ga->computeIndividualEvaluation(tc);
		Assert::IsTrue(score >= 0);
	}

	

	void GeneticAlgorithmTestsClass::createInitialPopulationTest()
	{
		Track^ track1 = gcnew Track("test.mp3");
		track1->BPM = 128;
		track1->Key = "6d";
		Track^ track2 = gcnew Track("test2.mp3");
		track2->BPM = 150;
		track2->Key = "6m";
		TrackCollection^ tc = gcnew TrackCollection();
		tc->Add(track1);
		tc->Add(track2);
		System::Collections::Generic::List<TrackCollection^>^ pop;
		GeneticAlgorithm^ ga = gcnew GeneticAlgorithm();
		pop = ga->createInitialPopulation(tc);
		Assert::IsTrue(pop->Count == GeneticAlgorithm::POPULATION_SIZE);
		for (int k = 0; k < pop->Count; k++) {
			Assert::IsTrue((pop[k]->Contains(track1)) && (pop[k]->Contains(track2)));
		}
	}

	void GeneticAlgorithmTestsClass::sortPopulationTest()
	{
		Track^ track1 = gcnew Track("test.mp3");
		track1->BPM = 128;
		track1->Key = "6d";
		Track^ track2 = gcnew Track("test2.mp3");
		track2->BPM = 150;
		track2->Key = "6m";
		TrackCollection^ tc = gcnew TrackCollection();
		tc->Add(track1);
		tc->Add(track2);
		System::Collections::Generic::List<TrackCollection^>^ pop;
		GeneticAlgorithm^ ga = gcnew GeneticAlgorithm();
		pop = ga->createInitialPopulation(tc);
		ga->sortPopulation(pop, 0, pop->Count - 1);
		for(int k = 0;k<pop->Count-1;k++)
		{
			Assert::IsTrue(ga->computeIndividualEvaluation(pop[k]) <= ga->computeIndividualEvaluation(pop[k + 1]));
		}
	}

	void GeneticAlgorithmTestsClass::createChildrenFromParentsTest()
	{
		Track^ track1 = gcnew Track("test.mp3");
		track1->BPM = 128;
		track1->Key = "6d";
		Track^ track2 = gcnew Track("test2.mp3");
		track2->BPM = 150;
		track2->Key = "6m";
		TrackCollection^ tc = gcnew TrackCollection();
		tc->Add(track1);
		tc->Add(track2);
		Track^ track3 = gcnew Track("test.mp3");
		track3->BPM = 128;
		track3->Key = "6d";
		Track^ track4 = gcnew Track("test2.mp3");
		track4->BPM = 150;
		track4->Key = "6m";
		TrackCollection^ tc1 = gcnew TrackCollection();
		tc1->Add(track3);
		tc1->Add(track4);
		GeneticAlgorithm^ ga = gcnew GeneticAlgorithm();
		TrackCollection^ tc2 = ga->createChildrenFromParents(tc, tc1);
		Assert::IsTrue(tc2->Count == tc->Count);
		Assert::IsTrue(tc2->Contains(track1));
	}

	void GeneticAlgorithmTestsClass::createChildAndPutThemIntoPopulationTest()
	{
		Track^ track1 = gcnew Track("test.mp3");
		track1->BPM = 128;
		track1->Key = "6d";
		Track^ track2 = gcnew Track("test2.mp3");
		track2->BPM = 150;
		track2->Key = "6m";
		TrackCollection^ tc = gcnew TrackCollection();
		tc->Add(track1);
		tc->Add(track2);
		System::Collections::Generic::List<TrackCollection^>^ pop;
		GeneticAlgorithm^ ga = gcnew GeneticAlgorithm();
		pop = ga->createInitialPopulation(tc);
		ga->createChildAndPutThemIntoPopulation(pop);
		Assert::IsTrue(pop->Count > GeneticAlgorithm::POPULATION_SIZE );
	}

	void GeneticAlgorithmTestsClass::mutatePopulationTest()
	{
		Track^ track1 = gcnew Track("test.mp3");
		track1->BPM = 128;
		track1->Key = "6d";
		Track^ track2 = gcnew Track("test2.mp3");
		track2->BPM = 150;
		track2->Key = "6m";
		TrackCollection^ tc = gcnew TrackCollection();
		tc->Add(track1);
		tc->Add(track2);
		System::Collections::Generic::List<TrackCollection^>^ pop;
		GeneticAlgorithm^ ga = gcnew GeneticAlgorithm();
		pop = ga->createInitialPopulation(tc);
		ga->mutatePopulation(pop);
		Assert::IsTrue(pop->Count == GeneticAlgorithm::POPULATION_SIZE);
	}

	void GeneticAlgorithmTestsClass::sortTrackByGeneticAlgorithmTest()
	{
		Track^ track1 = gcnew Track("test.mp3");
		track1->BPM = 128;
		track1->Key = "6d";
		Track^ track2 = gcnew Track("test2.mp3");
		track2->BPM = 150;
		track2->Key = "6m";
		TrackCollection^ tc = gcnew TrackCollection();
		tc->Add(track1);
		tc->Add(track2);
		GeneticAlgorithm^ ga = gcnew GeneticAlgorithm();
		TrackCollection^ tc1 = ga->sortTrackByGeneticAlgorithm(gcnew ComponentModel::BackgroundWorker(), tc);
		Assert::IsTrue(tc1->Count == tc->Count);
	}
}