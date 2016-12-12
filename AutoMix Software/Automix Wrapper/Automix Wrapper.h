// Automix Wrapper.h
#pragma once
#pragma comment(lib, "..\\..\\DataExctracionLibrary\\Debug\\DataExctracionLibrary.lib")

#include <DataExctracionLibrary.h>

using namespace System;
using namespace System::Runtime::InteropServices;

[DllImport("..\\..\\DataExctracionLibrary\\Debug\\DataExctracionLibrary.dll", EntryPoint="?fnDataExctracionLibrary@@YANXZ")]
extern double fnDataExctracionLibrary(void);

namespace AutoMixWrapper {

	public ref class Class1 {
	public:
		static double safe_fnDataExctracionLibrary();
	};

}
