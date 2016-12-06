#pragma once
#include <string>

namespace AM_StringUtils {
	std::string nameFromPath(std::string path);

	std::string toStdString(System::String^);
	System::String^ toManagedString(std::string);

	System::String^ extractExtension(System::String^ fileName);
}