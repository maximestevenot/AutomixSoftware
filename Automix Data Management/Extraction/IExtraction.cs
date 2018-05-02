// Copyright (C) 2016 - 2018 LesProjecteurs
// This file is part of Automix Software licensed under MIT License.

using System.ComponentModel;
using System.Threading;
using Automix_Data_Management.Model;

namespace Automix_Data_Management.Extraction
{
    internal interface IExtraction
    {
        void ExtractData(BackgroundWorker backgroundWorker, int nbTracks, CancellationTokenSource cancellationTokenSource, Track track);
    }
}
