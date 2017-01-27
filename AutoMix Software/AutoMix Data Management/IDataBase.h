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
		SQLiteConnection^ _dbConnection = nullptr;
	};
}