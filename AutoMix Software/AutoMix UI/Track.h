#pragma once

#include <string>
#include <iostream>
#include "Utils.h"

namespace AM_Resources {

	public class Track
	{
	private:

		struct Data
		{
			unsigned int _bpm = 0;
			unsigned int _duration = 0;
		};

		Data * _data;

		std::string _path;
		std::string _name;

	public:

		Track();
		Track(std::string path);

		std::string getName() const;
		unsigned int getBPM() const;
		unsigned int getDuration() const;
	};

	std::ostream & operator<<(std::ostream & out, const Track & track);

}
