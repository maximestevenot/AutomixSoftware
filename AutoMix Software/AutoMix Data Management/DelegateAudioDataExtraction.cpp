// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "DelegateAudioDataExtraction.h"


namespace AutoMixDataManagement {
	DelegateAudioDataExtraction::DelegateAudioDataExtraction(System::ComponentModel::BackgroundWorker^ bw, int nbTracks, System::Threading::CancellationTokenSource^ cts, System::IO::DirectoryInfo^ tempDirectory)
	{
		_tempDirectory = tempDirectory;
		_bw = bw;
		_cts = cts;
		_nbtracks = nbTracks;
	}

	void DelegateAudioDataExtraction::delegateExtraction(Track ^ track)
	{
		if (!_cts->IsCancellationRequested)
		{
			IExtraction^ ex;
			DataBase^ db = gcnew DataBase();
			if (db->isInDataBase(track))
			{
				ex = gcnew DataBaseExtraction(db);
			}
			else
			{
				ex = gcnew ExecutableExtraction(_tempDirectory);
			}
			if (!_bw->CancellationPending)
			{
				ex->extractData(_bw, _nbtracks, _cts, track);
			}
			else
			{
				_cts->Cancel();
			}
		}
	}

}