// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "AudioDataExtractionProxy.h"
#include "AudioDataExtractionMock.h"

namespace AutoMixDataManagement {

	AudioDataExtractionProxy::AudioDataExtractionProxy()
	{
		_realSubject = gcnew AudioDataExtractionMock();
	}

	void AudioDataExtractionProxy::extractBPM(Track^ track)
	{
		_realSubject->extractBPM(track);
	}

	void AudioDataExtractionProxy::extractBPM(TrackCollection^ trackCollection)
	{
		_realSubject->extractBPM(trackCollection);
	}

	void AudioDataExtractionProxy::extractDuration(Track^ track)
	{
		_realSubject->extractDuration(track);
	}

	void AudioDataExtractionProxy::extractDuration(TrackCollection^ trackCollection)
	{
		_realSubject->extractDuration(trackCollection);
	}

	void AudioDataExtractionProxy::extractKey(Track^ track)
	{
		_realSubject->extractKey(track);
	}

	void AudioDataExtractionProxy::extractKey(TrackCollection^ trackCollection)
	{
		_realSubject->extractKey(trackCollection);
	}

}
