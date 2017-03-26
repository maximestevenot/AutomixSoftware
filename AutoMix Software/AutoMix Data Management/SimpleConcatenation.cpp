// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "SimpleConcatenation.h"
#include "AudioIO.h"

namespace AutoMixDataManagement {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace NAudio;
	using namespace NAudio::Wave;
	using namespace NAudio::Lame;

	void SimpleConcatenation::exportMix(System::ComponentModel::BackgroundWorker ^ bw, TrackCollection ^ collection, System::String^ outputFile)
	{
		Stream^ outputStream = gcnew FileStream(outputFile, FileMode::Create);
		int count = 1;

		Id3v2Tag^ tag = AudioIO::CreateMp3Tag(outputFile);
		outputStream->Write(tag->RawData, 0, tag->RawData->Length);

		for each (auto track in collection)
		{
			if (bw->CancellationPending)
			{
				break;
			}
			Mp3FileReader^ reader = gcnew Mp3FileReader(track->Path);
			Mp3Frame^ frame;

			while ((frame = reader->ReadNextFrame()) != nullptr)
			{
				outputStream->Write(frame->RawData, 0, frame->RawData->Length);
			}
			reader->Close();
			outputStream->Flush();
			bw->ReportProgress((int)1000 * count++ / collection->Count);
		}
		outputStream->Close();
	}

}
