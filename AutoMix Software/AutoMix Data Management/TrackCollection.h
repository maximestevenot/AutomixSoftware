#pragma once

#include "Track.h"
#include "TracksComparison.h"

namespace AutoMixDataManagement {

	typedef System::Collections::Generic::List<Track^> track_collection;

	public ref class TrackCollection : public track_collection
	{
	public:
		Track^ searchByName(System::String^ name);

		void sortByName();
		void sortByDescendingName();
		void sortByDuration();
		void sortByDescendingDuration();
		void sortByBPM();
		void sortByDescendingBPM();
	};

}