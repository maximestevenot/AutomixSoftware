// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "DataBaseExtraction.h"

using namespace System::Threading::Tasks;
using namespace System::Diagnostics;
using namespace System::IO;
using namespace System;

namespace AutoMixDataManagement {

	DataBaseExtraction::DataBaseExtraction(DataBase^ dataBase)
	{
		_dataBase = dataBase;
	}

	void DataBaseExtraction::extractData(System::ComponentModel::BackgroundWorker^ bw, int nbTracks, System::Threading::CancellationTokenSource^ cts, Track^ track)
	{
		_dataBase->extractData(track);
		bw->ReportProgress((int)100 / nbTracks);
	}
}