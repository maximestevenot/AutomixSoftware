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
		_samplesPerSecond = AudioIO::WAVE_FORMAT->AverageBytesPerSecond / 4;
		_tempDirPath = System::IO::Path::GetTempPath() + "AutomixSoftware/";
		_tempWavPath = _tempDirPath + "AutoMix.wav";
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
		_overlaySize = value * AudioIO::WAVE_FORMAT->AverageBytesPerSecond / 4;
	}

	void SmoothMix::exportMix(ComponentModel::BackgroundWorker ^ bw, TrackCollection ^ collection, String ^ outputFile)
	{
		_savedOverlay = nullptr;
		_tempWavPath = _tempDirPath + "_automix_1.wav";
		_waveFileWriter = gcnew WaveFileWriter(_tempWavPath, AudioIO::WAVE_FORMAT);

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
			mergeTempFiles(bw, outputFile);
			bw->ReportProgress((int)(1000 * count++) / (collection->Count + 2));
		}
		deleteTempFiles();
	}

	void SmoothMix::mergeTempFiles(ComponentModel::BackgroundWorker^ bw, String^ outputFile)
	{
		//Stream^ outputStream = gcnew FileStream(outputFile, FileMode::Create);

		//Id3v2Tag^ tag = AudioIO::CreateId3v2Tag(outputFile);
		//outputStream->Write(tag->RawData, 0, tag->RawData->Length);

		AudioIO::WavToMp3(_tempFileList, outputFile, AudioIO::CreateID3TagData(outputFile));

		/*for each (auto path in _tempFileList)
		{
			if (bw->CancellationPending)
			{
				break;
			}

			Mp3FileReader^ reader = gcnew Mp3FileReader(path);
			Mp3Frame^ frame = nullptr;
			bool first = true;

			while ((frame = reader->ReadNextFrame()) != nullptr)
			{
				if (first)
				{
					int nbZeros = 0;
					for (int i = 0; i < frame->RawData->Length; i++)
					{
						if (frame->RawData[i].CompareTo(System::Convert::ToByte(10)) <= 0)
						{
							nbZeros++;
						}
					}
					if (nbZeros < frame->RawData->Length / 3)
					{
						first = false;
						outputStream->Write(frame->RawData, 0, frame->RawData->Length);
					}
				}
				else
				{
					outputStream->Write(frame->RawData, 0, frame->RawData->Length);
				}
			}
			outputStream->Flush();
			reader->Close();
		}
		outputStream->Close();*/
	}

	void AutoMixDataManagement::SmoothMix::fadeInOut(Track ^ track)
	{
		Mp3FileReader^ fileReader = gcnew Mp3FileReader(track->Path);

		FadeInOutSampleProvider^ fade = gcnew FadeInOutSampleProvider(WaveExtensionMethods::ToSampleProvider(fileReader), false);

		long bufferSize = fileReader->Length / 2 - track->getLastFadeOutDuration() * _samplesPerSecond;
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

		_tempWavPath = _tempDirPath + "_automix_" + (_tempFileList->Count + 1) + ".wav";
		_waveFileWriter = gcnew WaveFileWriter(_tempWavPath, AudioIO::WAVE_FORMAT);
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