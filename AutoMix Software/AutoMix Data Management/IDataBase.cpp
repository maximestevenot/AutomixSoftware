#include "stdafx.h"
#include "IDataBase.h"

using namespace System;
using namespace System::Data::SQLite;
using namespace AutoMixDataManagement;
namespace DataBase {

	IDataBase::IDataBase()
	{
		
	}

	void IDataBase::createNewDatabase()
	{
		SQLiteConnection::CreateFile("MyDatabase.sqlite");
	}

	void IDataBase::connectToDatabase(String^ path) 
	{
		_dbConnection = gcnew SQLiteConnection(path);
		_dbConnection->Open();
	}

	void IDataBase::createTable(String^ nom,String^ type, Track^ track)
	{
		System::String sql("");
		SQLiteCommand^ command = gcnew SQLiteCommand(sql, _dbConnection);
		command->ExecuteNonQuery();
	}

	void IDataBase::addTrack(Track^ track)
	{
		String^ sql = "insert into " + "" + "values ('" + "" + "" + "')";
		SQLiteCommand^ command = gcnew SQLiteCommand(sql, _dbConnection);
		command->ExecuteNonQuery();
	}

	TrackCollection^ IDataBase::getTracksInDataBase(Track^) {
		TrackCollection^ result = gcnew TrackCollection();
		String^ sql = "insert into " + "" + "values ('" + "" + "" + "')";
		SQLiteCommand^ command = gcnew SQLiteCommand(sql, _dbConnection);
		command->ExecuteNonQuery();
		SQLiteDataReader^ reader = command->ExecuteReader();
		while (reader->Read()) {
			result->Add(gcnew Track(""));
		}
		return result;
	}

}