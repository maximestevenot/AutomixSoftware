// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#pragma once

#include "TrackDistance.h"

namespace AutoMixAI
{

	public ref class SortAlgorithm abstract
	{
	public:

		property TrackDistance^ Distance { TrackDistance^ get(); }

		SortAlgorithm(TrackDistance^ distance);

		virtual AutoMixDataManagement::TrackCollection^ sort(System::ComponentModel::BackgroundWorker^, AutoMixDataManagement::TrackCollection^) abstract;

	private:
		TrackDistance^ _distance;
	};

}

