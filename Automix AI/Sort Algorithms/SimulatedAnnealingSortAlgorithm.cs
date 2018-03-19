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
using System.Collections.Generic;
using System.Linq;

namespace Automix_AI.Sort_Algorithms
{
    public class SimulatedAnnealingSortAlgorithm : AbstractSortAlgorithm
    {
        private readonly double _stopTemperature;
        private readonly double _beginTemperature;
        private readonly double _decayFactor;
        private readonly int _numberOfIteration;

        public SimulatedAnnealingSortAlgorithm(ITracksDistance distance) : this(distance, 1, 45.0, 0.93, 75) { }

        public SimulatedAnnealingSortAlgorithm(ITracksDistance distance, double stopTemperature, double beginTemperature, double decayFactor, int numberOfIteration) : base(distance)
        {
            _stopTemperature = stopTemperature;
            _beginTemperature = beginTemperature;
            _decayFactor = decayFactor;
            _numberOfIteration = numberOfIteration;
        }

        public override TrackCollection Sort(BackgroundWorker backgroundWorker, TrackCollection trackCollection, TrackCollection fixedTracks)
        {
            var nbCollections = fixedTracks.Count;
            var resultCollection = new TrackCollection();
            var collections = new List<TrackCollection>();
            int numCollection = 0;

            fixedTracks.ForEach(delegate (Track track)
            {
                collections.Add(new TrackCollection());
                int pos = trackCollection.IndexOf(track);
                if (pos != -1)
                {
                    for (int i = 0; i < pos; i++)
                    {
                        collections[numCollection].Add(trackCollection[i]);
                    }
                    numCollection++;

                    collections.Add(new TrackCollection());
                    collections[numCollection].Add(trackCollection[pos]); // add the fixed Track
                    numCollection++;

                    trackCollection.RemoveRange(0, pos+1);
                }
            });

            collections.Add(new TrackCollection());
            for (int i = 0; i < trackCollection.Count; i++)
            {
                collections[numCollection].Add(trackCollection[i]);
            }
            numCollection++;
            trackCollection.Clear();

            for (int i = 0; i < collections.Count; i++)
            {
                TrackCollection newCollection;
                newCollection = Sort(backgroundWorker, collections[i]);
                
                if (!newCollection.Equals(collections[i]))
                {
                    var pos = collections.IndexOf(collections[i]);
                    collections[pos] = newCollection;
                }
            }

            collections.ForEach(delegate(TrackCollection collection)
            {
                resultCollection.Concat(collection);
            });

            return resultCollection;
        }

        public override TrackCollection Sort(BackgroundWorker backgroundWorker, TrackCollection trackCollection)
        {
            var originalTrackCollection = trackCollection;
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
                        TrackCollection tempCollection = CreatePotentialTrackCollection(result);
                        for (var j = 0; j < temperature; j++)
                        {
                            tempCollection = CreatePotentialTrackCollection(tempCollection);
                            if (j > tempCollection.Count)
                            {
                                break;
                            }
                        }

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

            if (current[track1].IsFixed || current[track2].IsFixed)
            {
                return current;
            }
            else
            {
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
}
