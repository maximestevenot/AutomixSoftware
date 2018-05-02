// Copyright (C) 2016 - 2018 LesProjecteurs
// This file is part of Automix Software licensed under MIT License.

using System.ComponentModel;
using Automix_AI.Distances;
using Automix_AI.Sort_Algorithms;
using Automix_Data_Management.Model;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Automix_AI_Tests.Sort_Alogirthms
{
    [TestClass]
    public class SimulatedAnnealingSortAlgorithmTest
    {
        private static TrackCollection _trackCollection;
        private static BackgroundWorker _backgroundWorker;

        [ClassInitialize]
        public static void InitializeFields(TestContext testContext)
        {
            var track1 = new Track
            {
                Bpm = 128,
                Key = "6d",
                IsFixed = false
            };

            var track2 = new Track
            {
                Bpm = 150,
                Key = "6m",
                IsFixed = true
            };

            var track3 = new Track
            {
                Bpm = 128,
                Key = "6m",
                IsFixed = false
            };

            var track4 = new Track
            {
                Bpm = 120,
                Key = "3m",
                IsFixed = true
            };

            var track5 = new Track
            {
                Bpm = 60,
                Key = "1d",
                IsFixed = false
            };

            _trackCollection = new TrackCollection { track1, track2, track3, track4, track5 };

            _backgroundWorker = new BackgroundWorker
            {
                WorkerReportsProgress = true,
                WorkerSupportsCancellation = true
            };
        }

        [TestMethod]
        public void TestSortWithSimpleDistance()
        {
            Assert.IsNotNull(_trackCollection, "TrackCollection not initialized");
            Assert.IsNotNull(_backgroundWorker, "BackgroundWorker not initialized");

            var sortAlgorithm = new SimulatedAnnealingSortAlgorithm(new SimpleTracksDistance());
            var resultTrackCollection = sortAlgorithm.Sort(_backgroundWorker, _trackCollection);

            Assert.AreEqual(_trackCollection.Count, resultTrackCollection.Count);
        }

        [TestMethod]
        public void TestFixedTrackPosition()
        {
            Assert.IsNotNull(_trackCollection, "TrackCollection not initialized");
            Assert.IsNotNull(_backgroundWorker, "BackgroundWorker not initialized");

            var sortAlgorithm = new SimulatedAnnealingSortAlgorithm(new SimpleTracksDistance());
            var resultTrackCollection = sortAlgorithm.Sort(_backgroundWorker, _trackCollection);
            

            Assert.AreEqual(resultTrackCollection[1], _trackCollection[1]);
            Assert.AreEqual(resultTrackCollection[3], _trackCollection[3]);
        }
    }
}
