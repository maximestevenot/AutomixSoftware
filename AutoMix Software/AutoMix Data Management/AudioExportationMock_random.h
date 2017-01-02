#pragma once

#include "AutoMixDataManagement.h"

namespace AutoMixDataManagement {

	public ref class AudioExportationMock : public IAudioExportation
	{
	public:

		AudioExportationMock(System::String^ path);
		void exportTrackList(TrackCollection^) override;

	private:
		System::String^ _path;
	};
}