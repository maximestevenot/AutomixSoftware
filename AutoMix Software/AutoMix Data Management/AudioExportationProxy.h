#pragma once

#include "AutoMixDataManagement.h"

namespace AutoMixDataManagement {
	
	public ref class AudioExportationProxy : public IAudioExportation
	{
	public:

		AudioExportationProxy(System::String^ path);
		void exportTrackList(TrackCollection^) override;

	private:
		System::String^ _path;
		IAudioExportation^ _realSubject;
	};
}