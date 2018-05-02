// Copyright (C) 2016 - 2018 LesProjecteurs
// This file is part of Automix Software licensed under MIT License.

using System.ComponentModel;
using Automix_AI.Distances;
using Automix_Data_Management.Model;

namespace Automix_AI.Sort_Algorithms
{
    public abstract class AbstractSortAlgorithm
    {
        public ITracksDistance Distance { get; }

        protected AbstractSortAlgorithm(ITracksDistance distance)
        {
            Distance = distance;
        }

        public abstract TrackCollection Sort(BackgroundWorker backgroundWorker, TrackCollection trackCollection);

        public abstract TrackCollection Sort(BackgroundWorker backgroundWorker, TrackCollection trackCollection, TrackCollection fixedTracks);
    }
}