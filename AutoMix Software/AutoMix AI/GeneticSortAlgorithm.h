// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#pragma once

#include "SortAlgorithm.h"

namespace AutoMixAI
{
	typedef System::Collections::Generic::List<AutoMixDataManagement::TrackCollection^> Population;

	public ref class GeneticSortAlgorithm : public SortAlgorithm
	{
	public:
		static int NUMBER_OF_ITERATION = 150;
		static int POPULATION_SIZE = 200;
		static int MUTATION_PROBABILITY = 90; // Probabilty of mutation out of 100

		static int BPM_COEFFICIENT = 1200;
		static int KEY_NUMBER_COEFFICIENT = 30;
		static int KEY_TONALITY_COEFFICIENT = 800;
		static int DANCEABILITY_COEFFICIENT = 10;

		void sort(System::ComponentModel::BackgroundWorker^, AutoMixDataManagement::TrackCollection^) override;
		int computeTracksDistance(AutoMixDataManagement::Track^, AutoMixDataManagement::Track^);


	private:

		AutoMixDataManagement::TrackCollection^ GeneticSortAlgorithm::geneticSort(System::ComponentModel::BackgroundWorker^, AutoMixDataManagement::TrackCollection^);
		Population^ createInitialPopulation(AutoMixDataManagement::TrackCollection^);
		int computeIndividualEvaluation(AutoMixDataManagement::TrackCollection^);
		void sortPopulation(Population^, int, int);
		void createChildAndPutThemIntoPopulation(Population^);
		AutoMixDataManagement::TrackCollection^ createChildrenFromParents(AutoMixDataManagement::TrackCollection^, AutoMixDataManagement::TrackCollection^);
		void mutatePopulation(Population^);
	};


}

