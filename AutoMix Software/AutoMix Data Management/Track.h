#pragma once

#include <string>

namespace AutoMixDataManagement {

	class Track
	{
	public:
		Track();
		Track(std::string path);

		~Track();

		std::string getName() const;
		unsigned int getBPM() const;
		unsigned int getDuration() const;

		void setBPM(unsigned int value);

	private:

		struct Data
		{
			unsigned int bpm = 0;
			unsigned int duration = 0;
		};

		Data * _data;
		std::string _path;
		std::string _name;
	};

}

