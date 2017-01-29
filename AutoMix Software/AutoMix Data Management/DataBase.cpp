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
using namespace System::IO;
using namespace System::Data::SQLite;
using namespace System::Collections::Generic;

namespace AutoMixDataManagement {

	DataBase::DataBase() : DataBase("MyBase.sqlite") {}

	DataBase::DataBase(String^ path)
	{
		if (!File::Exists(path))
		{
			_dbPath = path;
			SQLiteConnection::CreateFile(path);
			connectToDatabase(path);
			createTable();
		}

		else
		{
			connectToDatabase(path);
		}

	}

	DataBase::~DataBase()
	{
		if (_dbConnection)
		{
			_dbConnection->Close();
		}
	}

	void DataBase::connectToDatabase(String^ path)
	{
		String^ connectionString = ("Data Source=" + path + ";Version=3;");
		_dbConnection = gcnew SQLiteConnection(connectionString);
		_dbConnection->Open();
	}

	void DataBase::createTable()
	{
		String^ query = "CREATE TABLE tracks (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, duration TEXT, bpm TEXT, key TEXT)";
		SQLiteCommand^ command = gcnew SQLiteCommand(query, _dbConnection);
		command->ExecuteNonQuery();
	}

	void DataBase::addTrack(Track^ track)
	{
		String^ query = "INSERT INTO tracks (name, duration, bpm, key)";
		query += "VALUES ( '" + track->Name + "','" + track->Duration + "','" + track->BPM + "','" + track->Key + "')";
		SQLiteCommand^ command = gcnew SQLiteCommand(query, _dbConnection);
		command->ExecuteNonQuery();
	}

	void DataBase::clear()
	{
		String^ query = "DELETE FROM tracks";
		SQLiteCommand^ command = gcnew SQLiteCommand(query, _dbConnection);
		command->ExecuteNonQuery();

		String^ query2 = "DELETE FROM sqlite_sequence WHERE name='tracks'";
		SQLiteCommand^ command2 = gcnew SQLiteCommand(query2, _dbConnection);
		command2->ExecuteNonQuery();
	}

	List<String^>^ DataBase::getTracksInDataBase() 
	{
		List<String^>^ result = gcnew List<String^>();

		String^ query = "SELECT name FROM tracks";
		SQLiteCommand^ command = gcnew SQLiteCommand(query, _dbConnection);
		command->ExecuteNonQuery();
		
		SQLiteDataReader^ reader = command->ExecuteReader();
		while (reader->Read()) 
		{
			result->Add(reader->GetString(0));
		}
		return result;
	}

}