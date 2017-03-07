// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "MP3Playing.h"


namespace AutoMixDataManagement {

	using namespace System;
	using namespace NAudio;
	using namespace NAudio::Wave;

	MP3Playing::MP3Playing(String^ file)
	{
		_waveOutDevice = gcnew WaveOut();
		AudioFileReader^ audioFileReader = gcnew AudioFileReader(file);

		_waveOutDevice->Init(audioFileReader);
	}

	void MP3Playing::play()
	{
		_waveOutDevice->Play();
	}

	void MP3Playing::pause()
	{
		_waveOutDevice->Pause();
	}

	void MP3Playing::stop()
	{
		_waveOutDevice->Stop();
	}
}