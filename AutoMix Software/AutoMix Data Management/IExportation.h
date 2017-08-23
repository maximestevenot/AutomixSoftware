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

	public ref class IExportation abstract
	{
	public:
		/// <summary>
		/// Export a <c>TrackCollection</c> in a single audio file.
		/// Different mix style can be used according to the implementation of this method.
		/// </summary>
		/// <param name="bw">An instance of BackgroindWorker</param>
		/// <param name="trackCollection">Collection to export</param>
		/// <param name="outputFile">Path of the destination file</param>
		void virtual exportMix(System::ComponentModel::BackgroundWorker^ bw, TrackCollection^ collection, System::String^ outputFile) abstract;
	};

}

