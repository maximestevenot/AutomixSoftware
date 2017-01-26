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
		AutoMixDataManagement::TrackCollection^ getTracksInDataBase(AutoMixDataManagement::Track^);
	private:
		SQLiteConnection^ _dbConnection = nullptr;
	};
}