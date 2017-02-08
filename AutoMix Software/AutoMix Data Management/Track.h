// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#pragma once

namespace AutoMixDataManagement {

	public ref class Track
	{
	public:

		Track();
		Track(System::String^ path);

		property unsigned int BPM;
		property unsigned int Duration;
		property System::String^ Key;

		property System::String^ Name { System::String^ get(); }
		property System::String^ Path { System::String^ get(); }
		property unsigned int Id { unsigned int get(); }

		System::String^ displayDuration();

	private:
		static unsigned int TRACKS_COUNT = 0;
		System::String^ _name;
		System::String^ _path;
		unsigned int _id;
	};
}