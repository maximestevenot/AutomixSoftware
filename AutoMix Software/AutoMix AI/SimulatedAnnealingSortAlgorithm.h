// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.


#pragma once

#include "SortAlgorithm.h"

namespace AutoMixAI
{

	public ref class SimulatedAnnealingSortAlgorithm : public SortAlgorithm
	{
	public:
		SimulatedAnnealingSortAlgorithm(TrackDistance^ distance);

		SimulatedAnnealingSortAlgorithm(TrackDistance^ distance, int stopTemperature, int beginTemperature, float decayFactor);

		AutoMixDataManagement::TrackCollection^ sort(System::ComponentModel::BackgroundWorker^, AutoMixDataManagement::TrackCollection^) override;

	private:

		initonly int STOPTEMPERATURE;
		initonly int BEGINTEMPERATURE;
		initonly float DECAYFACTOR;


		double computeIndividualEvaluation(AutoMixDataManagement::TrackCollection^);
		AutoMixDataManagement::TrackCollection^ createPotentialTrackCollection(AutoMixDataManagement::TrackCollection^);
	};
}