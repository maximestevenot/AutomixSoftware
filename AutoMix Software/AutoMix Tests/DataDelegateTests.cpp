// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "DataDelegateTests.h"

using namespace Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace AutoMixDataManagement;
using namespace System::IO;
using namespace System::Threading;
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

		ComponentModel::BackgroundWorker^ bw = gcnew ComponentModel::BackgroundWorker();
		bw->WorkerReportsProgress = true;
		bw->WorkerSupportsCancellation = true;
		DelegateAudioDataExtraction^ d = gcnew DelegateAudioDataExtraction(bw, 1, gcnew CancellationTokenSource(), tempDirectory);

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