#pragma once

#include "TrackCollection.h"

namespace AutoMixDataManagement {

	public ref class IAudioDataExportation abstract
	{

	public:
		//IAudioDataExportation() {}

		//virtual ~IAudioDataExportation() {}

		virtual void exportTrackList(TrackCollection^) abstract;
	};

}
