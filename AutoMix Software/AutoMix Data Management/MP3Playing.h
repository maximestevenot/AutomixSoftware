// Copyright(C) 2016 - 2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#pragma once

namespace AutoMixDataManagement {
	public ref class MP3Playing
	{
	public:
		MP3Playing(System::String^);
		void play();
		void pause();
		void stop();

		__int64 getLength();
		__int64 getPosition();

		void seek(double seconds);

		void setPosition(long position);
		void setPosition(double seconds);
		void setPosition(System::TimeSpan time);

	private:
		NAudio::Wave::IWavePlayer^ _waveOutDevice = nullptr;
		NAudio::Wave::AudioFileReader^ _audioFileReader = nullptr;
	};
}

