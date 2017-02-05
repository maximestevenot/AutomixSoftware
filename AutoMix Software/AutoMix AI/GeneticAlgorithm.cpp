// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "GeneticAlgorithm.h"


namespace AutoMixAI
{
	TrackCollection^ GeneticAlgorithm::sortTrackByGeneticAlgorithm(System::ComponentModel::BackgroundWorker^ bw, TrackCollection^ trackCollection)
	{
		population^ pop = createInitialPopulation(trackCollection);
		sortPopulation(pop, 0, pop->Count-1);
		
		for (int k = 0; k < NUMBER_OF_ITERATION; k++)
		{
			if (bw->CancellationPending)
			{
				break;
			}
			System::Diagnostics::Debug::WriteLine("iteration {0}", k);
			System::Diagnostics::Debug::WriteLine("premier {0}", computeIndividualEvaluation(pop[0]));
			System::Diagnostics::Debug::WriteLine("dernier {0}", computeIndividualEvaluation(pop[POPULATION_SIZE-1]));
			createChildAndPutThemIntoPopulation(pop);
			mutatePopulation(pop);
			sortPopulation(pop, 0, pop->Count-1);
			pop = pop->GetRange(0, POPULATION_SIZE);
		}
		return pop[0];
	}

	int GeneticAlgorithm::computeTracksDistance(Track^ track1, Track^ track2)
	{
		unsigned int distance;

		bool major1 = track1->Key->Contains("d");
		bool major2 = track2->Key->Contains("d");
		System::String^ key2 = track2->Key->Substring(0, track2->Key->Length-1);
		System::String^ key1 = track1->Key->Substring(0, track1->Key->Length-1);
		double key1int = double::Parse(key1);
		double key2int = double::Parse(key2);

		distance = System::Math::Abs((int)(track2->BPM - track1->BPM)) * 10; //BPM 10 fois plus important que clé
		if (major1 == major2)
		{
			distance += (int) System::Math::Abs(key1int - key2int);
		}
		else
		{
			distance += 100;
		}
		return distance;
	}

	population^ GeneticAlgorithm::createInitialPopulation(TrackCollection^ trackCollection)
	{
		population^ pop = gcnew population();
		System::Random^ rand = gcnew System::Random();
		for (int k = 0; k < POPULATION_SIZE; k++)
		{
			TrackCollection^ individual = gcnew TrackCollection();
			for (int i = 0; i < trackCollection->Count; i++)
			{
				individual->Add(trackCollection[i]);
			}
			for (int i = 0; i < individual->Count; i++)
			{
				Track^ track = individual[i];
				individual->Remove(track);
				individual->Insert(rand->Next(individual->Count), track);
			}
			pop->Add(individual);
		}
		return pop;
	}

	int GeneticAlgorithm::computeIndividualEvaluation(TrackCollection^ individual)
	{
		int result = 0;
		for (int k = 0; k < (individual->Count) - 1; k++)
		{
			result = result + computeTracksDistance(individual[k], individual[k + 1]);
		}
		return result;
	}

	void GeneticAlgorithm::sortPopulation(population^ population, int begin, int end)
	{
		int i = begin;
		int j = end;
		TrackCollection^ temp;
		TrackCollection^ pivot = population[(i + j) / 2];

		while (i <= j)
		{
			while (computeIndividualEvaluation(population[i]) < computeIndividualEvaluation(pivot))
			{
				i++;
			}
			while (computeIndividualEvaluation(population[j]) > computeIndividualEvaluation(pivot))
			{
				j--;
			}
			if (i <= j)
			{
				temp = population[i];
				population[i] = population[j];
				population[j] = temp;
				i++;
				j--;
			}
		}
		if (begin < j)
		{
			sortPopulation(population, begin, j);
		}
		if (i < end)
		{
			sortPopulation(population, i, end);
		}
	}

	void GeneticAlgorithm::createChildAndPutThemIntoPopulation(population^ pop)
	{
		int count = pop->Count;
		for (int k = 0; k < count / 2; k++)
		{
			TrackCollection^ children1 = createChildrenFromParents(pop[k], pop[k + 1]);
			TrackCollection^ children2 = createChildrenFromParents(pop[k + 1], pop[k]);
			pop->Add(children1);
			pop->Add(children2);
		}
	}

	TrackCollection^ GeneticAlgorithm::createChildrenFromParents(TrackCollection^ parent1, TrackCollection^ parent2)
	{
		TrackCollection^ children = gcnew TrackCollection();
		for (int k = 0; k < (parent1->Count) / 2; k++)
		{
			children->Add(parent1[k]);
		}

		for (int i = (parent1->Count) / 2; i < parent1->Count; i++)
		{
			if (children->Contains(parent2[i]))
			{
				for (int j = 0; j < parent1->Count; j++)
				{
					if ((!children->Contains(parent1[j])) && (!parent2->GetRange((parent1->Count) / 2, (parent1->Count)/2)->Contains(parent1[j])))
					{
						children->Add(parent1[j]);
					}
				}
			}
			else
			{
				children->Add(parent2[i]);
			}
		}
		return children;
	}

	void GeneticAlgorithm::mutatePopulation(population^ pop)
	{
		System::Random^ rand = gcnew System::Random();
		for (int k = 0; k < pop->Count; k++)
		{
			
			if (rand->Next(100) < MUTATION_PROBABILITY)
			{
				TrackCollection^ mutant = pop[k];
				Track^ temp;
				
				int index1 = rand->Next(mutant->Count);
				int index2 = rand->Next(mutant->Count);
				temp = mutant[index1];
				mutant[index1] = mutant[index2];
				mutant[index2] = temp;
				pop[k] = mutant;
			}
		}

	}
}
