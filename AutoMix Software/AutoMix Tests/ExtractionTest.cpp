// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "ExtractionTest.h"

using namespace Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace System;
using namespace System::IO;
using namespace AutoMixDataManagement;

namespace DataManagementTests
{
	void ExtractionTest::extractionCreationTest()
	{
		AudioDataExtraction^ db = gcnew AudioDataExtraction();
		Assert::IsTrue(Directory::Exists(Path::GetTempPath() + "AutomixSoftware"));
		Assert::IsTrue(File::Exists(Path::GetTempPath() + "AutomixSoftware\\profile.yaml"));
		
	}
	void ExtractionTest::keyConversionTest()
	{
		String^ myKey = Utils::convertToOpenKey("C", "major");
		Assert::AreEqual(myKey, "1d");
	}
}