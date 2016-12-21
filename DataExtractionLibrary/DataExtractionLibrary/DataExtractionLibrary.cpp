// DataExtractionLibrary.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "DataExtractionLibrary.h"

#include <basis.h>
#include <types.h>
#include <ERBTools.h>
#include <TranscriberExtract.h>
#include <TimeLine.h>

// This is an example of an exported variable
DATAEXTRACTIONLIBRARY_API int nDataExtractionLibrary=0;

// This is an example of an exported function.
DATAEXTRACTIONLIBRARY_API double fnDataExtractionLibrary(void)
{
	double d = Marsyas::ERBTools::Freq2ERB(1000);
	return 15*d;
}
