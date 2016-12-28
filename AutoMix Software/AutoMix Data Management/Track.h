#pragma once

namespace AutoMixDataManagement {

	public ref class Track
	{
	public:

		Track();
		Track(System::String^ path);

		property unsigned int BPM;
		property unsigned int Duration;

		property System::String^ Name { System::String^ get(); }
		property System::String^ Path { System::String^ get(); }

		System::String^ displayDuration();

	private:
		System::String^ _name;
		System::String^ _path;
	};
}