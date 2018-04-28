// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Threading;
using Automix_Data_Management.Model;
using Automix_Data_Management.Storage;
using log4net;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

namespace Automix_Data_Management.Extraction
{
    internal class ExecutableExtraction : IExtraction
    {
        private readonly ProcessStartInfo _startInfo;
        private readonly ProcessStartInfo _startInfoFade;
        private readonly DirectoryInfo _tempDirectory;

        private static readonly ILog log = LogManager.GetLogger(MethodBase.GetCurrentMethod().DeclaringType);

        public ExecutableExtraction(DirectoryInfo tempDirectory)
        {
            _tempDirectory = tempDirectory;

            var extractorpath = Directory.GetCurrentDirectory() + "\\essentia_streaming_extractor_music.exe";
            _startInfo = new ProcessStartInfo(extractorpath)
            {
                UseShellExecute = false,
                WorkingDirectory = _tempDirectory.FullName,
                WindowStyle = ProcessWindowStyle.Hidden,
                CreateNoWindow = true
            };

            extractorpath = Directory.GetCurrentDirectory() + "\\essentia_standard_fadedetection.exe";
            _startInfoFade = new ProcessStartInfo(extractorpath)
            {
                UseShellExecute = false,
                WorkingDirectory = _tempDirectory.FullName,
                WindowStyle = ProcessWindowStyle.Hidden,
                CreateNoWindow = true,
                RedirectStandardOutput = true
            };
        }

        public void ExtractData(BackgroundWorker backgroundWorker, int nbTracks, CancellationTokenSource cancellationTokenSource,
            Track track)
        {
            ExtractDataFromExecResult(backgroundWorker, cancellationTokenSource, track);

            if (backgroundWorker.CancellationPending || track.Duration <= 0)
            {
                return;
            }

            ExtractFadesFromExecResult(backgroundWorker, cancellationTokenSource, track);

            if (backgroundWorker.CancellationPending || track.FadeOuts == null)
            {
                return;
            }

            var dataBase = new DataBase();
            dataBase.AddTrack(track);

            Interlocked.Increment(ref AudioDataExtraction.ExploredTracks);
            backgroundWorker.ReportProgress(250 + 750 * AudioDataExtraction.ExploredTracks / nbTracks);
        }

        private void ExtractFadesFromExecResult(BackgroundWorker bw, CancellationTokenSource cancellationTokenSource,
            Track track)
        {
            _startInfoFade.Arguments = "\"" + track.Path + "\"";
            var fadeExtractor = new Process { StartInfo = _startInfoFade };
            fadeExtractor.Start();

            while (!bw.CancellationPending && !fadeExtractor.HasExited)
            {
                Thread.Sleep(100);
            }
            if (bw.CancellationPending && !fadeExtractor.HasExited)
            {
                fadeExtractor.Kill();
                cancellationTokenSource.Cancel();
            }
            else if (!bw.CancellationPending)
            {
                Thread.Sleep(100);
                ReadFades(fadeExtractor, track);
            }
        }

        private void ExtractDataFromExecResult(BackgroundWorker bw, CancellationTokenSource cancellationTokenSource,
            Track track)
        {
            _startInfo.Arguments = "\"" + track.Path + "\" \"" + track.Id + ".json\" \"" + _tempDirectory.FullName +
                                   "\\profile.yaml\"";
            var extractor = new Process { StartInfo = _startInfo };
            extractor.Start();

            while (!bw.CancellationPending && !extractor.HasExited)
            {
                Thread.Sleep(100);
            }
            if (bw.CancellationPending && !extractor.HasExited)
            {
                extractor.Kill();
                cancellationTokenSource.Cancel();
            }
            else if (!bw.CancellationPending)
            {
                Thread.Sleep(50);
                try
                {
                    ReadDataFromJson(track);
                }
                catch (FileNotFoundException e)
                {
                    log.Debug(e.Message, e);
                    Debug.WriteLine(e.Message);
                }
            }
        }

        private static void ReadFades(Process fadeExtractor, Track track)
        {
            var reader = fadeExtractor.StandardOutput;
            var output = reader.ReadToEnd();

            char[] separators = { ' ', ',', '[', ']', '\n' };
            var fadeInIndex = output.IndexOf("fade ins:", StringComparison.Ordinal);
            var fadeOutIndex = output.IndexOf("fade outs:", StringComparison.Ordinal);

            var fadeInList = new List<int>();
            if (fadeInIndex == -1)
            {
                fadeInList.Add(0);
            }
            else
            {
                var upperBound = fadeOutIndex == -1 ? output.Length : fadeOutIndex;
                var fadeInString = output.Substring(fadeInIndex + 9, upperBound - fadeInIndex - 9);
                var fadeInValues = fadeInString.Split(separators, StringSplitOptions.RemoveEmptyEntries);

                FeedListWithValues(fadeInList, fadeInValues);
            }

            track.FadeIns = fadeInList.ToArray();

            var fadeOutList = new List<int>();
            if (fadeOutIndex == -1)
            {
                fadeOutList.Add(track.Duration);
            }
            else
            {
                var fadeOutString = output.Substring(fadeOutIndex + 10);
                var fadeOutValues = fadeOutString.Split(separators, StringSplitOptions.RemoveEmptyEntries);

                FeedListWithValues(fadeOutList, fadeOutValues);
            }
            track.FadeOuts = fadeOutList.ToArray();
            reader.Close();
        }

        private static void FeedListWithValues(ICollection<int> list, IEnumerable<string> values)
        {
            foreach (var value in values)
            {
                var isParsed = double.TryParse(value, NumberStyles.Number,
                    CultureInfo.CreateSpecificCulture("en-US"), out double resultPtr);
                if (isParsed)
                {
                    list.Add((int) (resultPtr * 1000));
                }
            }
        }

        private void ReadDataFromJson(Track track)
        {
            var file = File.OpenText(_tempDirectory.FullName + "\\" + track.Id + ".json");
            var reader = new JsonTextReader(file);
            var jObject = (JObject)JToken.ReadFrom(reader);

            track.Duration = (int)((double)jObject["metadata"]["audio_properties"]["length"] * 1000);
            track.Bpm = (int)(jObject["rhythm"]["bpm"]);

            var key = (string)(jObject["tonal"]["key_key"]);
            var scale = (string)(jObject["tonal"]["key_scale"]);
            track.Key = Utils.ConvertToOpenKey(key, scale);

            track.Danceability = (double)jObject["rhythm"]["danceability"];
            track.Samplerate = (int)jObject["metadata"]["audio_properties"]["sample_rate"];

            var beatsList = JArray.FromObject(jObject["rhythm"]["beats_position"]).ToObject<List<double>>();
            track.Beats = beatsList.ConvertAll(b => (int)(b * 1000)).ToArray();

            reader.Close();
            file.Close();
        }
    }
}