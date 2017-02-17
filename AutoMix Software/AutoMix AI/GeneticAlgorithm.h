// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#pragma once

namespace AutoMixAI
{
	using namespace AutoMixDataManagement;
	typedef System::Collections::Generic::List<TrackCollection^> population;

	

	public ref class GeneticAlgorithm
	{
	public :
		static int NUMBER_OF_ITERATION = 150;
		static int POPULATION_SIZE = 200;
		static int MUTATION_PROBABILITY = 90; // Probabilty of mutation out of 100
		static int BPM_COEFFICIENT = 1200;
		static int KEY_NUMBER_COEFFICIENT = 30;
		static int KEY_TONALITY_COEFFICIENT = 800;
		static int DANCEABILITY_COEFFICIENT = 10;

		TrackCollection^ sortTrackByGeneticAlgorithm(System::ComponentModel::BackgroundWorker^, TrackCollection^);
		int computeTracksDistance(Track^, Track^);
		population^ createInitialPopulation(TrackCollection^);
		int computeIndividualEvaluation(TrackCollection^);
		void sortPopulation(population^, int, int);
		void createChildAndPutThemIntoPopulation(population^);
		TrackCollection^ createChildrenFromParents(TrackCollection^, TrackCollection^);
		void mutatePopulation(population^);
	};


}

