// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#pragma once
#include "AutoMixDataManagement.h"
#include "AudioIO.h"

namespace AutoMixDataManagement {

	public ref class SmoothMix : IExportation
	{
	public:
		SmoothMix();
		SmoothMix(int);

		void exportMix(System::ComponentModel::BackgroundWorker^ bw, TrackCollection^ collection, System::String^ outputFile) override;
		property int TransitionDuration { int get(); void set(int); }

	private:
		void createNewTempFile();
		void finalizeLastTempWav();
		void deleteTempFiles();
		void fadeInOut(Track^ track);
		array<float>^ applyOverlay(array<float>^ trackBuffer, array<float>^ overlayBuffer);

		System::String^ _tempDirPath;
		System::String^ _tempWavPath;
		System::Collections::Generic::List <System::String^>^ _tempFileList;
		NAudio::Wave::WaveFileWriter^ _waveFileWriter;
		array<float>^ _savedOverlay;
		static initonly int SAMPLES_PER_SECOND = AudioIO::TempWaveFormat->AverageBytesPerSecond / 4;
		int _transitionDuration;
		int _overlaySize;
	};

}