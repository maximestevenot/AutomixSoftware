// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "SmoothMix.h"
#include "AudioIO.h"

using namespace AutoMixDataManagement;
using namespace NAudio;
using namespace Wave;
using namespace SampleProviders;
using namespace System;
using namespace System::IO;

namespace AutoMixDataManagement {

	SmoothMix::SmoothMix()
	{
		WAVE_FORMAT = WaveFormat::CreateIeeeFloatWaveFormat(44100, 2);
		_tempPath = System::IO::Path::GetTempPath() + "AutomixSoftware/" + "AutoMix.wav";
	}

	void SmoothMix::exportMix(ComponentModel::BackgroundWorker ^ bw, TrackCollection ^ collection, String ^ outputFile)
	{
		_savedOverlay = nullptr;
		_waveFileWriter = gcnew WaveFileWriter(_tempPath, WAVE_FORMAT);

		int count = 1;
		for each (Track^ track in collection)
		{
			if (bw->CancellationPending)
			{
				break;
			}
			bw->ReportProgress((int)(1000 * count++) / (collection->Count + 1));
			fadeInOut(track);
		}

		_waveFileWriter->WriteSamples(_savedOverlay, 0, _savedOverlay->Length);
		_waveFileWriter->Flush();
		_waveFileWriter->Close();

		if (!bw->CancellationPending)
		{
			AudioIO::WavToMp3(_tempPath, outputFile);
			bw->ReportProgress((int)(1000 * count++) / (collection->Count + 1));
		}
	}

	void AutoMixDataManagement::SmoothMix::fadeInOut(Track ^ track)
	{
		Mp3FileReader^ fileReader = gcnew Mp3FileReader(track->Path);

		FadeInOutSampleProvider^ fade = gcnew FadeInOutSampleProvider(WaveExtensionMethods::ToSampleProvider(fileReader), false);
		int samplesPerSecond = WAVE_FORMAT->AverageBytesPerSecond / 4;

		long bufferSize = fileReader->Length / 2 - track->getLastFadeOutDuration() * samplesPerSecond;

		array<float>^ buffer = gcnew array<float>(bufferSize);

		fade->BeginFadeIn(10000);
		fade->Read(buffer, 0, bufferSize - 10 * samplesPerSecond);
		fade->BeginFadeOut(10000);
		fade->Read(buffer, bufferSize - 10 * samplesPerSecond, 10 * samplesPerSecond);

		if (_savedOverlay != nullptr)
		{
			buffer = applyOverlay(buffer, _savedOverlay);
		}

		_waveFileWriter->WriteSamples(buffer, 0, bufferSize - 10 * samplesPerSecond);
		_waveFileWriter->Flush();

		_savedOverlay = gcnew array<float>(10 * samplesPerSecond);
		for (int i = 0; i < (10 * samplesPerSecond); i++)
		{
			_savedOverlay[i] = buffer[(bufferSize - 10 * samplesPerSecond) + i];
		}
	}

	array<float>^ SmoothMix::applyOverlay(array<float>^ trackBuffer, array<float>^ overlayBuffer)
	{
		for (int i = 0; i < overlayBuffer->Length; i++)
		{
			trackBuffer[i] += overlayBuffer[i];
		}
		return trackBuffer;
	}

}