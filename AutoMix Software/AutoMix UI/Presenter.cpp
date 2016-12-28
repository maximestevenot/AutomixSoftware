#include "Presenter.h"


namespace AutoMixUI {
	using namespace System;
	using namespace System::Collections;

	Presenter::Presenter()
	{
		_views = gcnew Generic::List<UsingCollectionView^> ();
		_trackCollection = gcnew TrackCollection();
		_dataExtractionEngine = gcnew AudioDataExtractionProxy();
		_audioExportationEngine = nullptr;
	}

	Presenter::Presenter(UsingCollectionView^ view) : Presenter()
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

		while (files->MoveNext())
		{
			String^ filePath = safe_cast<String^>(files->Current);
			int lastDotIndex = filePath->LastIndexOf(".");
			String^ extension = filePath->Substring(lastDotIndex + 1)->ToLower();

			if (extension->Contains("mp3"))  //TODO make it better
			{
				Track^ track = gcnew Track(filePath);
				_dataExtractionEngine->extractBPM(track);
				_dataExtractionEngine->extractDuration(track);
				_trackCollection->Add(track);
			}
		}
		notify();
	}

	void Presenter::exportTrackList(System::String^ destinationFile)
	{
		_audioExportationEngine = gcnew AudioExportationProxy(destinationFile);
		_audioExportationEngine->exportTrackList(_trackCollection);
	}
}