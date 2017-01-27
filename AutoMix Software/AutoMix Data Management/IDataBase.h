// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#pragma once
#include "Track.h"
#include "TrackCollection.h"

namespace DataBase {

	ref class IDataBase
	{
		
	public:
		IDataBase();
		void createNewDatabase();
		void connectToDatabase(System::String^);
		void createTable(System::String^, System::String^, AutoMixDataManagement::Track^);
		void addTrack(AutoMixDataManagement::Track^);
		System::Collections::Generic::List<System::String^>^ getTracksInDataBase();
	private:
		System::Data::SQLite::SQLiteConnection^ _dbConnection;
	};
}