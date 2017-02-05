#pragma once

namespace AutoMixDataManagement {

	public ref class Utils
	{
	public:
		
		static System::String^ nameFromPath(System::String^ path);
		static System::String^ getExtension(System::String^ fileName);
		static System::String^ convertToOpenKey(System::String^ key, System::String^ scale);
	};
}