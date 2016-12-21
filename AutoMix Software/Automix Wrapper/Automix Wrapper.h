// Automix Wrapper.h
#pragma once

#include <DataExtractionLibrary.h>

#define DATA_EXTRACTION_LIB "..\\..\\DataExtractionLibrary\\Debug\\DataExtractionLibrary.dll"

namespace AutoMixWrapper {

	using namespace System;
	using namespace System::Runtime::InteropServices;

	[DllImport(DATA_EXTRACTION_LIB, EntryPoint = "?fnDataExtractionLibrary@@YANXZ")]
	extern double fnDataExtractionLibrary(void);

	public ref class DataExctractionLibrary
	{
	public:

		static double safe_fnDataExtractionLibrary();

	};
}
