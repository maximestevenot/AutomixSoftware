// ALL THOSE FUNCTIONS ARE PRIVATE NOW

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
	GeneticSortAlgorithm^ ga = gcnew GeneticSortAlgorithm();
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
	GeneticSortAlgorithm^ ga = gcnew GeneticSortAlgorithm();
	pop = ga->createInitialPopulation(tc);
	Assert::IsTrue(pop->Count == GeneticSortAlgorithm::POPULATION_SIZE);
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
	GeneticSortAlgorithm^ ga = gcnew GeneticSortAlgorithm();
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
	GeneticSortAlgorithm^ ga = gcnew GeneticSortAlgorithm();
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
	GeneticSortAlgorithm^ ga = gcnew GeneticSortAlgorithm();
	pop = ga->createInitialPopulation(tc);
	ga->createChildAndPutThemIntoPopulation(pop);
	Assert::IsTrue(pop->Count > GeneticSortAlgorithm::POPULATION_SIZE );
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
	GeneticSortAlgorithm^ ga = gcnew GeneticSortAlgorithm();
	pop = ga->createInitialPopulation(tc);
	ga->mutatePopulation(pop);
	Assert::IsTrue(pop->Count == GeneticSortAlgorithm::POPULATION_SIZE);
}
