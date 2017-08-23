using System.IO;
using NAudio.Wave;
using AutomixDataManagement.Model;

namespace AutomixDataManagement
{
    /// <summary>
    /// Provides some tools to manipulate audio files
    /// </summary>
    public class AudioIO
    {
        public static void TextExport(TrackCollection trackCollection, string outputFile)
        {
            StreamWriter sw = new StreamWriter(outputFile);
            sw.WriteLine("Playlist created with Automix Software");
            foreach(var t in trackCollection)

            {
                sw.WriteLine(t.Name + " | " + t.DisplayDuration() + " | " + t.BPM + " | " + t.Key);
            }
            sw.Flush();
            sw.Close();
        }

        public static void Mp3ToWav(string inputFile, string outputFile)
        {
            var reader = new Mp3FileReader(inputFile);
            WaveFileWriter.CreateWaveFile(outputFile, reader);
        }
    }
}
