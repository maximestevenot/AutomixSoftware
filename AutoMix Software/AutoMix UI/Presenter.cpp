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

	void Presenter::sortTrackCollectionWithGeneticAlgorithm()
	{
		GeneticAlgorithm^ al = gcnew GeneticAlgorithm();
		_trackCollection = al->sortTrackByGeneticAlgorithm(_trackCollection);
		notify();
	}

	void Presenter::loadTracks(array<System::String^>^ fileEntries)
	{
		IEnumerator^ files = fileEntries->GetEnumerator();
		while (files->MoveNext())
		{
			String^ filePath = safe_cast<String^>(files->Current);
			int lastDotIndex = filePath->LastIndexOf(".");
			String^ extension = filePath->Substring(lastDotIndex + 1)->ToLower();

			if (extension->Contains("mp3"))  //TODO make it better
			{
				Track^ track = gcnew Track(filePath);
				_trackCollection->Add(track);
			}
		}

		_dataExtractionEngine->extractData(_trackCollection);

		_trackCollection->sortByName();
		notify();
	}

	void Presenter::exportTrackList(System::String^ destinationFile)
	{
		_trackCollection->exportToMP3(destinationFile);
	}
}