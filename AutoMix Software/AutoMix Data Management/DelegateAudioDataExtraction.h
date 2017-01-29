#pragma once

#include "AutoMixDataManagement.h"

namespace AutoMixDataManagement {

	public ref class DelegateAudioDataExtraction
	{
	public:
		DelegateAudioDataExtraction(System::Diagnostics::ProcessStartInfo^ startInfo, System::IO::DirectoryInfo^ tempDirectory) :_startInfo(startInfo), _tempDirectory(tempDirectory) {}

		void extractDelegate(Track^ track);

	private:
		System::Diagnostics::ProcessStartInfo^ _startInfo;
		System::IO::DirectoryInfo^ _tempDirectory;
	};
}