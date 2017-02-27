// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "GeneticSortAlgorithm.h"

using namespace System;
using namespace AutoMixDataManagement;

namespace AutoMixAI
{
	GeneticSortAlgorithm::GeneticSortAlgorithm(TrackDistance^ distance) : GeneticSortAlgorithm(distance, 175, 175, 85) {}

	GeneticSortAlgorithm::GeneticSortAlgorithm(TrackDistance^ distance, unsigned int numberOfIteration, unsigned int populationSize, double mutationProbabilty)
		: SortAlgorithm(distance)
	{
		NUMBER_OF_ITERATION = numberOfIteration;
		POPULATION_SIZE = populationSize;
		MUTATION_PROBABILITY = mutationProbabilty;
	}

	TrackCollection^ GeneticSortAlgorithm::sort(System::ComponentModel::BackgroundWorker^ bw, TrackCollection^ trackCollection)
	{
		Population^ pop = createInitialPopulation(trackCollection);
		sortPopulation(pop, 0, pop->Count - 1);

		for (int k = 0; k < NUMBER_OF_ITERATION; k++)
		{
			if (bw->CancellationPending)
			{
				break;
			}

			System::Diagnostics::Debug::WriteLine("iteration {0}", k);
			System::Diagnostics::Debug::WriteLine("premier {0}", computeIndividualEvaluation(pop[0]));
			System::Diagnostics::Debug::WriteLine("dernier {0}", computeIndividualEvaluation(pop[POPULATION_SIZE - 1]));

			createChildAndPutThemIntoPopulation(pop);
			mutatePopulation(pop);
			sortPopulation(pop, 0, pop->Count - 1);
			pop = pop->GetRange(0, POPULATION_SIZE);
			bw->ReportProgress((int)1000 * k / NUMBER_OF_ITERATION);
		}
		return pop[0];
	}

	Population^ GeneticSortAlgorithm::createInitialPopulation(TrackCollection^ trackCollection)
	{
		Population^ pop = gcnew Population();
		System::Random^ rand = gcnew System::Random();
		pop->Add(trackCollection);
		for (int k = 1; k < POPULATION_SIZE; k++)
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

	double GeneticSortAlgorithm::computeIndividualEvaluation(TrackCollection^ individual)
	{
		double result = 0;
		for (int k = 0; k < (individual->Count) - 1; k++)
		{
			result += Distance->compute(individual[k], individual[k + 1]);
			//result = result + computeTracksDistance(individual[k], individual[k + 1]);
		}
		return result;
	}

	void GeneticSortAlgorithm::sortPopulation(Population^ population, int begin, int end)
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

	void GeneticSortAlgorithm::createChildAndPutThemIntoPopulation(Population^ pop)
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

	TrackCollection^ GeneticSortAlgorithm::createChildrenFromParents(TrackCollection^ parent1, TrackCollection^ parent2)
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
					if ((!children->Contains(parent1[j])) && (!parent2->GetRange((parent1->Count) / 2, (parent1->Count) / 2)->Contains(parent1[j])))
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

	void GeneticSortAlgorithm::mutatePopulation(Population^ pop)
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
