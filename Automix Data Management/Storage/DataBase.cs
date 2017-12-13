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
using log4net;

namespace Automix_Data_Management.Storage
{
    public class DataBase
    {
        private SQLiteConnection _dbConnection;

        private static readonly log4net.ILog log = log4net.LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);

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
                log.Debug("DB ERROR when trying to insert :" + track.Path + e.Message, e);
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

                log.Debug("DB ERROR when trying to clean database" + e.Message, e);
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
                log.Debug("DB ERROR when trying to extract data of : " + track.Path + e.Message, e);
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
                log.Debug("DB ERROR when trying to isPresent: " + track.Path + e.Message, e);
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
                log.Debug("DB ERROR when trying to create tracks table" + e.Message, e);
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





        public void ImportDataBase(String pathDbUser)
        {
            _dbConnection.Open();
            SQLiteConnection dbUserConnection = new SQLiteConnection("Data Source=" + pathDbUser + ";Version=3;");
            dbUserConnection.Open();

            if (CheckColumnsProperties(dbUserConnection))
            {
                SQLiteCommand commandUser = new SQLiteCommand("SELECT * FROM tracks;", dbUserConnection); // checker nom table db user
                commandUser.ExecuteNonQuery();
                SQLiteDataReader readerUser = commandUser.ExecuteReader();
                
                while (readerUser.Read())
                {
                    string checksumUser = readerUser.GetString(1);
                    if (!IsInDataBase(checksumUser))
                    {
                        string query = "INSERT INTO tracks (checksum, duration, bpm, key, danceability, samplerate, beats, fadeins, fadeouts) VALUES "
                            + "('" + checksumUser + "',"
                            + "'" + readerUser.GetString(2) + "',"
                            + "'" + readerUser.GetString(3) + "',"
                            + "'" + readerUser.GetString(4) + "',"
                            + "'" + readerUser.GetString(5) + "',"
                            + "'" + readerUser.GetString(6) + "',"
                            + "'" + readerUser.GetString(7) + "',"
                            + "'" + readerUser.GetString(8) + "',"
                            + "'" + readerUser.GetString(9) + "');";
                        SQLiteCommand command = new SQLiteCommand(query, _dbConnection);
                        command.ExecuteNonQuery();
                    }
                }
            }
            else
            {
                throw new System.ArgumentException("User database to import hasn't the same format than the software database\n");
            }

            dbUserConnection.Close();
            _dbConnection.Close();
        }

        private bool CheckColumnsProperties(SQLiteConnection dbUserConnection)
        {
            SQLiteCommand commandUser = new SQLiteCommand("SELECT * FROM tracks;", dbUserConnection); // checker le nom de table de db user
            commandUser.ExecuteNonQuery();
            SQLiteDataReader readerUser = commandUser.ExecuteReader();
            int nbColUser = readerUser.FieldCount;

            SQLiteCommand command = new SQLiteCommand("SELECT * FROM tracks;", _dbConnection);
            command.ExecuteNonQuery();
            SQLiteDataReader reader = command.ExecuteReader();
            int nbCol = reader.FieldCount;

            if (nbColUser == nbCol)
            {
                for (int i = 0; i < nbCol; i++)
                {
                    if (readerUser.GetName(i) == reader.GetName(i) && readerUser.GetFieldType(i) == reader.GetFieldType(i))
                    {
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else
            {
                return false;
            }

            return true;
        }

        private bool IsInDataBase(string checksumUser)
        {
            const string query = "SELECT checksum FROM tracks;";
            var command = new SQLiteCommand(query, _dbConnection);
            command.ExecuteNonQuery();
            var reader = command.ExecuteReader();

            while (reader.Read())
            {
                if (reader.GetString(0).Equals(checksumUser))
                {
                    return true;
                }
            }

            return false;
        }

        public bool ChecksumsAreInDataBase(SQLiteConnection dbUserConnection)
        {
            dbUserConnection.Open();
            const string queryUser = "SELECT checksum FROM tracks;";
            var commandUser = new SQLiteCommand(queryUser, dbUserConnection);
            commandUser.ExecuteNonQuery();
            var readerUser = commandUser.ExecuteReader();

            while (readerUser.Read())
            {
                var checksumUser = readerUser.GetString(0);
                if (!IsInDataBase(checksumUser))
                {
                    dbUserConnection.Close();
                    return false;
                }
            }

            dbUserConnection.Close();
            return true;
        }


        public void ExportDataBase(string pathDbUser)
        {
            _dbConnection.Open();

            // Creation of the user database file .db 
            SQLiteConnection.CreateFile(pathDbUser);
            SQLiteConnection dbUserConnection = new SQLiteConnection("Data Source=" + pathDbUser + ";Version=3;");
            dbUserConnection.Open();

            // Creation of the user database with the same format than the software database
            try
            {
                const string query = "CREATE TABLE tracks (id INTEGER PRIMARY KEY AUTOINCREMENT, checksum TEXT, "
                                     + "duration TEXT, bpm TEXT, key TEXT, danceability TEXT, samplerate TEXT, beats TEXT, fadeins TEXT, fadeouts TEXT)";
                SQLiteCommand commandUser = new SQLiteCommand(query, dbUserConnection);
                commandUser.ExecuteNonQuery();
            }
            catch (Exception e)
            {
                System.Diagnostics.Debug.WriteLine("DB ERROR when trying to create tracks table" + e.Message);
            }

            // Copy the software database in the database user
            SQLiteCommand command = new SQLiteCommand("SELECT * FROM tracks", _dbConnection);
            command.ExecuteNonQuery();
            SQLiteDataReader reader = command.ExecuteReader();
            while (reader.Read())
            {
                string queryUser = "INSERT INTO tracks (checksum, duration, bpm, key, danceability, samplerate, beats, fadeins, fadeouts) VALUES "
                    + "('" + reader.GetString(1) + "',"
                    + "'" + reader.GetString(2) + "',"
                    + "'" + reader.GetString(3) + "',"
                    + "'" + reader.GetString(4) + "',"
                    + "'" + reader.GetString(5) + "',"
                    + "'" + reader.GetString(6) + "',"
                    + "'" + reader.GetString(7) + "',"
                    + "'" + reader.GetString(8) + "',"
                    + "'" + reader.GetString(9) + "');";
                SQLiteCommand commandUser = new SQLiteCommand(queryUser, dbUserConnection);
                commandUser.ExecuteNonQuery();
            }

            dbUserConnection.Close();
            _dbConnection.Close();
        }
    }
}