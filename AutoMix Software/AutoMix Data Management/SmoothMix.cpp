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
using namespace System::Collections::Generic;

namespace AutoMixDataManagement {

	SmoothMix::SmoothMix() : SmoothMix(10) {}

	SmoothMix::SmoothMix(int transitionDuration)
	{
		_tempDirPath = System::IO::Path::GetTempPath() + "AutomixSoftware/";
		TransitionDuration = transitionDuration;
		_tempFileList = gcnew List<String^>();
	}

	int SmoothMix::TransitionDuration::get()
	{
		return _transitionDuration;
	}

	void SmoothMix::TransitionDuration::set(int value)
	{
		_transitionDuration = value;
		_overlaySize = value * SAMPLES_PER_SECOND;
	}

	void SmoothMix::exportMix(ComponentModel::BackgroundWorker ^ bw, TrackCollection ^ collection, String ^ outputFile)
	{
		_savedOverlay = nullptr;
		_tempWavPath = _tempDirPath + "automix_1.wav";
		_waveFileWriter = gcnew WaveFileWriter(_tempWavPath, AudioIO::TempWaveFormat);

		int count = 1;
		int tempFileDuration = 0;

		for each (Track^ track in collection)
		{
			if (bw->CancellationPending)
			{
				_waveFileWriter->Close();
				break;
			}
			tempFileDuration += track->Duration;

			if (tempFileDuration > 2700000) //45 minutes
			{
				tempFileDuration = track->Duration;
				createNewTempFile();
			}

			fadeInOut(track);
			bw->ReportProgress((int)(1000 * count++) / (collection->Count + 2));
		}

		if (!bw->CancellationPending)
		{
			finalizeLastTempWav();
			bw->ReportProgress((int)(1000 * count++) / (collection->Count + 2));
			AudioIO::WavToMp3(_tempFileList, outputFile, AudioIO::CreateID3TagData(outputFile));
			bw->ReportProgress((int)(1000 * count++) / (collection->Count + 2));
		}
		deleteTempFiles();
	}

	void AutoMixDataManagement::SmoothMix::fadeInOut(Track ^ track)
	{
		Mp3FileReader^ fileReader = gcnew Mp3FileReader(track->Path);

		FadeInOutSampleProvider^ fade = gcnew FadeInOutSampleProvider(WaveExtensionMethods::ToSampleProvider(fileReader), false);

		long bufferSize = fileReader->Length / 2 - track->getLastFadeOutDuration() * SAMPLES_PER_SECOND;
		if (bufferSize < _overlaySize)
		{
			bufferSize = _overlaySize;
		}

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

	void SmoothMix::createNewTempFile()
	{
		_waveFileWriter->Flush();
		_waveFileWriter->Close();

		_tempFileList->Add(_tempWavPath);

		_tempWavPath = _tempDirPath + "automix_" + (_tempFileList->Count + 1) + ".wav";
		_waveFileWriter = gcnew WaveFileWriter(_tempWavPath, AudioIO::TempWaveFormat);
	}

	void SmoothMix::finalizeLastTempWav()
	{
		_waveFileWriter->WriteSamples(_savedOverlay, 0, _savedOverlay->Length);
		_waveFileWriter->Flush();
		_waveFileWriter->Close();
		_tempFileList->Add(_tempWavPath);
	}

	array<float>^ SmoothMix::applyOverlay(array<float>^ trackBuffer, array<float>^ overlayBuffer)
	{
		for (int i = 0; i < overlayBuffer->Length; i++)
		{
			trackBuffer[i] += overlayBuffer[i];
		}
		return trackBuffer;
	}

	void SmoothMix::deleteTempFiles()
	{
		try
		{
			System::IO::File::Delete(_tempWavPath);
		}
		catch (System::IO::IOException^ e)
		{
			System::Diagnostics::Debug::WriteLine(e->Message);
		}

		for each (auto path in _tempFileList)
		{
			try
			{
				System::IO::File::Delete(path);
			}
			catch (System::IO::IOException^ e)
			{
				System::Diagnostics::Debug::WriteLine(e->Message);
			}
		}
	}

}