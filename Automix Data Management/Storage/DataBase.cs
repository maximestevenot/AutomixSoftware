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
    }
}