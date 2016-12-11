// DataExctracionLibrary.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "DataExctracionLibrary.h"


// This is an example of an exported variable
DATAEXCTRACIONLIBRARY_API int nDataExctracionLibrary=0;

// This is an example of an exported function.
DATAEXCTRACIONLIBRARY_API int fnDataExctracionLibrary(void)
{
    return 42;
}
