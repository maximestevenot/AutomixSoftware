#pragma once

#include "Track.h"

namespace AutoMixDataManagement {

	typedef System::Collections::Generic::List<Track^> track_collection;

	public ref class TrackCollection : public track_collection
	{
	public:
		void add(Track^);
		Track^ searchByName(System::String^ name);
	};

}