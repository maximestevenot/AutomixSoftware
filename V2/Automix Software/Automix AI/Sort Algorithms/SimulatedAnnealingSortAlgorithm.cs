// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using System;
using System.ComponentModel;
using Automix_AI.Distances;
using Automix_Data_Management.Model;

namespace Automix_AI.Sort_Algorithms
{
    public class SimulatedAnnealingSortAlgorithm : AbstractSortAlgorithm
    {
        private readonly double _stopTemperature;
        private readonly double _beginTemperature;
        private readonly double _decayFactor;
        private readonly int _numberOfIteration;

        public SimulatedAnnealingSortAlgorithm(ITracksDistance distance) : this(distance, 1, 35.0, 0.93, 15) { }

        public SimulatedAnnealingSortAlgorithm(ITracksDistance distance, double stopTemperature, double beginTemperature, double decayFactor, int numberOfIteration) : base(distance)
        {
            _stopTemperature = stopTemperature;
            _beginTemperature = beginTemperature;
            _decayFactor = decayFactor;
            _numberOfIteration = numberOfIteration;
        }
        public override TrackCollection Sort(BackgroundWorker backgroundWorker, TrackCollection trackCollection)
        {
            var nbTracks = trackCollection.Count;
            var n = (nbTracks / 2) * (nbTracks / 2);
            var result = trackCollection;
            var random = new Random();

            for (var k = 0; k < _numberOfIteration; k++)
            {
                if (backgroundWorker.CancellationPending)
                {
                    break;
                }

                var temperature = _beginTemperature;

                while (temperature > _stopTemperature)
                {
                    for (var i = 0; i < n; i++)
                    {
                        var tempCollection = CreatePotentialTrackCollection(result);
                        var dE = ComputeIndividualEvaluation(tempCollection) - ComputeIndividualEvaluation(result);

                        if (dE < 0)
                        {
                            result = tempCollection;
                        }
                        else
                        {
                            if (random.Next(100) < (Math.Exp(-dE / temperature) * 100))
                            {
                                result = tempCollection;
                            }
                        }

                    }
                    temperature = temperature * _decayFactor;
                }
                if (ComputeIndividualEvaluation(result) < ComputeIndividualEvaluation(trackCollection))
                {
                    trackCollection = result;
                }
                backgroundWorker.ReportProgress(1000 * k / _numberOfIteration);
            }

            return trackCollection;
        }

        private double ComputeIndividualEvaluation(TrackCollection individual)
        {
            double result = 0;
            for (var k = 0; k < (individual.Count) - 1; k++)
            {
                result += Distance.Compute(individual[k], individual[k + 1]);
            }
            return result;
        }

        private static TrackCollection CreatePotentialTrackCollection(TrackCollection current)
        {
            var random = new Random();
            var track1 = random.Next(current.Count);
            var track2 = random.Next(current.Count);

            var newTrackCollection = new TrackCollection();
            for (var i = 0; i < current.Count; i++)
            {
                if (i == track1)
                {
                    newTrackCollection.Add(current[track2]);
                }
                else
                {
                    newTrackCollection.Add(i == track2 ? current[track1] : current[i]);
                }
            }
            return newTrackCollection;
        }
    }
}
