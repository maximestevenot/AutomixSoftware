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


	AudioIO::AudioIO()
	{
	}

	void AudioIO::Mp3Export( TrackCollection ^ trackCollection, System::ComponentModel::BackgroundWorker^ bw, String ^ outputFile)
	{
		List<String^>^ filesList = gcnew List<String^>();
		Stream^ outputStream = gcnew FileStream(outputFile, FileMode::Create);
		int cpt = 1;

		Id3v2Tag^ tag = CreateMp3Tag(outputFile);
		outputStream->Write(tag->RawData, 0, tag->RawData->Length);

		for each (auto track in trackCollection)
		{

			if (bw->CancellationPending)
			{
				break;
			}
			Mp3FileReader^ reader = gcnew Mp3FileReader(track->Path);
			Mp3Frame^ frame;

			while ((frame = reader->ReadNextFrame()) != nullptr)
			{
				outputStream->Write(frame->RawData, 0, frame->RawData->Length);
			}

			bw->ReportProgress((int)1000*cpt++ / trackCollection->Count);
		}
		outputStream->Close();
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
		int nbFrames = (int) reader->Length / 1152 / 4 / 1000;

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

	Id3v2Tag^ AudioIO::CreateMp3Tag(String^ outputFile)
	{

		Dictionary<String^, String^>^ tags = gcnew Dictionary<String^, String^>();
		tags->Add("TIT2", outputFile->Substring(outputFile->LastIndexOf("\\") + 1, outputFile->LastIndexOf(".mp3") - outputFile->LastIndexOf("\\") - 1));
		tags->Add("TPE1", Environment::UserName);
		tags->Add("TYER", DateTime::Now.Year.ToString());
		tags->Add("TSSE", "AutoMix Software with NAudio");
		tags->Add("COMM", "Created with AutoMix");
		Id3v2Tag^ tag = Id3v2Tag::Create(tags);
		return tag;
	}
}