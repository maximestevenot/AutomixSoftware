// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using System;
using System.Data.SQLite;
using System.IO;
using System.Linq;
using Automix_Data_Management.Model;

namespace Automix_Data_Management.Storage
{
    public class DataBase
    {
        private SQLiteConnection _dbConnection;

        public DataBase()
        {
            var dbDir = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\AutomixSoftware";

            if (!Directory.Exists(dbDir))
            {
                Directory.CreateDirectory(dbDir);
            }

            InitializeDataBaseConnection(dbDir + "\\automix_software_collection.db");
        }

        public DataBase(string path)
        {
            InitializeDataBaseConnection(path);
        }

        public void AddTrack(Track track)
        {
            var beats = track.Beats.Aggregate("", (current, i) => current + (Convert.ToString(i) + " "));
            var fadeins = track.FadeIns.Aggregate("", (current, i) => current + (Convert.ToString(i) + " "));
            var fadeouts = track.FadeOuts.Aggregate("", (current, i) => current + (Convert.ToString(i) + " "));

            _dbConnection.Open();

            try
            {
                var query = "INSERT INTO tracks (checksum, duration, bpm, key, danceability, samplerate, beats, fadeins, fadeouts)";
                query += "VALUES ( \"" + track.Checksum + "\",\"" + track.Duration + "\",\"" + track.Bpm + "\",\"" + track.Key + "\",\"" + track.Danceability + "\",\"" + track.Samplerate + "\",\"" + beats + "\",\"" + fadeins + "\",\"" + fadeouts + "\")";
                var command = new SQLiteCommand(query, _dbConnection);
                command.ExecuteNonQuery();
            }
            catch (Exception e)
            {
                System.Diagnostics.Debug.WriteLine("DB ERROR when trying to insert :" + track.Path + e.Message);
            }

            _dbConnection.Close();
        }

        public void Clear()
        {
            _dbConnection.Open();

            try
            {
                var deleteFromTracksCmd = new SQLiteCommand("DELETE FROM tracks", _dbConnection);
                deleteFromTracksCmd.ExecuteNonQuery();

                const string query = "DELETE FROM sqlite_sequence WHERE name='tracks'";
                var deleteSequenceCmd = new SQLiteCommand(query, _dbConnection);
                deleteSequenceCmd.ExecuteNonQuery();
            }
            catch (Exception e)
            {
                System.Diagnostics.Debug.WriteLine("DB ERROR when trying to clean database" + e.Message);
            }
            _dbConnection.Close();
        }

        public void ExtractData(Track track)
        {
            _dbConnection.Open();
            try
            {
                var query =
                    "SELECT duration, bpm, key, danceability, samplerate, beats, fadeins, fadeouts FROM tracks WHERE checksum = '" +
                    track.Checksum + "'";
                var command = new SQLiteCommand(query, _dbConnection);

                command.ExecuteNonQuery();
                var reader = command.ExecuteReader();

                if (!reader.Read())
                {
                    return;
                }

                track.Duration = Convert.ToInt32(reader.GetString(0));
                track.Bpm = Convert.ToInt32(reader.GetString(1));
                track.Key = reader.GetString(2);
                track.Danceability = Convert.ToDouble(reader.GetString(3));
                track.Samplerate = Convert.ToInt32(reader.GetString(4));
                track.Beats = ExtractFromString(reader.GetString(5));
                track.FadeIns = ExtractFromString(reader.GetString(6));
                track.FadeOuts = ExtractFromString(reader.GetString(7));

            }
            catch (Exception e)
            {
                System.Diagnostics.Debug.WriteLine(
                    "DB ERROR when trying to extract data of : " + track.Path + e.Message);

                _dbConnection.Close();
            }
        }

        public bool IsInDataBase(Track track)
        {
            _dbConnection.Open();

            try
            {
                const string query = "SELECT checksum FROM tracks";
                var command = new SQLiteCommand(query, _dbConnection);

                command.ExecuteNonQuery();
                var reader = command.ExecuteReader();

                while (reader.Read())
                {
                    if (reader.GetString(0).Equals(track.Checksum))
                    {
                        _dbConnection.Close();
                        return true;
                    }
                }
            }
            catch (Exception e)
            {
                System.Diagnostics.Debug.WriteLine("DB ERROR when trying to isPresent : " + track.Path + e.Message);
            }

            _dbConnection.Close();
            return false;
        }

        private void InitializeDataBaseConnection(string path)
        {
            if (!File.Exists(path))
            {
                SQLiteConnection.CreateFile(path);
                ConnectToDatabase(path);
                CreateTable();
            }
            else
            {
                ConnectToDatabase(path);
            }
        }

        private void ConnectToDatabase(string path)
        {
            _dbConnection = new SQLiteConnection("Data Source=" + path + ";Version=3;");
        }

        private void CreateTable()
        {
            _dbConnection.Open();

            try
            {
                const string query = "CREATE TABLE tracks (id INTEGER PRIMARY KEY AUTOINCREMENT, checksum TEXT, "
                                     + "duration TEXT, bpm TEXT, key TEXT, danceability TEXT, samplerate TEXT, beats TEXT, fadeins TEXT, fadeouts TEXT)";
                var command = new SQLiteCommand(query, _dbConnection);
                command.ExecuteNonQuery();
            }
            catch (Exception e)
            {
                System.Diagnostics.Debug.WriteLine("DB ERROR when trying to create tracks table" + e.Message);
            }

            _dbConnection.Close();
        }

        public int[] ExtractFromString(string orig)
        {
            char[] separator = { ' ' };
            var values = orig.Split(separator, StringSplitOptions.RemoveEmptyEntries);
            return values.Select(value => Convert.ToInt32(value)).ToArray();
        }





