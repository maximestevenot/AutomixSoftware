// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#pragma once
#include "TrackCollection.h"

namespace AutoMixDataManagement {
	public ref class AudioIO
	{
	public:
		AudioIO();
		static void Mp3Export( TrackCollection^ trackCollection, System::ComponentModel::BackgroundWorker^ bw, System::String^ outputFile);
		static void TextExport(TrackCollection^ trackCollection, System::String^ outputFile);

		static void Mp3ToWav(System::String^ inputFile, System::String^ outputFile);
		static void WavToMp3(System::String^ inputFile, System::String^ outputFile);

		static System::String^ Mp3Md5Hash(Track^ track);

		static NAudio::Wave::Id3v2Tag^ CreateMp3Tag(System::String^ outputFile);
	};
}
