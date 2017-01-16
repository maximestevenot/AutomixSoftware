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

	void AudioDataExtractionProxy::extractData(Track^ track)
	{
		_realSubject->extractData(track);
	}

	void AudioDataExtractionProxy::extractData(TrackCollection^ trackCollection)
	{
		_realSubject->extractData(trackCollection);
	}

}
