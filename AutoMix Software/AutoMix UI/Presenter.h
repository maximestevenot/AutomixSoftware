#pragma once
#include "UsingCollectionView.h"

namespace AutoMixUI {
	using namespace AutoMixDataManagement;

	public ref class Presenter
	{
	public:
		Presenter();
		Presenter(UsingCollectionView^);
		void notify();

		void loadTracks(array<System::String^>^);
		void exportTrackList(System::String^);

	private:
		System::Collections::Generic::List<UsingCollectionView^>^ _views;

		TrackCollection^ _trackCollection;
		IAudioDataExtraction^ _dataExtractionEngine;
		IAudioExportation^ _audioExportationEngine;
	};
}
