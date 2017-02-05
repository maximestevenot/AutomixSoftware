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