// Copyright (C) 2016 - 2018 LesProjecteurs
// This file is part of Automix Software licensed under MIT License.

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