        public void ImportDatabBase(String pathUser)
        {
            /*
            var db = new DataBase();
            String path = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\AutomixSoftware\\automix_software_collection.db";
            ConnectToDatabase(path);
            */

            _dbConnection.Open();

            SQLiteConnection dbUserConnection = new SQLiteConnection("Data Source=" + pathUser + ";Version=3;");
            dbUserConnection.Open();

            if (CheckColumnsProperties(pathUser, dbUserConnection))
            {
                SQLiteCommand commandUser = new SQLiteCommand("SELECT * FROM tracks", _dbConnection); // checker nom table db user
                commandUser.ExecuteNonQuery();
                SQLiteDataReader readerUser = commandUser.ExecuteReader();

                while (readerUser.Read())
                {
                    string checksumUser = readerUser.GetString(1);
                    if (!IsInDataBase(checksumUser))
                    {
                        string query = "INSERT INTO tracks VALUES (" + readerUser.GetString(0) + ","
                            + checksumUser + ","
                            + readerUser.GetString(2) + ","
                            + readerUser.GetString(3) + ","
                            + readerUser.GetString(4) + ","
                            + readerUser.GetString(5) + ","
                            + readerUser.GetString(6) + ","
                            + readerUser.GetString(7) + ","
                            + readerUser.GetString(8) + ","
                            + readerUser.GetString(9) + ")"; // ATTENTION ';' DS REQUETE SQL A METTRE OU PAS ?
                        SQLiteCommand command = new SQLiteCommand(query, _dbConnection);
                        command.ExecuteNonQuery();
                    }
                }
            }
            else
            {
                // ATTENTION : EXCEPTION A CREER ?
            }

            _dbConnection.Close();
            dbUserConnection.Close();
        }

        private bool CheckColumnsProperties(String pathUser, SQLiteConnection dbUserConnection)
        {
            _dbConnection.Open();
            dbUserConnection.Open();
            int nbColUser, nbCol;

            SQLiteCommand commandUser = new SQLiteCommand("SELECT * FROM tracks", dbUserConnection); // checker le nom de table de db user
            commandUser.ExecuteNonQuery();
            SQLiteDataReader readerUser = commandUser.ExecuteReader();
            nbColUser = readerUser.FieldCount;

            SQLiteCommand command = new SQLiteCommand("SELECT * FROM tracks", _dbConnection);
            command.ExecuteNonQuery();
            SQLiteDataReader reader = command.ExecuteReader();
            nbCol = reader.FieldCount;

            if (nbColUser == nbCol)
            {
                for (int i = 0; i < nbCol; i++)
                {
                    if (readerUser.GetName(i) == reader.GetName(i) && readerUser.GetFieldType(i) == reader.GetFieldType(i))
                    {
                    }
                    else
                    {
                        _dbConnection.Close();
                        dbUserConnection.Close();
                        return false;
                    }
                }
            }
            else
            {
                _dbConnection.Close();
                dbUserConnection.Close();
                return false;
            }

            _dbConnection.Close();
            dbUserConnection.Close();
            return true;
        }

        private bool IsInDataBase(string checksumUser)
        {
            _dbConnection.Open();

            const string query = "SELECT checksum FROM tracks";
            var command = new SQLiteCommand(query, _dbConnection);
            command.ExecuteNonQuery();
            var reader = command.ExecuteReader();

            while (reader.Read())
            {
                if (reader.GetString(0).Equals(checksumUser))
                {
                    _dbConnection.Close();
                    return true;
                }
            }

            _dbConnection.Close();
            return false;
        }


        public void ExportDataBase(string pathUser)
        {
            _dbConnection.Open();

            SQLiteConnection.CreateFile(pathUser);
            SQLiteConnection dbUserConnection = new SQLiteConnection("Data Source=" + pathUser + ";Version=3;");
            dbUserConnection.Open();

            try
            {
                // Creation of the user database
                const string query = "CREATE TABLE tracks (id INTEGER PRIMARY KEY AUTOINCREMENT, checksum TEXT, "
                                     + "duration TEXT, bpm TEXT, key TEXT, danceability TEXT, samplerate TEXT, beats TEXT, fadeins TEXT, fadeouts TEXT)";
                SQLiteCommand commandUser = new SQLiteCommand(query, dbUserConnection);
                commandUser.ExecuteNonQuery();
            }
            catch (Exception e)
            {
                System.Diagnostics.Debug.WriteLine("DB ERROR when trying to create tracks table" + e.Message);
            }

            // Copy of the database in the database user
            SQLiteCommand command = new SQLiteCommand("SELECT * FROM tracks", _dbConnection);
            command.ExecuteNonQuery();
            SQLiteDataReader reader = command.ExecuteReader();
            while (reader.Read())
            {
                string queryUser = "INSERT INTO tracks VALUES (" + reader.GetString(0) + ","
                    + reader.GetString(1) + ","
                    + reader.GetString(2) + ","
                    + reader.GetString(3) + ","
                    + reader.GetString(4) + ","
                    + reader.GetString(5) + ","
                    + reader.GetString(6) + ","
                    + reader.GetString(7) + ","
                    + reader.GetString(8) + ","
                    + reader.GetString(9) + ")"; // ATTENTION ';' DS REQUETE SQL A METTRE OU PAS ?
                SQLiteCommand commandUser = new SQLiteCommand(queryUser, dbUserConnection);
                commandUser.ExecuteNonQuery();
            }

            _dbConnection.Close();
            dbUserConnection.Close();
        }
    }
}