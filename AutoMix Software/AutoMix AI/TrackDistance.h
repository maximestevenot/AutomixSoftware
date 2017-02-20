// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#pragma once

namespace AutoMixAI
{

	public ref class TrackDistance abstract
	{

	public:

		property double BPMPriority;
		property double KeyNumberPriority;
		property double KeyTonalityPriority;
		property double DanceabilityPriority;

		TrackDistance()
		{
			BPMPriority = 1200;
			KeyNumberPriority = 20;
			KeyTonalityPriority = 2000;
			DanceabilityPriority = 10;
		}

		virtual double compute(AutoMixDataManagement::Track^ t1, AutoMixDataManagement::Track^ t2) abstract;
	};

}

