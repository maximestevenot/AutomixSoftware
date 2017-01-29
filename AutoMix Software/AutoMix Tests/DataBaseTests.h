#pragma once

using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace DataManagementTests {

	[TestClass]
	public ref class DataBaseTests
	{

	public:
		[TestMethod]
		void dataBaseCreation();
		
		[TestMethod]
		void addValueInDataBase();
		
		[TestMethod]
		void clearDataBase();

		[TestMethod]
		void extractDataFromDataBase();
	};
}