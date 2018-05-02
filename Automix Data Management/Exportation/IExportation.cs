// Copyright (C) 2016 - 2018 LesProjecteurs
// This file is part of Automix Software licensed under MIT License.

using System.ComponentModel;
using Automix_Data_Management.Model;

namespace Automix_Data_Management.Exportation
{
    public interface IExportation
    {
        void ExportMix(BackgroundWorker bw, TrackCollection collection, string outputFile);
    }
}
