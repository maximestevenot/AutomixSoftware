// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "Presenter.h"

namespace AutoMixUI {
	using namespace System;
	using namespace System::Collections;
	using namespace AutoMixAI;

	Presenter::Presenter()
	{
		_views = gcnew Generic::List<ViewWithTrackCollection^>();
		_trackCollection = gcnew TrackCollection();
		_dataExtractionEngine = gcnew AudioDataExtractionProxy();
	}

	Presenter::Presenter(ViewWithTrackCollection^ view) : Presenter()
	{
		_views->Add(view);
	}

	void Presenter::notify()
	{
		for each (auto view in _views)
		{
			view->update(_trackCollection);
		}
	}

	TrackCollection^ Presenter::sortTrackCollectionWithGeneticAlgorithm(ComponentModel::BackgroundWorker^ bw)
	{
		GeneticAlgorithm^ _geneticAlgorithm = gcnew GeneticAlgorithm();
		_trackCollection = _geneticAlgorithm->sortTrackByGeneticAlgorithm(bw, _trackCollection);
		return _trackCollection;
	}

	TrackCollection^ Presenter::loadTracks(ComponentModel::BackgroundWorker^ bw, array<String^>^ fileEntries)
	{
		IEnumerator^ files = fileEntries->GetEnumerator();
		TrackCollection^ collection = gcnew TrackCollection();

		while (files->MoveNext() && !bw->CancellationPending)
		{
			String^ filePath = safe_cast<String^>(files->Current);

			if (Utils::getExtension(filePath)->Contains("mp3"))
			{
				Track^ track = gcnew Track(filePath);
				collection->safeAdd(track);
			}
		}

		_trackCollection->concat(collection);
		_trackCollection->sortByName();
		_dataExtractionEngine->extractData(bw, collection);
		_trackCollection = TrackCollection::CopyFrom(_trackCollection);
		_trackCollection->purge();
		return _trackCollection;
	}

	void Presenter::exportTrackList(System::ComponentModel::BackgroundWorker^ bw, String^ destinationFile)
	{
		_trackCollection->exportToMP3(bw, destinationFile);
	}

	void Presenter::clearDataBase()
	{
		DataBase^ db = gcnew DataBase();
		db->clear();
	}

}