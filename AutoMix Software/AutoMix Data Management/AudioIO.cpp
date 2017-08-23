// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "AudioIO.h"

namespace AutoMixDataManagement {

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::IO;
	using namespace NAudio;
	using namespace NAudio::Wave;
	using namespace NAudio::Lame;
	using namespace System::Security::Cryptography;

	static AudioIO::AudioIO()
	{
		ExportQuality = NAudio::Lame::LAMEPreset::INSANE;
		WAV_FORMAT = NAudio::Wave::WaveFormat::CreateIeeeFloatWaveFormat(44100, 2);
	}

	WaveFormat^ AudioIO::TempWaveFormat::get()
	{
		return WaveFormat::CreateIeeeFloatWaveFormat(44100, 2);
	}

	void AudioIO::TextExport(TrackCollection ^ trackCollection, System::String ^ outputFile)
	{
		StreamWriter^ sw = gcnew StreamWriter(outputFile);
		sw->WriteLine("Playlist created with Automix Software");
		for each(auto t in trackCollection)
		{
			sw->WriteLine(t->Name + " | " + t->displayDuration() + " | " + t->BPM + " | " + t->Key);
		}
		sw->Flush();
		sw->Close();
	}

	void AudioIO::Mp3ToWav(String^ inputFile, String^ outputFile)
	{
		Mp3FileReader^ reader = gcnew Mp3FileReader(inputFile);
		WaveFileWriter::CreateWaveFile(outputFile, reader);
	}

	void AudioIO::WavToMp3(System::String ^ inputFile, System::String^ outputFile, ID3TagData^ id3Tag)
	{
		WaveFileReader^ reader = gcnew WaveFileReader(inputFile);
		LameMP3FileWriter^ writer = gcnew LameMP3FileWriter(outputFile, reader->WaveFormat, ExportQuality, id3Tag);

		reader->CopyTo(writer);
		reader->Close();
		writer->Flush();
		writer->Close();
	}

	void AudioIO::WavToMp3(System::String ^ inputFile, System::String^ outputFile)
	{
		WavToMp3(inputFile, outputFile, nullptr);
	}

	void AudioIO::WavToMp3(List <String^>^ inputFiles, System::String^ outputFile, ID3TagData^ id3Tag)
	{
		LameMP3FileWriter^ writer = gcnew LameMP3FileWriter(outputFile, TempWaveFormat, ExportQuality, id3Tag);

		for each (auto inputFile in inputFiles)
		{
			WaveFileReader^ reader = gcnew WaveFileReader(inputFile);
			reader->CopyTo(writer);
			reader->Close();
		}

		writer->Flush();
		writer->Close();
	}

	void AudioIO::WavToMp3(System::Collections::Generic::List<System::String^>^ inputFiles, System::String ^ outputFile)
	{
		WavToMp3(inputFiles, outputFile, nullptr);
	}


	System::String^ AudioIO::Mp3Md5Hash(String ^ path)
	{
		Mp3FileReader^ reader;
		try {
			reader = gcnew Mp3FileReader(path);
		}
		catch (InvalidOperationException^ ex)
		{
			System::Diagnostics::Debug::WriteLine(String::Format("Error when reading {0}", path));
			System::Diagnostics::Debug::WriteLine(ex->Message);
			return "";
		}
		Mp3Frame^ frame;
		array<Byte>^ audioData = gcnew array<Byte>(0);
		int readFrame = 0;
		int nbFrames = (int)reader->Length / 1152 / 4 / 1000 + 1;

		while ((frame = reader->ReadNextFrame()) != nullptr)
		{
			if (!readFrame)
			{
				int originalLength = audioData->Length;
				Array::Resize<Byte>(audioData, originalLength + frame->RawData->Length);
				Array::Copy(frame->RawData, 0, audioData, originalLength, frame->RawData->Length);
			}
			readFrame = (readFrame + 1) % nbFrames;
		}

		MD5^ md5Hash = MD5::Create();
		array<Byte>^ audioDataHash = md5Hash->ComputeHash(audioData);
		Text::StringBuilder^ sBuilder = gcnew Text::StringBuilder();

		for (int i = 0; i < audioDataHash->Length; i++)
		{
			sBuilder->Append(audioDataHash[i].ToString("x2"));
		}

		return sBuilder->ToString();
	}

	Id3v2Tag^ AudioIO::CreateId3v2Tag(String^ outputFile)
	{
		ID3TagData^ data = CreateID3TagData(outputFile);
		Dictionary<String^, String^>^ tags = gcnew Dictionary<String^, String^>();

		tags->Add("TIT2", data->Title);
		tags->Add("TPE1", data->Artist);
		tags->Add("TALB", data->Album);
		tags->Add("TCON", data->Genre);
		tags->Add("TYER", data->Year);
		tags->Add("TENC", "Automix Software with NAudio API");
		tags->Add("COMM", data->Comment);

		return Id3v2Tag::Create(tags);
	}

	ID3TagData^ AudioIO::CreateID3TagData(String^ outputFile)
	{
		ID3TagData^ tag = gcnew ID3TagData();
		tag->Title = outputFile->Substring(outputFile->LastIndexOf("\\") + 1, outputFile->LastIndexOf(".mp3") - outputFile->LastIndexOf("\\") - 1); //TIT2
		tag->Artist = Environment::UserName; //TPE1
		tag->Album = "Automix Software Compilation"; //TALB
		tag->Year = DateTime::Now.Year.ToString(); //TYER
		tag->Comment = "Created with Automix Software"; //COMM
		tag->Genre = "Mix"; //TCON
		return tag;
	}
}