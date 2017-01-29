// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#pragma once

#include "AutoMixDataManagement.h"

namespace AutoMixDataManagement {

	public ref class AudioDataExtractionMock : public IAudioDataExtraction
	{
	public:
		AudioDataExtractionMock();

		void extractData(Track^) override;
		void extractData(TrackCollection^) override;

	private:
		System::String^ _textFile = "";
		void setPath(Track^ track);

	};

}
