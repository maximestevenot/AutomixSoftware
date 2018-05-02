// Copyright (C) 2016 - 2018 LesProjecteurs
// This file is part of Automix Software licensed under MIT License.

using System;
using Automix_Data_Management.Model;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Automix_Data_Management_Tests.Model
{
    [TestClass]
    public class TrackCollectionTest
    {
        private static Track _testTrack;

        [ClassInitialize]
        public static void InitializeTests(TestContext testContext)
        {
            _testTrack = new Track(TestConstant.TestFilePath, TestConstant.TestCheckSum)
            {
                Bpm = 128,
                Key = "6d",
                Beats = new[] { 1, 2, 3 },
                FadeIns = new[] { 2, 3, 5 },
                FadeOuts = new[] { 3, 4, 6 },
                Danceability = 3,
                Duration = 1000,
                Samplerate = 44100
            };
        }

        [TestMethod]
        public void TestSafeAdd()
        {
            var originalCollection = new TrackCollection();
            Assert.AreEqual(originalCollection.Count, 0);
            originalCollection.SafeAdd(_testTrack);
            Assert.AreEqual(originalCollection.Count, 1);
            originalCollection.SafeAdd(_testTrack);
            Assert.AreEqual(originalCollection.Count, 1);
        }

        [TestMethod]
        public void TestIsPresent()
        {
            var originalCollection = new TrackCollection();
            Assert.IsFalse(originalCollection.IsPresent(_testTrack));
            originalCollection.Add(_testTrack);
            Assert.IsTrue(originalCollection.IsPresent(_testTrack));
        }

        [TestMethod]
        public void TestSearch()
        {
            var originalCollection = new TrackCollection { _testTrack };
            var extractedTrack = originalCollection.Search(_testTrack.Path);
            Assert.AreSame(_testTrack, extractedTrack);
        }

        [TestMethod]
        public void TestCopyFrom()
        {
            var originalCollection = new TrackCollection { _testTrack };
            var copiedCollection = TrackCollection.CopyFrom(originalCollection);

            Assert.AreNotSame(originalCollection, copiedCollection);

            var originalFirstTrack = originalCollection[0];
            var copiedFirstTrack = copiedCollection[0];

            Assert.AreNotSame(originalFirstTrack, copiedFirstTrack);
            Assert.AreNotSame(originalFirstTrack.Beats, copiedFirstTrack.Beats);
            Assert.AreNotSame(originalFirstTrack.FadeIns, copiedFirstTrack.FadeIns);
            Assert.AreNotSame(originalFirstTrack.FadeOuts, copiedFirstTrack.FadeOuts);

            Assert.AreEqual(originalFirstTrack.Duration, copiedFirstTrack.Duration);
            Assert.AreEqual(originalFirstTrack.Bpm, copiedFirstTrack.Bpm);
            Assert.AreEqual(originalFirstTrack.Key, copiedFirstTrack.Key);
            Assert.AreEqual(originalFirstTrack.Samplerate, copiedFirstTrack.Samplerate);
            Assert.AreEqual(originalFirstTrack.Danceability, copiedFirstTrack.Danceability);

            for (var i = 0; i < 3; i++)
            {
                Assert.AreEqual(originalFirstTrack.Beats[i], copiedFirstTrack.Beats[i]);
                Assert.AreEqual(originalFirstTrack.FadeIns[i], copiedFirstTrack.FadeIns[i]);
                Assert.AreEqual(originalFirstTrack.FadeOuts[i], copiedFirstTrack.FadeOuts[i]);
            }
        }

        [TestMethod]
        public void TestRemove()
        {
            var myCollection = new TrackCollection { _testTrack };
            myCollection.Remove(_testTrack.Path);
            Assert.IsFalse(myCollection.IsPresent(_testTrack));
        }

        [TestMethod]
        public void TestSortByName()
        {
            var myCollection = new TrackCollection
            {
                new Track("test1.mp3", TestConstant.TestCheckSum),
                new Track("test3.mp3", TestConstant.TestCheckSum + "1"),
                new Track("test2.mp3", TestConstant.TestCheckSum + "2")
            };

            myCollection.SortByName();

            Assert.IsTrue(string.Compare(myCollection[0].Name, myCollection[1].Name, StringComparison.Ordinal) < 0);
            Assert.IsTrue(string.Compare(myCollection[1].Name, myCollection[2].Name, StringComparison.Ordinal) < 0);
        }
    }
}
