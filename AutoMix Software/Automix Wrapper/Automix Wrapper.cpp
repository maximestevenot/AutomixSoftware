// This is the main DLL file.

#include "stdafx.h"

#include <DataExctracionLibrary.h>
#pragma comment(lib, "..\\..\\DataExctracionLibrary\\Debug\\DataExctracionLibrary.lib")

#include "Automix Wrapper.h"

using namespace System;
using namespace System::Runtime::InteropServices;

[DllImport("..\\..\\DataExctracionLibrary\\Debug\\DataExctracionLibrary.dll", CharSet = CharSet::Auto)]
extern double fnDataExctracionLibrary();

double AutoMixWrapper::Class1::safe_fnDataExctracionLibrary()
{
	return fnDataExctracionLibrary();
}
