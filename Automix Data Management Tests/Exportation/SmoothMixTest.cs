using Automix_Data_Management.Exportation;
using Automix_Data_Management.Model;
// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Automix_Data_Management.Exportation.Tests
{
    [TestClass()]
    public class SmoothMixTest
    {
        [TestMethod()]
        public void TestExportMix()
        {
            SmoothMix mix = new SmoothMix();
            System.ComponentModel.BackgroundWorker bw = new System.ComponentModel.BackgroundWorker();
            TrackCollection tc = new TrackCollection();
            Track track = new Track();
            tc.Add(track);
            mix.ExportMix(bw, tc, "string");
        }
    }
}
