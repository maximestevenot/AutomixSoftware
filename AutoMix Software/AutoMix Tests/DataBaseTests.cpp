#include "stdafx.h"
#include "DataBaseTests.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace AutoMixDataManagement;


namespace DataManagementTests
{
	void DataBaseTests::dataBaseCreationTest()
	{
		// TODO: Add your test code here
		Assert::AreEqual("toto", "toto");
	}
}