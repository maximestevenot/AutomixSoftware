// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "SimulatedAnnealingSortAlgorithm.h"

using namespace System;
using namespace AutoMixDataManagement;

namespace AutoMixAI
{
	SimulatedAnnealingSortAlgorithm::SimulatedAnnealingSortAlgorithm(TrackDistance^ distance) : SimulatedAnnealingSortAlgorithm(distance, 1, 35, 0.93, 15)
	{
	}

	SimulatedAnnealingSortAlgorithm::SimulatedAnnealingSortAlgorithm(TrackDistance^ distance, int stopTemperature, int beginTemperature, float decayFactor, int numberOfIteration) : SortAlgorithm(distance)
	{
		STOPTEMPERATURE = stopTemperature;
		BEGINTEMPERATURE = beginTemperature;
		DECAYFACTOR = decayFactor;
		NUMBEROFITERATION = numberOfIteration;
	}

	TrackCollection^ SimulatedAnnealingSortAlgorithm::sort(System::ComponentModel::BackgroundWorker^ bw, TrackCollection^ trackCollection)
	{	
		int nb_track = trackCollection->Count;
		int N = (nb_track / 2) * (nb_track / 2);
		TrackCollection^ result = trackCollection;
		TrackCollection^ temp;
		System::Random^ rand = gcnew System::Random();

		for (int k = 0; k < NUMBEROFITERATION; k++) {
			
			if (bw->CancellationPending)
			{
				break;
			}
			float temperature = BEGINTEMPERATURE;

			while (temperature > STOPTEMPERATURE) {
				for (int i = 0; i < N; i++) {

					temp = createPotentialTrackCollection(result);
					double dE = computeIndividualEvaluation(temp) - computeIndividualEvaluation(result);

					if (dE < 0) {
						result = temp;
					}
					else {
						if (rand->Next(100) < (System::Math::Exp(-dE / temperature) * 100)) {
							result = temp;
						}
					}

				}
				temperature = temperature * DECAYFACTOR;
			}
			if (computeIndividualEvaluation(result) < computeIndividualEvaluation(trackCollection)) {
				trackCollection = result;
			}
			bw->ReportProgress((int)1000 * k / NUMBEROFITERATION);
			System::Diagnostics::Debug::WriteLine("premier {0}", computeIndividualEvaluation(trackCollection));
		}

		return trackCollection;
	}

	double SimulatedAnnealingSortAlgorithm::computeIndividualEvaluation(TrackCollection^ individual)
	{
		double result = 0;
		for (int k = 0; k < (individual->Count) - 1; k++)
		{
			result += Distance->compute(individual[k], individual[k + 1]);
		}
		return result;
	}

	TrackCollection^ SimulatedAnnealingSortAlgorithm::createPotentialTrackCollection(TrackCollection^ current) {
		TrackCollection^ newTrackCollection = gcnew TrackCollection();
		System::Random^ rand = gcnew System::Random();
		int track1 = rand->Next(current->Count);
		int track2 = rand->Next(current->Count);

		for (int i = 0; i < current->Count; i++) {
			if (i == track1) {
				newTrackCollection->Add(current[track2]);
			}
			else {
				if (i == track2) {
					newTrackCollection->Add(current[track1]);
				}
				else {
					newTrackCollection->Add(current[i]);
				}
			}
			

		}
		return newTrackCollection;

	}

}
