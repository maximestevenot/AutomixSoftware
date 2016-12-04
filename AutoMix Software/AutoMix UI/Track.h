#pragma once

#include <string>

namespace AMResources {

	public class Track
	{
	private :

		class Data 
		{
		private :
			unsigned int _bpm;
		};

		std::string _path;
		Data _data;

	};
}
