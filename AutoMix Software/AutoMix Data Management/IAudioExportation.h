#pragma once

#include "TrackCollection.h"

namespace AutoMixDataManagement {

	public ref class IAudioExportation abstract
	{

	public:
		//IAudioExportation() {}

		//virtual ~IAudioExportation() {}

		virtual void exportTrackList(TrackCollection^) abstract;
	};

}
