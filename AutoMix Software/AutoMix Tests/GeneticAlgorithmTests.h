// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#pragma once

using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace GeneticAlgorithmTests {

	[TestClass]
	public ref class GeneticAlgorithmTestsClass
	{

	public:
		[TestMethod]
		void computeTracksDistanceTest();

		[TestMethod]
		void createInitialPopulationTest();

		[TestMethod]
		void computeIndividualEvaluationTest();

		[TestMethod]
		void sortPopulationTest();

		[TestMethod]
		void createChildrenFromParentsTest();

		[TestMethod]
		void createChildAndPutThemIntoPopulationTest();

		[TestMethod]
		void mutatePopulationTest();

		[TestMethod]
		void sortTrackByGeneticAlgorithmTest();

		
	};
}