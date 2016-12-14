#pragma once

#include "AutoMixDataManagement.h"

namespace AutoMixDataManagement {

	public ref class AudioDataExportationMock : public IAudioDataExportation
	{
	public:
		AudioDataExportationMock(System::String^ path);

		void exportTrackList(TrackCollection^) override;
	private:
		System::String^ _path;
	};

}