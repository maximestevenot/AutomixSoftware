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
	DelegateAudioDataExtraction::DelegateAudioDataExtraction(System::IO::DirectoryInfo^ tempDirectory)
	{
		_tempDirectory = tempDirectory;
	}
	void DelegateAudioDataExtraction::delegateExtraction(Track ^ track)
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
		ex->extractData(track);
	}

}