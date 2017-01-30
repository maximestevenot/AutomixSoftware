#pragma once

#include "AutoMixDataManagement.h"

namespace AutoMixDataManagement {

	public ref class ExecutableExtraction : public IExtraction
	{
	public:

		ExecutableExtraction(System::IO::DirectoryInfo^);
		void extractData(Track^ track) override;

	private:
		System::Diagnostics::ProcessStartInfo^ _startInfo;
		System::IO::DirectoryInfo^ _tempDirectory;
	};

}

