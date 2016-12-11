#pragma once

#include "Track.h"

namespace AutoMixDataManagement {
	using namespace System::Collections::Generic;

	typedef List<Track^> track_collection;

	public ref class TrackCollection : public track_collection
	{
	public:
		void add(Track^);
		Track^ searchByName(String^ name);
	};

}