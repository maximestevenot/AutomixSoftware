// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

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

        [ClassInitialize()]
        public static void InitializeFields(TestContext testContext)
        {
            var track1 = new Track()
            {
                Bpm = 128,
                Key = "6d",
                isFixed = false
            };

            var track2 = new Track()
            {
                Bpm = 150,
                Key = "6m",
                isFixed = true
            };

            var track3 = new Track()
            {
                Bpm = 128,
                Key = "6m",
                isFixed = false
            };

            var track4 = new Track()
            {
                Bpm = 120,
                Key = "3m",
                isFixed = true
            };

            var track5 = new Track()
            {
                Bpm = 60,
                Key = "1d",
                isFixed = false
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
