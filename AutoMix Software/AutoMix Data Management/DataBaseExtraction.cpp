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

	void DataBaseExtraction::extractData(Track^ track)
	{
		_dataBase->extractData(track);
	}
}