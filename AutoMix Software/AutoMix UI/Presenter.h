#pragma once
#include "ViewWithTrackCollection.h"

namespace AutoMixUI {
	using namespace AutoMixDataManagement;

	public ref class Presenter
	{
	public:
		Presenter();
		Presenter(ViewWithTrackCollection^);
		void notify();

		void loadTracks(array<System::String^>^);
		void exportTrackList(System::String^);

	private:
		System::Collections::Generic::List<ViewWithTrackCollection^>^ _views;

		TrackCollection^ _trackCollection;
		IAudioDataExtraction^ _dataExtractionEngine;
	};
}
