// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#pragma once
#include "TrackCollection.h"

namespace AutoMixDataManagement {

	/// <summary>
	/// Provides some tools to manipulate audio files
	/// </summary>
	public ref class AudioIO
	{
	public:

		static initonly NAudio::Wave::WaveFormat^ WAVE_FORMAT = NAudio::Wave::WaveFormat::CreateIeeeFloatWaveFormat(44100, 2);

		/// <summary>
		/// Export a <c>TrackCollection</c> as text file containing all information
		/// </summary>
		/// <param name="trackCollection">The collection to export</param>
		/// <param name="outputFile">The path of the destination file</param>
		static void TextExport(TrackCollection^ trackCollection, System::String^ outputFile);

		/// <summary>
		/// Convert an MP3 into WAV file
		/// </summary>
		/// <param name="inputFile">The path of the MP3 file</param>
		/// <param name="outputFile">The path of the WAV file</param>
		static void Mp3ToWav(System::String^ inputFile, System::String^ outputFile);

		/// <summary>
		/// Convert a WAV into MP3 file
		/// </summary>
		/// <param name="inputFile">Input WAV files path</param>
		/// <param name="outputFile">Output MP3 file path</param>
		/// <param name="id3Tag">MP3 tags</param>
		static void WavToMp3(System::String^ inputFile, System::String^ outputFile, NAudio::Lame::ID3TagData^ id3Tag);

		/// <summary>
		/// Convert a WAV into MP3 file
		/// </summary>
		/// <param name="inputFile">Input WAV files path</param>
		/// <param name="outputFile">Output MP3 file path</param>
		static void WavToMp3(System::String^ inputFile, System::String^ outputFile);

		/// <summary>
		/// Concat a list of WAV in a MP3 file
		/// </summary>
		/// <param name="inputFiles">List of input WAV files paths</param>
		/// <param name="outputFile">Output MP3 file path</param>
		/// <param name="id3Tag">MP3 tags</param>
		static void WavToMp3(System::Collections::Generic::List <System::String^>^ inputFiles, System::String ^ outputFile, NAudio::Lame::ID3TagData^ id3Tag);

		/// <summary>
		/// Concat a list of WAV in a MP3 file
		/// </summary>
		/// <param name="inputFiles">List of input WAV files paths</param>
		/// <param name="outputFile">Output MP3 file path</param>
		static void WavToMp3(System::Collections::Generic::List <System::String^>^ inputFiles, System::String ^ outputFile);

		/// <summary>
		/// Compute the MD5 hash of an MP3 file
		/// </summary>
		/// <param name="path">The path of the MP3 file</param>
		/// <returns>The Hash in a <c>String^</c></returns>
		static System::String^ Mp3Md5Hash(System::String^ path);

		/// <summary>
		/// Create a <c>NAudio::Wave::Id3v2Tag</c> for a specified MP3 file
		/// </summary>
		/// <param name="path">The path of the MP3 file</param>
		/// <returns> A new <c>NAudio::Wave::Id3v2Tag^</c></returns>
		static NAudio::Wave::Id3v2Tag^ CreateId3v2Tag(System::String^ path);

		/// <summary>
		/// Create a <c>NAudio::Lame::ID3TagData</c> for a specified MP3 file
		/// </summary>
		/// <param name="path">The path of the MP3 file</param>
		/// <returns> A new <c>NAudio::Lame::ID3TagData^</c></returns>
		static NAudio::Lame::ID3TagData^ CreateID3TagData(System::String ^ outputFile);
	};
}
