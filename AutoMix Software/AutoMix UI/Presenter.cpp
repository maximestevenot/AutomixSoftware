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
		if (_trackCollection->Count > 1)
		{
			GeneticSortAlgorithm^ geneticAlgorithm = gcnew GeneticSortAlgorithm();
			geneticAlgorithm->sort(bw, _trackCollection);
		}
		return _trackCollection;
	}

	TrackCollection^ Presenter::loadTracks(ComponentModel::BackgroundWorker^ bw, array<String^>^ fileEntries)
	{
		IEnumerator^ files = fileEntries->GetEnumerator();
		TrackCollection^ collection = gcnew TrackCollection();

		while (files->MoveNext() && !bw->CancellationPending)
		{
			String^ filePath = safe_cast<String^>(files->Current);

			if (IO::Directory::Exists(filePath))
			{
				IEnumerator^ dirFiles = IO::Directory::GetFiles(filePath)->GetEnumerator();

				while (dirFiles->MoveNext() && !bw->CancellationPending)
				{
					String^ dirFilePath = safe_cast<String^>(dirFiles->Current);

					if (Utils::getExtension(dirFilePath)->Contains("mp3"))
					{
						Track^ track = gcnew Track(dirFilePath);
						collection->safeAdd(track);
					}
				}
			}

			else if (Utils::getExtension(filePath)->Contains("mp3"))
			{
				Track^ track = gcnew Track(filePath);
				collection->safeAdd(track);
			}
		}

		_trackCollection->concat(collection);
		_trackCollection->sortByName();
		bw->ReportProgress(0);

		_dataExtractionEngine->extractData(bw, collection);
		getMyRightsBack();

		_trackCollection->purge();
		return _trackCollection;
	}

	void Presenter::removeTracks(Generic::List<String^>^ selection)
	{
		for each (String^ name in selection)
		{
			_trackCollection->Remove(name);
		}
		notify();
	}

	void Presenter::moveTrack(int index, String^ name)
	{
		if (index < 0 && index >= _trackCollection->Count)
		{
			notify();
			return;
		}

		Track^ t = _trackCollection->search(name);
		_trackCollection->Remove(t);
		_trackCollection->Insert(index, t);
	}

	void Presenter::exportTrackList(System::ComponentModel::BackgroundWorker^ bw, String^ destinationFile)
	{
		if (_trackCollection->Count >= 1)
		{
			_trackCollection->exportToMP3(bw, destinationFile);
		}
	}

	void Presenter::clearDataBase()
	{
		DataBase^ db = gcnew DataBase();
		db->clear();
	}

	void Presenter::getMyRightsBack()
	{
		_trackCollection = TrackCollection::CopyFrom(_trackCollection);
	}
}