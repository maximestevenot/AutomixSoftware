#pragma once


#include "AutoMixDataManagement.h"

namespace AutoMixDataManagement {
	/*
	public ref class AudioDataExtractionProxy : public IAudioDataExtraction
	{
	public:

		AudioDataExtractionProxy();
		void extractBPM(Track^) override;
		void extractBPM(TrackCollection^) override;

	private:
		IAudioDataExtraction^ _realSubject;
	};*/

	
	public ref class AudioDataExportationProxy : public IAudioDataExtraction
	{
	public:
		AudioDataExportationProxy(System::String^ path);

		void exportTrackList(TrackCollection^) override;
	private:
		System::String^ _path;
		IAudioDataExportation^ _realSubject;
	};

}