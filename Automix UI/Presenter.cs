// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using Automix_AI.Distances;
using Automix_AI.Sort_Algorithms;
using Automix_Data_Management;
using Automix_Data_Management.Audio_Playing;
using Automix_Data_Management.Extraction;
using Automix_Data_Management.Model;
using Automix_Data_Management.Storage;
using static Automix_Data_Management.Utils;
using log4net;
using System;

namespace Automix_UI
{
    internal class Presenter
    {
        private readonly List<IViewWithTrackCollection> _views;
        private TrackCollection _trackCollection;

        private readonly IAudioDataExtraction _dataExtractionEngine;
        private readonly AbstractSortAlgorithm _sortAlgorithm;
        private Mp3Player _mp3Player;

        private static readonly log4net.ILog log = log4net.LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);

        public Presenter()
        {
            _views = new List<IViewWithTrackCollection>();
            _trackCollection = new TrackCollection();
            _dataExtractionEngine = new AudioDataExtractionProxy();

            _sortAlgorithm = new SimulatedAnnealingSortAlgorithm(new SimpleTracksDistance());
        }

        public Presenter(IViewWithTrackCollection view) : this()
        {
            _views.Add(view);
        }

        public bool IsTrackCollectionFilled => _trackCollection?.Count >= 1;

        public void ExportPlaylistInTextFile(string outputFilePath) => _trackCollection.ExportToText(outputFilePath);


        public void ClearDataBase()
        {
            var db = new DataBase();
            db.Clear();
        }

        public void MoveTrack(int dropIndex, string trackName)
        {
            if (dropIndex < 0 && dropIndex >= _trackCollection.Count)
            {
                Notify();
                return;
            }

            var track = _trackCollection.Search(trackName);
            _trackCollection.Remove(track);
            _trackCollection.Insert(dropIndex, track);
        }

        public void RemoveTracks(List<string> selection)
        {
            foreach (var trackName in selection)
            {
                _trackCollection.Remove(trackName);
            }
            Notify();
        }

        public void LockTracks(List<string> selection)
        {
            foreach(var trackName in selection)
            {
                var track = _trackCollection.Search(trackName);
                if (track != null)
                {
                    track.isFixed = true;
                }
            }
        }

        public object LoadTracks(BackgroundWorker backgroundWorker, string[] fileNames)
        {
            var filesEnum = fileNames.GetEnumerator();
            var tempTrackCollection = new TrackCollection();
            var count = 1;

            while (filesEnum.MoveNext() && !backgroundWorker.CancellationPending)
            {
                var filePath = (string)(filesEnum.Current);

                if (Directory.Exists(filePath))
                {
                    var filesInDirectoryEnum = Directory.GetFiles(filePath).GetEnumerator();

                    while (filesInDirectoryEnum.MoveNext() && !backgroundWorker.CancellationPending)
                    {
                        var filePathInDirectory = (string)(filesInDirectoryEnum.Current);

                        if (Utils.GetExtension(filePathInDirectory).Contains("mp3"))
                        {
                            var track = new Track(filePathInDirectory);
                            tempTrackCollection.SafeAdd(track);
                        }
                    }
                }

                else if (Utils.GetExtension(filePath).Contains("mp3"))
                {
                    var track = new Track(filePath);
                    tempTrackCollection.SafeAdd(track);
                }
                backgroundWorker.ReportProgress(500 * count++ / fileNames.Length);
            }

            _trackCollection.Concat(tempTrackCollection);
            _trackCollection.SortByName();
            backgroundWorker.ReportProgress(500);

            _dataExtractionEngine.ExtractData(backgroundWorker, tempTrackCollection);
            RetrieveControlOnCollection();

            _trackCollection.Purge();
            return _trackCollection;
        }

        private void RetrieveControlOnCollection()
        {
            _trackCollection = TrackCollection.CopyFrom(_trackCollection);
        }

        public void Notify()
        {
            foreach (var view in _views)
            {
                view.Update(_trackCollection);
            }
        }

        public object SortTrackCollection(BackgroundWorker backgroundWorker)
        {
            if (_trackCollection.Count > 1)
            {
                /*_trackCollection[2].isFixed = true;
                _trackCollection[6].isFixed = true;
                _trackCollection[8].isFixed = true;*/

                //_trackCollection = _sortAlgorithm.Sort(backgroundWorker, _trackCollection);
                _trackCollection = _sortAlgorithm.Sort(backgroundWorker, _trackCollection);
            }
            return _trackCollection;
        }

        public void ExportTrackList(BackgroundWorker backgroundWorker, string outputFilePath)
        {
            if (_trackCollection.Count >= 1)
            {
                _trackCollection.ExportToMp3(backgroundWorker, outputFilePath);
            }
        }

        public void Seek(double d) => _mp3Player.Seek(d);


        public void PlayMix(string fileName)
        {
            _mp3Player = new Mp3Player(fileName);
            _mp3Player.Play();
        }

        public void ResumeMix() => _mp3Player?.Play();

        public void PauseMix() => _mp3Player?.Pause();

        public void StopMix()
        {
            _mp3Player?.Stop();
            _mp3Player = null;
        }

        public long GetPlayerPosition()
        {
            //TODO : correct the error or at least catch the exception into the other classes
            try
            {
                return _mp3Player.GetPosition();
            }
            catch (System.NullReferenceException e)
            {
                log.Debug("Exception in presenter --> TODO correct error", e);
                throw e;
            }

        }

        public long GetPlayerLength()
        {
            return _mp3Player.GetLength();
        }

        public void ClearMusicList()
        {
            foreach (Track t in _trackCollection)
            {
                if (!_trackCollection.IsPresent(t))
                {
                    _trackCollection.Remove(t.Name);
                }
            }
            Notify();
        }
    }
}