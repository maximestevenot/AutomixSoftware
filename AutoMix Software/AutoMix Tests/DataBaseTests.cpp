#include "stdafx.h"
#include "DataBaseTests.h"

using namespace System;
using namespace System::IO;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace AutoMixDataManagement;

namespace DataManagementTests
{
	void DataBaseTests::dataBaseCreationTest()
	{
		String^ myDB = "myDataBase.db";

		DataBase^ db = gcnew DataBase(myDB);
		Assert::IsTrue(File::Exists(myDB));
	}
	void DataBaseTests::addValueTest()
	{
		String^ myDB = "myDataBase.db";
		DataBase^ db = gcnew DataBase(myDB);

		Track^ myTrack = gcnew Track("test.mp3");
		myTrack->BPM = 128;
		myTrack->Duration = 1000;
		myTrack->Key = "14";

		db->addTrack(myTrack);
	}
}