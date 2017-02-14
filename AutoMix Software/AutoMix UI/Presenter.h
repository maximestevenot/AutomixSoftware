// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#pragma once
#include "ViewWithTrackCollection.h"

namespace AutoMixUI {

	public ref class Presenter
	{
	public:
		Presenter();
		Presenter(ViewWithTrackCollection^);
		void notify();

		TrackCollection^ loadTracks(System::ComponentModel::BackgroundWorker^, array<System::String^>^);
		void exportTrackList(System::ComponentModel::BackgroundWorker^, System::String^);
		TrackCollection^ sortTrackCollectionWithGeneticAlgorithm(System::ComponentModel::BackgroundWorker^);
		void clearDataBase();

	private:
		System::Collections::Generic::List<ViewWithTrackCollection^>^ _views;

		AutoMixDataManagement::TrackCollection^ _trackCollection;
		AutoMixDataManagement::IAudioDataExtraction^ _dataExtractionEngine;
	};
}
