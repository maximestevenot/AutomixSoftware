// This is the main DLL file.

#include "stdafx.h"
#include "Automix Wrapper.h"

namespace AutoMixWrapper {

	double DataExctractionLibrary::safe_fnDataExtractionLibrary()
	{
		double d = fnDataExtractionLibrary();
		return d;
	}

}