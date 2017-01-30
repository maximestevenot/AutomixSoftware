#include "stdafx.h"
#include "DataDelegateTests.h"

using namespace Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace AutoMixDataManagement;
using namespace System::IO;
using namespace System;

namespace DataManagementTests
{

	void DataDelegateTests::DelegateDataBaseTests()
	{
		String^ temppath = Path::GetTempPath() + "AutomixSoftware";
		DirectoryInfo^ tempDirectory;
		if (!Directory::Exists(temppath))
		{
			tempDirectory = Directory::CreateDirectory(temppath);
		}
		else
		{
			System::IO::Directory::Delete(temppath, true);
			tempDirectory = Directory::CreateDirectory(temppath);
		}
		DelegateAudioDataExtraction^ d = gcnew DelegateAudioDataExtraction(tempDirectory);

		Track^ myTrack = gcnew Track("test.mp3");
		myTrack->BPM = 128;
		myTrack->Duration = 1000;
		myTrack->Key = "14";

		DataBase^ db = gcnew DataBase();
		db->addTrack(myTrack);

		Track^ extractedTrack = gcnew Track("test.mp3");
		d->delegateExtraction(extractedTrack);

		Assert::AreEqual(myTrack->Duration, extractedTrack->Duration);
		Assert::AreEqual(myTrack->BPM, extractedTrack->BPM);
		Assert::AreEqual(myTrack->Key, extractedTrack->Key);
	}
}