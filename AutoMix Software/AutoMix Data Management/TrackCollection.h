#pragma once

#include "Track.h"
#include "TracksComparison.h"

namespace AutoMixDataManagement {

	typedef System::Collections::Generic::List<Track^> track_collection;

	public ref class TrackCollection : public track_collection
	{
	public:
		void add(Track^);
		Track^ searchByName(System::String^ name);

		void orderByName();
		void orderByDescendingName();
		void orderByDuration();
		void orderByDescendingDuration();
		void orderByBPM();
		void orderByDescendingBPM();
	};

}