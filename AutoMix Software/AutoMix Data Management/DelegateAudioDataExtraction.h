#pragma once

#include "AutoMixDataManagement.h"
#include "ExecutableExtraction.h"
#include "DataBaseExtraction.h"

namespace AutoMixDataManagement {

	public ref class DelegateAudioDataExtraction
	{
	public:
		DelegateAudioDataExtraction(System::ComponentModel::BackgroundWorker^, System::Threading::CancellationTokenSource^, System::IO::DirectoryInfo^);
		void delegateExtraction(Track^);
	
	private:
		System::IO::DirectoryInfo^ _tempDirectory;
		System::ComponentModel::BackgroundWorker^ _bw;
		System::Threading::CancellationTokenSource^ _cts;
	};
}