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

	DataBase::DataBase() : DataBase("AutoMixSoftware.db") {}

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

	void DataBase::connectToDatabase(String^ path)
	{
		String^ connectionString = ("Data Source=" + path + ";Version=3;");
		_dbConnection = gcnew SQLiteConnection(connectionString);
	}

	void DataBase::createTable()
	{
		_dbConnection->Open();

		try
		{
			String^ query = "CREATE TABLE tracks (id INTEGER PRIMARY KEY AUTOINCREMENT, path TEXT, duration TEXT, bpm TEXT, key TEXT)";
			SQLiteCommand^ command = gcnew SQLiteCommand(query, _dbConnection);
			command->ExecuteNonQuery();
		}
		catch (...)
		{
			System::Diagnostics::Debug::WriteLine("DB ERROR when trying to create tracks table");
		}

		_dbConnection->Close();
	}

	void DataBase::addTrack(Track^ track)
	{
		_dbConnection->Open();

		try
		{
			String^ query = "INSERT INTO tracks (path, duration, bpm, key)";
			query += "VALUES ( '" + track->Path + "','" + track->Duration + "','" + track->BPM + "','" + track->Key + "')";
			SQLiteCommand^ command = gcnew SQLiteCommand(query, _dbConnection);
			command->ExecuteNonQuery();
		}
		catch (...)
		{
			System::Diagnostics::Debug::WriteLine("DB ERROR when trying to insert :" + track->Path);
		}

		_dbConnection->Close();
	}

	void DataBase::clear()
	{
		_dbConnection->Open();

		try
		{
			String^ query = "DELETE FROM tracks";
			SQLiteCommand^ command = gcnew SQLiteCommand(query, _dbConnection);
			command->ExecuteNonQuery();

			String^ query2 = "DELETE FROM sqlite_sequence WHERE name='tracks'";
			SQLiteCommand^ command2 = gcnew SQLiteCommand(query2, _dbConnection);
			command2->ExecuteNonQuery();
		}
		catch (...)
		{
			System::Diagnostics::Debug::WriteLine("DB ERROR when trying to clean database");
		}

		_dbConnection->Close();
	}

	void DataBase::extractData(Track^ track)
	{
		_dbConnection->Open();

		try
		{
			String^ query = "SELECT duration, bpm, key FROM tracks WHERE path = '" + track->Path + "'";
			SQLiteCommand^ command = gcnew SQLiteCommand(query, _dbConnection);
			command->ExecuteNonQuery();

			SQLiteDataReader^ reader = command->ExecuteReader();
			if (reader->Read())
			{
				track->Duration = Convert::ToUInt32(reader->GetString(0));
				track->BPM = Convert::ToUInt32(reader->GetString(1));
				track->Key = reader->GetString(2);
			}
		}
		catch (...)
		{
			System::Diagnostics::Debug::WriteLine("DB ERROR when trying to extract data of : " + track->Path);
		}

		_dbConnection->Close();
	}

	bool DataBase::isInDataBase(Track^ track) {
		_dbConnection->Open();

		try {
			String^ query = "SELECT path FROM tracks";
			SQLiteCommand^ command = gcnew SQLiteCommand(query, _dbConnection);
			command->ExecuteNonQuery();

			SQLiteDataReader^ reader = command->ExecuteReader();
			while (reader->Read())
			{
				if (reader->GetString(0) == track->Path)
				{
					_dbConnection->Close();
					return true;
				}
			}
		}
		catch (...)
		{
			System::Diagnostics::Debug::WriteLine("DB ERROR when trying to search : " + track->Path);
		}

		_dbConnection->Close();
		return false;
	}

}