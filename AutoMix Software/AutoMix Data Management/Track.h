#pragma once

#include <string>

namespace AutoMixDataManagement {

	using namespace System;

	public ref class Track
	{
	public:
		Track();
		Track(String^ path);

		~Track();

		String^ getName();
		unsigned int getBPM();
		unsigned int getDuration();

		void setBPM(unsigned int value);

	private:

		ref struct Data
		{
			unsigned int bpm = 0;
			unsigned int duration = 0;
		};

		Data^ _data;
		String^ _path;
		String^ _name;
	};

}

