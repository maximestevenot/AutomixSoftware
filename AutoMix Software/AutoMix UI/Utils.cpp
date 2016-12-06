#include "Utils.h"
#include <vcclr.h>


using namespace System;
using namespace System::Runtime::InteropServices;

namespace AM_StringUtils {

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

	std::string toStdString(String^ inputString)
	{
		char* tempString = (char*)(void*)Marshal::StringToHGlobalAnsi(inputString);
		std::string outputString = std::string(tempString);

		return outputString;
	}
	System::String^ toManagedString(std::string inputString) 
	{
		String^ outputString = gcnew String(inputString.c_str());
		return outputString;
	}

	System::String^ extractExtension(System::String^ fileName)
	{
		int last_dot_index = fileName->LastIndexOf(".");
		String^ extension = fileName->Remove(0, last_dot_index + 1);
		extension = extension->ToLower();
		
		return extension;
	}

}