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
        private static string _pathTrackSingleIn = "FadeInx1.mp3"; //"../../testsSingleFades/FadeInx1.mp3";
        private static string _pathTrackSingleOut = "FadeOutx1.mp3"; //"../../testsSingleFades/FadeOutx1.mp3";
        private static string _pathTrackSingleInOut = "FadeInx1FadeOutx1.mp3"; //= "../../testsSingleFades/FadeInx1FadeOutx1.mp3";
        private static string _outputFile = "testSmoothMix";
        private static string _checksum1 = "0001";
        private static string _checksum2 = "0002";
        private static string _checksum3 = "0003";
        private static TrackCollection _collection;
        private static SmoothMix _mix;
        private static Track _track1;
        private static Track _track2;
        private static Track _track3;

        [ClassInitialize()]
        public static void InitializeTracks(TestContext testContent)
        {
            _track1 = new Track(_pathTrackSingleIn, _checksum1)
            {
                Bpm = 128,
                Key = "6d",
                Beats = new[] { 1, 2, 3 },
                FadeIns = new[] { 2 },
                FadeOuts = new[] { 3, 4, 6 },
                Danceability = 3,
                Duration = 1000,
                Samplerate = 44100
            };

            _track2 = new Track(_pathTrackSingleOut, _checksum2)
            {
                Bpm = 128,
                Key = "6d",
                Beats = new[] { 1, 2, 3 },
                FadeIns = new[] { 2 },
                FadeOuts = new[] { 3 },
                Danceability = 3,
                Duration = 2000,
                Samplerate = 44100
            };

            _track3 = new Track(_pathTrackSingleInOut, _checksum3)
            {
                Bpm = 128,
                Key = "6d",
                Beats = new[] { 1, 2, 3 },
                FadeIns = new[] { 2 },
                FadeOuts = new[] { 3 },
                Danceability = 3,
                Duration = 3000,
                Samplerate = 44100
            };

        }


        [TestMethod()]
        public void TestExportMix()
        {
            _collection = new TrackCollection();
            var track1 = new Track(_pathTrackSingleIn);
            var track2 = new Track(_pathTrackSingleOut);
            var track3 = new Track(_pathTrackSingleInOut);
            _collection.Add(track1);
            _collection.Add(track2);
            _collection.Add(track3);
            
            //_mix = new SmoothMix();
            //System.ComponentModel.BackgroundWorker bw = new System.ComponentModel.BackgroundWorker();
            //_mix.ExportMix(bw, _collection, _outputFile);
        }
    }
}
