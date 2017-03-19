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

		_sortAlgorithm = gcnew SimulatedAnnealingSortAlgorithm(gcnew SimpleDistance());
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
	bool Presenter::IsTrackCollectionFilled::get()
	{
		if (!_trackCollection)
		{
			return false;
		}
		return _trackCollection->Count >= 1;
	}
	TrackCollection^ Presenter::sortTrackCollectionWithGeneticAlgorithm(ComponentModel::BackgroundWorker^ bw)
	{
		if (_trackCollection->Count > 1)
		{
			_trackCollection = _sortAlgorithm->sort(bw, _trackCollection);
		}
		return _trackCollection;
	}

	TrackCollection^ Presenter::loadTracks(ComponentModel::BackgroundWorker^ bw, array<String^>^ fileEntries)
	{
		IEnumerator^ filesEnum = fileEntries->GetEnumerator();
		TrackCollection^ collection = gcnew TrackCollection();
		int count = 1;

		while (filesEnum->MoveNext() && !bw->CancellationPending)
		{
			String^ filePath = safe_cast<String^>(filesEnum->Current);

			if (IO::Directory::Exists(filePath))
			{
				IEnumerator^ filesInDirectoryEnum = IO::Directory::GetFiles(filePath)->GetEnumerator();

				while (filesInDirectoryEnum->MoveNext() && !bw->CancellationPending)
				{
					String^ filePathInDirectory = safe_cast<String^>(filesInDirectoryEnum->Current);

					if (Utils::getExtension(filePathInDirectory)->Contains("mp3"))
					{
						Track^ track = gcnew Track(filePathInDirectory);
						collection->safeAdd(track);
					}
				}
			}

			else if (Utils::getExtension(filePath)->Contains("mp3"))
			{
				Track^ track = gcnew Track(filePath);
				collection->safeAdd(track);
			}
			bw->ReportProgress((int)500 * count++ / fileEntries->Length);
		}

		_trackCollection->concat(collection);
		_trackCollection->sortByName();
		bw->ReportProgress(500);

		_dataExtractionEngine->extractData(bw, collection);
		retrieveControlOnCollection();

		_trackCollection->purge();
		return _trackCollection;
	}

	void Presenter::removeTracks(Generic::List<String^>^ selection)
	{
		for each (String^ trackName in selection)
		{
			_trackCollection->Remove(trackName);
		}
		notify();
	}

	void Presenter::moveTrack(int newIndex, String^ trackName)
	{
		if (newIndex < 0 && newIndex >= _trackCollection->Count)
		{
			notify();
			return;
		}

		Track^ track = _trackCollection->search(trackName);
		_trackCollection->Remove(track);
		_trackCollection->Insert(newIndex, track);
	}

	void Presenter::exportTrackList(System::ComponentModel::BackgroundWorker^ bw, String^ destinationFile)
	{

		if (_trackCollection->Count >= 1)
		{
			//createTransition(); BUGGED
			_trackCollection->exportToMP3(bw, destinationFile);
		}
	}

	void Presenter::clearDataBase()
	{
		DataBase^ db = gcnew DataBase();
		db->clear();
	}

	void Presenter::playMix(System::String ^ fileName)
	{
		_mp3Playing = gcnew AutoMixDataManagement::MP3Playing(fileName);
		_mp3Playing->play();
	}

	void Presenter::resumeMix()
	{
		_mp3Playing->play();
	}

	void Presenter::pauseMix()
	{
		_mp3Playing->pause();
	}

	void Presenter::stopMix()
	{
		_mp3Playing->stop();
	}

	void Presenter::seek(double seconds)
	{
		_mp3Playing->seek(seconds);
	}

	__int64 Presenter::getPosition()
	{
		return _mp3Playing->getPosition();
	}

	__int64 Presenter::getLength()
	{
		return _mp3Playing->getLength();
	}

	void Presenter::retrieveControlOnCollection()
	{
		_trackCollection = TrackCollection::CopyFrom(_trackCollection);
	}

	void Presenter::createTransition()
	{
		Transition^ transition = gcnew Transition(_trackCollection);
		transition->makeTransition();
	}
}