// Automix Wrapper.h
#pragma once

#include <DataExctracionLibrary.h>

#define DATA_EXTRACTION_LIB "..\\..\\DataExctracionLibrary\\Debug\\DataExctracionLibrary.dll"

namespace AutoMixWrapper {

	using namespace System;
	using namespace System::Runtime::InteropServices;

	[DllImport(DATA_EXTRACTION_LIB, EntryPoint = "?fnDataExctracionLibrary@@YANXZ")]
	extern double fnDataExctracionLibrary(void);

	public ref class DataExctractionLibrary
	{
	public:

		static double safe_fnDataExctracionLibrary();

	};
}
