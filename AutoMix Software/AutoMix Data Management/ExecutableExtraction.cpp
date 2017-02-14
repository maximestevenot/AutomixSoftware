// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "ExecutableExtraction.h"

using namespace System::Collections::Generic;
using namespace System::Threading::Tasks;
using namespace System::Diagnostics;
using namespace System::IO;
using namespace System;
using namespace Newtonsoft::Json;

namespace AutoMixDataManagement {

	ExecutableExtraction::ExecutableExtraction(System::IO::DirectoryInfo^ tempDirectory)
	{
		_tempDirectory = tempDirectory;

		String^ extractorpath = Directory::GetCurrentDirectory() + "\\essentia_streaming_extractor_music.exe";

		_startInfo = gcnew ProcessStartInfo(extractorpath);
		_startInfo->UseShellExecute = false;
		_startInfo->WorkingDirectory = _tempDirectory->FullName;
		_startInfo->WindowStyle = ProcessWindowStyle::Hidden;
		_startInfo->CreateNoWindow = true;

		extractorpath = Directory::GetCurrentDirectory() + "\\essentia_standard_fadedetection.exe";
		_startInfoFade = gcnew ProcessStartInfo(extractorpath);
		_startInfoFade->UseShellExecute = false;
		_startInfoFade->WorkingDirectory = _tempDirectory->FullName;
		_startInfoFade->WindowStyle = ProcessWindowStyle::Hidden;
		_startInfoFade->CreateNoWindow = true;
		_startInfoFade->RedirectStandardOutput = true;
	}

	void ExecutableExtraction::extractData(System::ComponentModel::BackgroundWorker^ bw, int nbTracks, System::Threading::CancellationTokenSource^ cts, Track ^ track)
	{
		_startInfo->Arguments = "\"" + track->Path + "\" \"" + track->Id + ".json\" \"" + _tempDirectory->FullName + "\\profile.yaml\"";
		Process^ extractor = gcnew Process;
		extractor->StartInfo = _startInfo;
		extractor->Start();
		while (!bw->CancellationPending && !extractor->HasExited)
		{
			System::Threading::Thread::Sleep(100);
		}
		if (bw->CancellationPending && !extractor->HasExited)
		{
			extractor->Kill();
			cts->Cancel();
		}
		else if (!bw->CancellationPending)
		{
			Threading::Thread::Sleep(50);

			try
			{
				StreamReader^ file = File::OpenText(_tempDirectory->FullName + "\\" + track->Id + ".json");
				JsonTextReader^ reader = gcnew JsonTextReader(file);
				Linq::JObject^ obj = (Linq::JObject^)Linq::JToken::ReadFrom(reader);

				track->Duration = Convert::ToUInt32((double)obj["metadata"]["audio_properties"]["length"] * 1000);
				track->BPM = Convert::ToUInt32((int)(obj["rhythm"]["bpm"]));

				String^ key = (String^)(obj["tonal"]["key_key"]);
				String^ scale = (String^)(obj["tonal"]["key_scale"]);
				track->Key = Utils::convertToOpenKey(key, scale);

				track->Danceability = Convert::ToDouble((double)obj["rhythm"]["danceability"]);
				track->Samplerate = Convert::ToUInt32((int)(obj["metadata"]["audio_properties"]["sample_rate"]));

				Linq::JArray^ beats = Linq::JArray::FromObject(obj["rhythm"]["beats_position"]);
				List<double>^ doublebeatlist = beats->ToObject<List<double>^>();
				List<unsigned int>^ beatlist = doublebeatlist->ConvertAll<unsigned int>(gcnew Converter<double, unsigned int>(DoubleToUIntLists));
				array<unsigned int>^ beatarray = gcnew array<unsigned int>(beatlist->Count);
				beatlist->CopyTo(beatarray);
				track->Beats = beatarray;

				reader->Close();
				file->Close();
			}
			catch (FileNotFoundException^ e)
			{
				e->Message;
			}
		}

		if (!bw->CancellationPending)
		{
			_startInfoFade->Arguments = "\"" + track->Path + "\"";
			Process^ fadeExtractor = gcnew Process;
			fadeExtractor->StartInfo = _startInfoFade;
			fadeExtractor->Start();

			StreamReader^ reader = fadeExtractor->StandardOutput;
			String^ output = reader->ReadToEnd();

			while (!bw->CancellationPending && !fadeExtractor->HasExited)
			{
				System::Threading::Thread::Sleep(100);
			}
			if (bw->CancellationPending && !fadeExtractor->HasExited)
			{
				fadeExtractor->Kill();
				cts->Cancel();
			}
			else if (!bw->CancellationPending)
			{
				Threading::Thread::Sleep(100);

				int in = output->IndexOf("fade ins:");
				int out = output->IndexOf("fade outs:");
				array<Char>^ sep = gcnew array<Char>{ ' ', ',', '[', ']', '\n' };
				System::Collections::Generic::List<unsigned int>^ fadeInList = gcnew System::Collections::Generic::List<unsigned int>();
				if (in == -1)
				{
					fadeInList->Add(0);
				}
				else
				{
					int upperBound;
					if (out == -1)
					{
						upperBound = output->Length;
					}
					else
					{
						upperBound = out;
					}
					String^ subIn = output->Substring(in + 9, upperBound-in);
					array<String^>^ valuesIn = subIn->Split(sep, StringSplitOptions::RemoveEmptyEntries);
					for each (String^ value in valuesIn)
					{
						double number;
						if (Double::TryParse(value, Globalization::NumberStyles::Number, Globalization::CultureInfo::CreateSpecificCulture("en-US"), number))
						{
							fadeInList->Add((int)(number * 1000));
						}
					}
				}
				array<unsigned int>^ FadeInArray = gcnew array<unsigned int>(fadeInList->Count);
				fadeInList->CopyTo(FadeInArray);
				track->FadeIns = FadeInArray;

				System::Collections::Generic::List<unsigned int>^ fadeOutList = gcnew System::Collections::Generic::List<unsigned int>();
				if (out == -1)
				{
					fadeOutList->Add(track->Duration);
				}
				else
				{
					String^ subOut = output->Substring(out + 10);
					array<String^>^ valuesOut = subOut->Split(sep, StringSplitOptions::RemoveEmptyEntries);
					for each (String^ value in valuesOut)
					{
						double number;
						if (Double::TryParse(value, Globalization::NumberStyles::Number, Globalization::CultureInfo::CreateSpecificCulture("en-US"), number))
						{
							fadeOutList->Add((int)(number * 1000));
						}
					}
				}
				array<unsigned int>^ FadeOutArray = gcnew array<unsigned int>(fadeOutList->Count);
				fadeOutList->CopyTo(FadeOutArray);
				track->FadeOuts = FadeOutArray;

				if (track->BPM > 0 && track->Duration > 0)
				{
					DataBase^ db = gcnew DataBase();
					db->addTrack(track);
				}
			}
			reader->Close();
		}
		bw->ReportProgress((int)1000 / nbTracks);
	}

	unsigned int ExecutableExtraction::DoubleToUIntLists(double old)
	{
		return (int)(old * 1000);
	}

}