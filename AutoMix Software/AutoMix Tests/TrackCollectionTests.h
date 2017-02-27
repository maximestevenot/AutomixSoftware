// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#pragma once

using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace DataManagementTests {

	[TestClass]
	public ref class TrackCollectionTests
	{
	public:
		[TestMethod]
		void safeAddTest();
		[TestMethod]
		void isPresentTest();
		[TestMethod]
		void searchTest();
		[TestMethod]
		void CopyfromTest();
		[TestMethod]
		void removeTest();
		[TestMethod]
		void nameSortTest();
		[TestMethod]
		void descNameSortTest();
		[TestMethod]
		void durationSortTest();
		[TestMethod]
		void descDurationSortTest();
		[TestMethod]
		void BPMSortTest();
		[TestMethod]
		void descBPMSortTest();
		[TestMethod]
		void purgeTest();
		[TestMethod]
		void concatTest();
	};

}