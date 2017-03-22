// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#pragma once

#include "AutoMixDataManagement.h"

namespace AutoMixDataManagement {

	public ref class SmoothMix : IExportation
	{
	public:
		SmoothMix();
		void exportMix(System::ComponentModel::BackgroundWorker^ bw, TrackCollection^ collection, System::String^ outputFile) override;

	private:
		NAudio::Wave::WaveFormat^ WAVE_FORMAT;
		System::String^ _tempPath;
		NAudio::Wave::WaveFileWriter^ _waveFileWriter;
		array<float>^ _savedOverlay;

		void fadeInOut(Track^ track);
		array<float>^ applyOverlay(array<float>^ trackBuffer, array<float>^ overlayBuffer);
	};

}