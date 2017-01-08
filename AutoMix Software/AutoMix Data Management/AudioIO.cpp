#include "stdafx.h"
#include "AudioIO.h"

namespace AutoMixDataManagement {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace NAudio;
	using namespace NAudio::Wave;
	using namespace NAudio::Lame;

	AudioIO::AudioIO()
	{
	}

	void AudioIO::Mp3Export(TrackCollection ^ trackCollection, String ^ outputFile)
	{
		List<String^>^ filesList = gcnew List<String^>();
		Stream^ outputStrem = gcnew FileStream(outputFile, FileMode::Create);

		for each (auto track in trackCollection)
		{

			Mp3FileReader^ reader = gcnew Mp3FileReader(track->Path);

			if ((outputStrem->Position == 0) && (reader->Id3v2Tag != nullptr))
			{
				outputStrem->Write(reader->Id3v2Tag->RawData, 0, reader->Id3v2Tag->RawData->Length);
			}

			Mp3Frame^ frame;

			while ((frame = reader->ReadNextFrame()) != nullptr)
			{
				outputStrem->Write(frame->RawData, 0, frame->RawData->Length);
			}
		}
	}
	void AudioIO::TextExport(TrackCollection ^ trackCollection, System::String ^ outputFile)
	{
		StreamWriter^ sw = gcnew StreamWriter(outputFile);

		for each(auto t in trackCollection)
		{
			sw->WriteLine(t->Name);
		}

		sw->Close();
	}

	void AudioIO::Mp3ToWav(String^ inputFile, String^ outputFile)
	{
		Mp3FileReader^ reader = gcnew Mp3FileReader(inputFile);
		WaveFileWriter::CreateWaveFile(outputFile, reader);
	}

	void AudioIO::WavToMp3(System::String ^ inputFile, System::String ^ outputFile)
	{
		ID3TagData^ tag = gcnew ID3TagData(); //TODO add gestion of metadata

		WaveFileReader^ reader = gcnew WaveFileReader(inputFile);
		LameMP3FileWriter^ writer = gcnew LameMP3FileWriter(outputFile, reader->WaveFormat, 320, tag);
		reader->CopyTo(writer);
	}
}