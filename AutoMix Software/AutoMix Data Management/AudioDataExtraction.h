// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#pragma once

#include "AutoMixDataManagement.h"
#include "DelegateAudioDataExtraction.h"


namespace AutoMixDataManagement {

	delegate void ExtractDelegate();

	public ref class AudioDataExtraction
	{
	public:

		AudioDataExtraction();
		void extractData(TrackCollection^);

	private:

		void initExecConfiguration();
		System::Diagnostics::ProcessStartInfo^ _startInfo;
		System::IO::DirectoryInfo^ _tempDirectory;
	};

}
