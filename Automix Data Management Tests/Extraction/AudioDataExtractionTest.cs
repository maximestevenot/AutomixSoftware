// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using System.IO;
using Automix_Data_Management.Extraction;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Automix_Data_Management_Tests.Extraction
{
    [TestClass]
    public class AudioDataExtractionTest
    {
        [TestMethod]
        public void TestExtractionInitialization()
        {
            new AudioDataExtractionProxy();
            Assert.IsTrue(Directory.Exists(TestConstant.TempDirPath));
            Assert.IsTrue(File.Exists(TestConstant.TempDirPath + "\\profile.yaml"));
        }
    }
}
