#include "Presenter.h"

namespace AutoMixUI {
	using namespace System;
	using namespace System::Collections;

	Presenter::Presenter()
	{
		_views = gcnew Generic::List<ViewWithTrackCollection^>();
		_trackCollection = gcnew TrackCollection();
		_dataExtractionEngine = gcnew AudioDataExtractionProxy();
		_audioExportationEngine = nullptr;
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
	void Presenter::loadTracks(array<System::String^>^ fileEntries)
	{
		IEnumerator^ files = fileEntries->GetEnumerator();

		_dataExtractionEngine->setPath(fileEntries[0]->Substring(0, fileEntries[0]->LastIndexOf("\\")));

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

		_dataExtractionEngine->extractBPM(_trackCollection);
		_dataExtractionEngine->extractDuration(_trackCollection);
		_dataExtractionEngine->extractKey(_trackCollection);

		_trackCollection->sortByName();
		notify();
	}

	void Presenter::exportTrackList(System::String^ destinationFile)
	{
		_audioExportationEngine = gcnew AudioExportationProxy(destinationFile);
		_audioExportationEngine->exportTrackList(_trackCollection);
	}
}