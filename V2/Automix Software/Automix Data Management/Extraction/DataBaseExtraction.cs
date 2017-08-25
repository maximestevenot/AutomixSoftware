// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

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
            var exploredTracks = AudioDataExtraction.ExploredTracks;
            Interlocked.Increment(ref exploredTracks);
            backgroundWorker.ReportProgress(500 + 500 * AudioDataExtraction.ExploredTracks / nbTracks);
        }
    }
}