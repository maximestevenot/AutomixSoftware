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

namespace AutoMixDataManagement {

	public ref class DataBase
	{

	public:
		DataBase();
		DataBase(System::String^ path);

		void addTrack(Track^);
		void clear();
		void extractData(Track^ track);
		bool isInDataBase(Track^);
	private:

		void connectToDatabase(System::String^);
		void createTable();

		System::String^ _dbPath;
		System::Data::SQLite::SQLiteConnection^ _dbConnection;
	};
}