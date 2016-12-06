#include "Utils.h"
#include <vcclr.h>


using namespace System;
using namespace System::Runtime::InteropServices;

namespace AM_Utils {

	std::string nameFromPath(std::string path)
	{
		size_t last_slash_idx = path.find_last_of("\\");
		return path.erase(0, last_slash_idx + 1);
	}

	System::String^ getExtension(String^ fileName)
	{
		int lastDotIndex = fileName->LastIndexOf(".");
		String^ extension = fileName->Remove(0, lastDotIndex + 1);

		return extension->ToLower();
	}

	std::string convertString(String^ str)
	{
		char* str2 = (char*)(void*)Marshal::StringToHGlobalAnsi(str);
		std::string str3 = std::string(str2);
		return str3;
	}

}