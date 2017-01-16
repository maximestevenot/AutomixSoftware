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
	namespace GeneticAlgorithm
	{
		typedef System::Collections::Generic::List<TrackCollection^> population;

		static int NUMBER_OF_ITERATION = 50;
		static int POPULATION_SIZE = 100;

		void sortTrackByGeneticAlgorithm(TrackCollection^);
		int computeTracksDistance(Track^, Track^);
		void createInitialPopulation(TrackCollection^, population^);
		int computeIndividualEvaluation(TrackCollection^);
	}
}

