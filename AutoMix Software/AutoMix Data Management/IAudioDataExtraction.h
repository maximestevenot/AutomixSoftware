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

	public ref class IAudioDataExtraction abstract
	{

	public:
		//IAudioDataExtraction() {}

		//virtual ~IAudioDataExtraction() {}

		virtual void extractBPM(Track^) abstract;
		virtual void extractBPM(TrackCollection^) abstract;

		virtual void extractDuration(Track^) abstract;
		virtual void extractDuration(TrackCollection^) abstract;

		virtual void extractKey(Track^) abstract;
		virtual void extractKey(TrackCollection^) abstract;
	};

}