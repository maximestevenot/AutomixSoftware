// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "DataBaseTests.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace AutoMixDataManagement;

namespace DataManagementTests
{
	void DataBaseTests::dataBaseCreation()
	{
		String^ myDB = "myDataBase.sqlite";

		DataBase^ db = gcnew DataBase(myDB);
		Assert::IsTrue(File::Exists(myDB));
	}

	void DataBaseTests::addValueInDataBase()
	{
		String^ myDB = "myDataBase.sqlite";
		DataBase^ db = gcnew DataBase(myDB);

		Track^ myTrack = gcnew Track("test.mp3");
		myTrack->BPM = 128;
		myTrack->Duration = 1000;
		myTrack->Key = "14";

		db->addTrack(myTrack);
		db->addTrack(myTrack);
	}

	void DataBaseTests::clearDataBase()
	{
		String^ myDB = "myDataBase.sqlite";
		DataBase^ db = gcnew DataBase(myDB);

		Track^ myTrack = gcnew Track("test.mp3");
		myTrack->BPM = 128;
		myTrack->Duration = 1000;
		myTrack->Key = "15";

		db->addTrack(myTrack);
		db->clear();
	}

	void DataBaseTests::extractDataFromDataBase()
	{
		String^ myDB = "myDataBase.sqlite";
		DataBase^ db = gcnew DataBase(myDB);

		Track^ myTrack = gcnew Track("test.mp3");
		myTrack->BPM = 128;
		myTrack->Duration = 1000;
		myTrack->Key = "15";

		db->addTrack(myTrack);

		Track^ extractedTrack = gcnew Track("test.mp3");
		db->extractData(extractedTrack);

		Assert::AreEqual(myTrack->Duration, extractedTrack->Duration);
		Assert::AreEqual(myTrack->BPM, extractedTrack->BPM);
		Assert::AreEqual(myTrack->Key, extractedTrack->Key);
	}

	void DataBaseTests::isInDataBase() {
		String^ myDB = "myDataBase.sqlite";
		DataBase^ db = gcnew DataBase(myDB);

		Track^ myTrack = gcnew Track("test.mp3");
		myTrack->BPM = 128;
		myTrack->Duration = 1000;
		myTrack->Key = "15";
		db->clear();
		Assert::IsFalse(db->isInDataBase(myTrack));
		db->addTrack(myTrack);
		Assert::IsTrue(db->isInDataBase(myTrack));
	}
}