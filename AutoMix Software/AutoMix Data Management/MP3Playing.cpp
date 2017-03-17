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
		SetPosition(_audioFileReader, 0.);
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

	void MP3Playing::SetPosition(NAudio::Wave::WaveStream ^ strm, long position)
	{
		long adj = position % strm->WaveFormat->BlockAlign;
		long newPos = (long) Math::Max((long long)0, Math::Min(strm->Length,(long long) position - adj));
		strm->Position = newPos;
	}

	void MP3Playing::SetPosition(NAudio::Wave::WaveStream ^ strm, double seconds)
	{
		strm->Position = (long)(seconds * strm->WaveFormat->AverageBytesPerSecond);
	}

	void MP3Playing::SetPosition(NAudio::Wave::WaveStream ^ strm, System::TimeSpan time)
	{
		strm->Position = (__int64) time.TotalSeconds;
	}

	void MP3Playing::Seek(NAudio::Wave::WaveStream ^ strm, double offset)
	{
		strm->Position = strm->Position + (long)(offset * strm->WaveFormat->AverageBytesPerSecond);
	}
}