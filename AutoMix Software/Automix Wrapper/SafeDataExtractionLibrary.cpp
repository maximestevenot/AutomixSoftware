// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "SafeDataExtractionLibrary.h"

namespace AutoMixWrapper {

	using namespace System;
	using namespace System::Runtime::InteropServices;

	[DllImport(DATA_EXTRACTION_LIB, EntryPoint = "?fnDataExtractionLibrary@@YANXZ")]
	extern double fnDataExtractionLibrary(void);

	double SafeDataExtractionLibrary::fnDataExtractionLibrary()
	{
		double d = fnDataExtractionLibrary();
		return d;
	}

}