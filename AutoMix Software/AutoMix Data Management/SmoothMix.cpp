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
		WAVE_FORMAT = WaveFormat::CreateIeeeFloatWaveFormat(44100, 2);
		_samplesPerSecond = WAVE_FORMAT->AverageBytesPerSecond / 4;
		_tempPath = System::IO::Path::GetTempPath() + "AutomixSoftware/";
		_tempWav = _tempPath + "AutoMix.wav";
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
		_overlaySize = value * WAVE_FORMAT->AverageBytesPerSecond / 4;;
	}

	void SmoothMix::exportMix(ComponentModel::BackgroundWorker ^ bw, TrackCollection ^ collection, String ^ outputFile)
	{
		_savedOverlay = nullptr;
		_waveFileWriter = gcnew WaveFileWriter(_tempWav, WAVE_FORMAT);

		int count = 1;
		int finalFileDuration = 0;
		for each (Track^ track in collection)
		{
			finalFileDuration += track->Duration;
			if (finalFileDuration >30000) {
				finalFileDuration = track->Duration;
				//TODO
				
				//sauvegarder le chemin du mp3 dans un tableau
				_tempFileList->Add(_tempPath + (_tempFileList->Count+1) +".mp3");
				_waveFileWriter->Flush();
				_waveFileWriter->Close();
				//exporter en mp3
				AudioIO::WavToMp3(_tempWav, _tempPath + (_tempFileList->Count) + ".mp3");
				
				try
				{
					//supprimer le wav
					System::IO::File::Delete(_tempWav);
					//creer un nouveau
					_waveFileWriter = gcnew WaveFileWriter(_tempWav, WAVE_FORMAT);
				}
				catch (System::IO::IOException^ e)
				{
					Console::WriteLine(e->Message);
					return;
				}

				
			}
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
			//Reconstruire le MP3 final
			

			Stream^ outputStream = gcnew FileStream(outputFile, FileMode::Create);
			int count = 1;

			Id3v2Tag^ tag = AudioIO::CreateMp3Tag(outputFile);
			outputStream->Write(tag->RawData, 0, tag->RawData->Length);

			for each (auto path in _tempFileList)
			{
				if (bw->CancellationPending)
				{
					break;
				}
				Mp3FileReader^ reader = gcnew Mp3FileReader(path);
				Mp3Frame^ frame;
				//TODO virer la putain d'en tete pour les musiques suivantes !!
				//SALE !!
				/*for (int i = 0; i < 50000;  i++) {
					reader->ReadNextFrame();
				}*/
				while ((frame = reader->ReadNextFrame()) != nullptr)
				{					
						outputStream->Write(frame->RawData, 0, frame->RawData->Length);

				}
			}
			outputStream->Close();



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