#pragma once

namespace AutoMixDataManagement {

	public ref class Track
	{
	public:
		Track();
		Track(System::String^ path);

		~Track();

		System::String^ getName();
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
		System::String^ _path;
		System::String^ _name;
	};

}

