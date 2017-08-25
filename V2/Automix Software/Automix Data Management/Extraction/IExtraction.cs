﻿using System.Threading;
using System.ComponentModel;
using Automix_Data_Management.Model;

namespace Automix_Data_Management.Extraction
{
    public interface IExtraction
    {
        void ExtractData(BackgroundWorker backgroundWorker, int nbTracks, CancellationTokenSource cancellationTokenSource, Track track);
    }
}
