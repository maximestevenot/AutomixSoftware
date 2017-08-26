// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using Automix_Data_Management.Model;
using NAudio.Lame;
using NAudio.Wave;
using System;
using System.Collections.Generic;
using System.IO;
using System.Security.Cryptography;
using System.Text;

namespace Automix_Data_Management
{
    /// <summary>
    /// Provides some tools to manipulate audio files
    /// </summary>
    public class AudioIO
    {
        /// <summary>
        /// Format of temp WAV files
        /// </summary>
        public static WaveFormat TempWaveFormat => WaveFormat.CreateIeeeFloatWaveFormat(44100, 2);

        /// <summary>
        /// Quality of the exported MP3 file
        /// </summary>
        public static LAMEPreset ExportQuality { get; set; }

        /// <summary>
        /// Static constructor which initialize properties
        /// </summary>
        static AudioIO()
        {
            ExportQuality = LAMEPreset.INSANE;
        }

        /// <summary>
        /// Export a <c>TrackCollection</c> as text file containing all information
        /// </summary>
        /// <param name="trackCollection">The collection to export</param>
        /// <param name="outputFile">The path of the destination file</param>
        public static void TextExport(TrackCollection trackCollection, string outputFile)
        {
            var sw = new StreamWriter(outputFile);
            sw.WriteLine("Playlist created with Automix Software");
            foreach (var t in trackCollection)

            {
                sw.WriteLine(t.Name + " | " + t.DisplayDuration() + " | " + t.Bpm + " | " + t.Key);
            }
            sw.Flush();
            sw.Close();
        }

        /// <summary>
        /// Convert an MP3 into WAV file
        /// </summary>
        /// <param name="inputFile">The path of the MP3 file</param>
        /// <param name="outputFile">The path of the WAV file</param>
        public static void Mp3ToWav(string inputFile, string outputFile)
        {
            var reader = new Mp3FileReader(inputFile);
            WaveFileWriter.CreateWaveFile(outputFile, reader);
        }

        /// <summary>
        /// Convert a WAV into MP3 file
        /// </summary>
        /// <param name="inputFile">Input WAV files path</param>
        /// <param name="outputFile">Output MP3 file path</param>
        /// <param name="id3Tag">MP3 tags</param>
        public static void WavToMp3(string inputFile, string outputFile, ID3TagData id3Tag)
        {
            var reader = new WaveFileReader(inputFile);
            var writer = new LameMP3FileWriter(outputFile, reader.WaveFormat, ExportQuality, id3Tag);
            reader.CopyTo(writer);
            writer.Close();
            reader.Close();
        }

        /// <summary>
        /// Convert a WAV into MP3 file
        /// </summary>
        /// <param name="inputFile">Input WAV files path</param>
        /// <param name="outputFile">Output MP3 file path</param>
        public static void WavToMp3(string inputFile, string outputFile)
        {
            WavToMp3(inputFile, outputFile, null);
        }

        /// <summary>
        /// Concat a list of WAV in a MP3 file
        /// </summary>
        /// <param name="inputFiles">List of input WAV files paths</param>
        /// <param name="outputFile">Output MP3 file path</param>
        /// <param name="id3Tag">MP3 tags</param>
        public static void WavToMp3(List<string> inputFiles, string outputFile, ID3TagData id3Tag)
        {
            var writer = new LameMP3FileWriter(outputFile, TempWaveFormat, ExportQuality, id3Tag);

            foreach (var inputFile in inputFiles)
            {
                var reader = new WaveFileReader(inputFile);
                reader.CopyTo(writer);
                reader.Close();
            }
            writer.Flush();
            writer.Close();
        }

        /// <summary>
        /// Concat a list of WAV in a MP3 file
        /// </summary>
        /// <param name="inputFiles">List of input WAV files paths</param>
        /// <param name="outputFile">Output MP3 file path</param>
        public static void WavToMp3(List<string> inputFiles, string outputFile)
        {
            WavToMp3(inputFiles, outputFile, null);
        }

        /// <summary>
        /// Compute the MD5 hash of an MP3 file
        /// </summary>
        /// <param name="path">The path of the MP3 file</param>
        /// <returns>The Hash in a <c>string</c></returns>
        public static string Mp3Md5Hash(string path)
        {
            Mp3FileReader reader;
            try
            {
                reader = new Mp3FileReader(path);
            }
            catch (InvalidOperationException ex)
            {
                System.Diagnostics.Debug.WriteLine($@"Error when reading {path}");
                System.Diagnostics.Debug.WriteLine(ex.Message);
                return string.Empty;
            }

            Mp3Frame frame;
            var audioData = new byte[0];
            var readFrame = 0;
            var nbFrames = (int)reader.Length / 1152 / 4 / 1000 + 1;

            while ((frame = reader.ReadNextFrame()) != null)
            {
                if (readFrame == 0)
                {
                    var originalLength = audioData.Length;
                    Array.Resize(ref audioData, originalLength + frame.RawData.Length);
                    Array.Copy(frame.RawData, 0, audioData, originalLength, frame.RawData.Length);
                }
                readFrame = (readFrame + 1) % nbFrames;
            }

            var md5Hash = MD5.Create();
            var audioDataHash = md5Hash.ComputeHash(audioData);
            var sBuilder = new StringBuilder();

            foreach (var b in audioDataHash)
            {
                sBuilder.Append(b.ToString("x2"));
            }

            return sBuilder.ToString();
        }

        /// <summary>
        /// Create a <c>NAudio.Lame.ID3TagData</c> for a specified MP3 file
        /// </summary>
        /// <param name="outputFile">The path of the MP3 file</param>
        /// <returns> A new <c>NAudio.Lame.ID3TagData</c></returns>
        public static ID3TagData CreateId3TagData(string outputFile)
        {
            return new ID3TagData
            {
                Title = outputFile.Substring(outputFile.LastIndexOf("\\", StringComparison.Ordinal) + 1,
                     outputFile.LastIndexOf(".mp3", StringComparison.Ordinal) -
                     outputFile.LastIndexOf("\\", StringComparison.Ordinal) - 1),
                Artist = Environment.UserName,
                Album = "Automix Software Compilation",
                Year = DateTime.Now.Year.ToString(),
                Comment = "Created with Automix Software",
                Genre = "Mix"
            };
        }

        /// <summary>
        /// Create a <c>NAudio.Wave.Id3v2Tag</c> for a specified MP3 file
        /// </summary>
        /// <param name="outputFile">The path of the MP3 file</param>
        /// <returns> A new <c>NAudio.Wave.Id3v2Tag</c></returns>
        public static Id3v2Tag CreateId3V2Tag(string outputFile)
        {
            var data = CreateId3TagData(outputFile);
            var tags = new Dictionary<string, string>
            {
                { "TIT2", data.Title },
                { "TPE1", data.Artist },
                { "TALB", data.Album },
                { "TCON", data.Genre },
                { "TYER", data.Year },
                { "TENC", "Automix Software with NAudio API" },
                { "COMM", data.Comment }
            };

            return Id3v2Tag.Create(tags);
        }
    }
}
