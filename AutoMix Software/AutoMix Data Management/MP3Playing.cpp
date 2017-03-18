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
		_audioFileReader = gcnew AudioFileReader(file);

		_waveOutDevice->Init(_audioFileReader);
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
		setPosition(0.);
		delete _waveOutDevice;
		delete _audioFileReader;
	}

	__int64 MP3Playing::getLength()
	{
		return _audioFileReader->Length;
	}

	__int64 MP3Playing::getPosition()
	{
		return _audioFileReader->Position;
	}

	void MP3Playing::seek(double seconds)
	{
		_audioFileReader->Position = _audioFileReader->Position + (long)(seconds * _audioFileReader->WaveFormat->AverageBytesPerSecond);
	}

	void MP3Playing::setPosition(long position)
	{
		long adj = position % _audioFileReader->WaveFormat->BlockAlign;
		long newPos = (long) Math::Max((long long)0, Math::Min(_audioFileReader->Length,(long long) position - adj));
		_audioFileReader->Position = newPos;
	}

	void MP3Playing::setPosition(double seconds)
	{
		_audioFileReader->Position = (long)(seconds * _audioFileReader->WaveFormat->AverageBytesPerSecond);
	}

	void MP3Playing::setPosition(TimeSpan time)
	{
		_audioFileReader->Position = (__int64) time.TotalSeconds;
	}
}