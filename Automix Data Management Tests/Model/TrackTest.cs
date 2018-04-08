using Automix_Data_Management.Model;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Automix_Data_Management_Tests.Model
{
    [TestClass]
    public class TrackTest
    {
        [TestMethod]
        public void TestCopyFrom()
        {
            var originalTrack = new Track(TestConstant.TestFilePath, TestConstant.TestCheckSum)
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

            var copiedTrack = Track.CopyFrom(originalTrack);

            Assert.AreNotSame(originalTrack, copiedTrack);
            Assert.AreNotSame(originalTrack.Beats, copiedTrack.Beats);
            Assert.AreNotSame(originalTrack.FadeIns, copiedTrack.FadeIns);
            Assert.AreNotSame(originalTrack.FadeOuts, copiedTrack.FadeOuts);

            Assert.AreEqual(originalTrack.Duration, copiedTrack.Duration);
            Assert.AreEqual(originalTrack.Bpm, copiedTrack.Bpm);
            Assert.AreEqual(originalTrack.Key, copiedTrack.Key);
            Assert.AreEqual(originalTrack.Samplerate, copiedTrack.Samplerate);
            Assert.AreEqual(originalTrack.Danceability, copiedTrack.Danceability);

            for (var i = 0; i < 3; i++)
            {
                Assert.AreEqual(originalTrack.Beats[i], copiedTrack.Beats[i]);
                Assert.AreEqual(originalTrack.FadeIns[i], copiedTrack.FadeIns[i]);
                Assert.AreEqual(originalTrack.FadeOuts[i], copiedTrack.FadeOuts[i]);
            }
        }
    }
}
