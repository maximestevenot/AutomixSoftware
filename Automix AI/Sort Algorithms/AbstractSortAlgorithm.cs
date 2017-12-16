// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using System.ComponentModel;
using Automix_AI.Distances;
using Automix_Data_Management.Model;

namespace Automix_AI.Sort_Algorithms
{
    public abstract class AbstractSortAlgorithm
    {
        protected TrackCollection _fixedTracks;

        public ITracksDistance Distance { get; }

        protected AbstractSortAlgorithm(ITracksDistance distance)
        {
            Distance = distance;
        }

        public abstract TrackCollection Sort(BackgroundWorker backgroundWorker, TrackCollection trackCollection);
    }
}