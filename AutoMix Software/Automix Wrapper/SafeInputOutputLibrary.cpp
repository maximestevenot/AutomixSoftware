// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "SafeInputOutputLibrary.h"
#include "SafeInputOutputException.h"

namespace AutoMixWrapper {

	using namespace System;
	using namespace System::Runtime::InteropServices;

	[DllImport(INPUT_OUTPUT_LIB, CharSet = CharSet::Ansi, EntryPoint = "wav_to_mp3")]
	extern "C" INPUTOUTPUTLIBRARY_API int wav_to_mp3(String ^ pSsourcefile, String ^ pDestinationfile);

	[DllImport(INPUT_OUTPUT_LIB, CharSet = CharSet::Auto, EntryPoint = "mp3_to_wav")]
	extern "C" INPUTOUTPUTLIBRARY_API int mp3_to_wav(String ^ pSsourcefile, String ^ pDestinationfile);

	void SafeInputOutputLibrary::wavToMp3(System::String ^ inputFile, System::String ^ outputFile)
	{
		int returnCode = wav_to_mp3(inputFile, outputFile);

		if (returnCode != 0)
		{
			throw gcnew SafeInputOutputException("wav_to_mp3 exited abnormally with code : " + returnCode);
		}

	}
	void SafeInputOutputLibrary::mp3ToWav(System::String ^ inputFile, System::String ^ outputFile)
	{
		int returnCode = mp3_to_wav(inputFile, outputFile);

		if (returnCode != 0)
		{
			throw gcnew SafeInputOutputException("mp3_to_wav exited abnormally with code : " + returnCode);
		}
	}
}