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

	SmoothMix::SmoothMix() : SmoothMix(10) {}

	SmoothMix::SmoothMix(int transitionDuration)
	{
		WAVE_FORMAT = WaveFormat::CreateIeeeFloatWaveFormat(44100, 2);
		_samplesPerSecond = WAVE_FORMAT->AverageBytesPerSecond / 4;
		_tempPath = System::IO::Path::GetTempPath() + "AutomixSoftware/" + "AutoMix.wav";
		TransitionDuration = transitionDuration;
	}

	int SmoothMix::TransitionDuration::get()
	{
		return _transitionDuration;
	}

	void SmoothMix::TransitionDuration::set(int value)
	{
		_transitionDuration = value;
		_overlaySize = value * WAVE_FORMAT->AverageBytesPerSecond / 4;;
	}

	void SmoothMix::exportMix(ComponentModel::BackgroundWorker ^ bw, TrackCollection ^ collection, String ^ outputFile)
	{
		_savedOverlay = nullptr;
		_waveFileWriter = gcnew WaveFileWriter(_tempPath, WAVE_FORMAT);

		int count = 1;
		int memoryCount = 0;
		for each (Track^ track in collection)
		{
			if (bw->CancellationPending)
			{
				break;
			}
			bw->ReportProgress((int)(1000 * count++) / (collection->Count + 1));
			fadeInOut(track);
			memoryCount++;
			if (memoryCount > 9) {
				memoryCount = 0;
				//TODO
				//exporter en mp3
				//sauvegarder le chemin du mp3 dans un tableau
				//supprimer le wav
				//creer un nouveau wav
			}
			
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
		
		long bufferSize = fileReader->Length / 2 - track->getLastFadeOutDuration() * _samplesPerSecond;
		array<float>^ buffer = gcnew array<float>(bufferSize);

		fade->BeginFadeIn(_transitionDuration * 1000);
		fade->Read(buffer, 0, bufferSize - _overlaySize);
		fade->BeginFadeOut(_transitionDuration * 1000);
		fade->Read(buffer, bufferSize - _overlaySize, _overlaySize);

		if (_savedOverlay != nullptr)
		{
			buffer = applyOverlay(buffer, _savedOverlay);
		}

		_waveFileWriter->WriteSamples(buffer, 0, bufferSize - _overlaySize);
		_waveFileWriter->Flush();

		_savedOverlay = gcnew array<float>(_overlaySize);
		for (int i = 0; i < _overlaySize; i++)
		{
			_savedOverlay[i] = buffer[(bufferSize - _overlaySize) + i];
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