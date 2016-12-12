// DataExctracionLibrary.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "DataExctracionLibrary.h"

#include <basis.h>
#include <types.h>
#include <ERBTools.h>
#include <TranscriberExtract.h>
#include <TimeLine.h>

// This is an example of an exported variable
DATAEXCTRACIONLIBRARY_API int nDataExctracionLibrary=0;

// This is an example of an exported function.
DATAEXCTRACIONLIBRARY_API double fnDataExctracionLibrary(void)
{
	double d = Marsyas::ERBTools::Freq2ERB(1000);
	return 175.0;
}
