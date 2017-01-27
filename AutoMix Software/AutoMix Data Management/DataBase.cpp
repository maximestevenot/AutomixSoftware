// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of AutoMix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

#include "stdafx.h"
#include "DataBase.h"

using namespace System;
using namespace System::Data::SQLite;
using namespace System::Collections::Generic;

namespace AutoMixDataManagement {

	DataBase::DataBase()
	{

	}

	void DataBase::createNewDatabase()
	{
		SQLiteConnection::CreateFile("MyDatabase.db");
	}

	void DataBase::connectToDatabase(String^ path)
	{
		_dbConnection = gcnew SQLiteConnection(path);
		_dbConnection->Open();
	}

	void DataBase::createTable(String^ nom, String^ type, Track^ track)
	{
		System::String^ sql("");
		SQLiteCommand^ command = gcnew SQLiteCommand(sql, _dbConnection);
		command->ExecuteNonQuery();
	}

	void DataBase::addTrack(Track^ track)
	{
		String^ sql = "insert into " + "" + "values ('" + "" + "" + "')";
		SQLiteCommand^ command = gcnew SQLiteCommand(sql, _dbConnection);
		command->ExecuteNonQuery();
	}

	List<String^>^ DataBase::getTracksInDataBase() {
		List<String^>^ result = gcnew List<String^>();
		String^ sql = "insert into " + "" + "values ('" + "" + "" + "')";
		SQLiteCommand^ command = gcnew SQLiteCommand(sql, _dbConnection);
		command->ExecuteNonQuery();
		SQLiteDataReader^ reader = command->ExecuteReader();
		while (reader->Read()) {
			result->Add(reader->GetString(1));
		}
		return result;
	}

}