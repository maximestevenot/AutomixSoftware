#pragma once

using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace DataManagementTests {

	[TestClass]
	public ref class DataBaseTests
	{

	public:
		[TestMethod]
		void dataBaseCreationTest();
		
		[TestMethod]
		void addValueTest();
		
		[TestMethod]
		void clear();

		[TestMethod]
		void getTracks();

		[TestMethod]
		void extractDataTest();
	};
}