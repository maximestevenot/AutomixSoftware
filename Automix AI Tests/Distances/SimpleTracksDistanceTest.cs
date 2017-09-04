// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using Microsoft.VisualStudio.TestTools.UnitTesting;
using Automix_AI.Distances;
using Automix_Data_Management.Model;

namespace Automix_AI_Tests.Distances
{
    [TestClass]
    public class SimpleTracksDistanceTest
    {
        [TestMethod]
        public void TestCompute()
        {
            ITracksDistance distance = new SimpleTracksDistance();

            var track1 = new Track()
            {
                Bpm = 128,
                Key = "6d"
            };

            var track2 = new Track()
            {
                Bpm = 150,
                Key = "6m"
            };

            var track3 = new Track()
            {
                Bpm = 128,
                Key = "6m"
            };


            var value1 = distance.Compute(track1, track2);
            Assert.IsTrue(value1 >= 0);

            var value2 = distance.Compute(track1, track3);
            Assert.IsTrue(value2 >= 0);
            Assert.IsTrue(value1 >= value2);
        }
    }
}
