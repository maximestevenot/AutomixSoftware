// Copyright (C) 2016 - 2018 LesProjecteurs
// This file is part of Automix Software licensed under MIT License.

using System.ComponentModel;
using System.Threading;
using Automix_Data_Management.Model;
using Automix_Data_Management.Storage;

namespace Automix_Data_Management.Extraction
{
    internal class DataBaseExtraction : IExtraction
    {
        private readonly DataBase _dataBase;

        public DataBaseExtraction(DataBase dataBase)
        {
            _dataBase = dataBase;
        }

        public void ExtractData(BackgroundWorker backgroundWorker, int nbTracks, CancellationTokenSource cancellationTokenSource, Track track)
        {
            _dataBase.ExtractData(track);
            Interlocked.Increment(ref AudioDataExtraction.ExploredTracks);
            backgroundWorker.ReportProgress(500 + 500 * AudioDataExtraction.ExploredTracks / nbTracks);
        }
    }
}