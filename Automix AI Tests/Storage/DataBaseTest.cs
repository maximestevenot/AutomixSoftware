// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using Automix_Data_Management.Model;
using Automix_Data_Management.Storage;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Automix_AI_Tests.Storage
{

    [TestClass]
    public class DataBaseTest
    {
        private static readonly string _path = "automix_software_collection_test.db";
        private readonly Track _testTrack = new Track("test.mp3", "checksum") { Bpm = 128, Key = "6d", Beats = new int[] { 1, 2, 3 }, FadeIns = new int[] { 2, 3, 5 }, FadeOuts = new int[] { 3, 4, 6 }, Danceability = 3, Duration = 1000, Samplerate = 44100 };
        private static DataBase _testDataBase;

        [TestInitialize]
        public void TestSetup()
        {
            _testDataBase = new DataBase(_path);
            _testDataBase.Clear();
        }

        [TestMethod]
        public void AddTrackIntoDataBaseTest()
        {
            Assert.IsFalse(_testDataBase.IsInDataBase(_testTrack));
            _testDataBase.AddTrack(_testTrack);
            Assert.IsTrue(_testDataBase.IsInDataBase(_testTrack));
        }

        //TODO clear failing
        //[TestMethod]
        /*public void RemoveTrackIntoDataBaseTest()
        {
            _testDataBase.AddTrack(_testTrack);
            Assert.IsTrue(_testDataBase.IsInDataBase(_testTrack));
            /_testDataBase.Clear();
            Assert.IsFalse(_testDataBase.IsInDataBase(_testTrack));
        }*/


    }
}
