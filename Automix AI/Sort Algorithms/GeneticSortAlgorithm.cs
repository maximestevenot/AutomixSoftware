// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using System;
using System.Collections.Generic;
using System.ComponentModel;
using Automix_AI.Distances;
using Automix_Data_Management.Model;

namespace Automix_AI.Sort_Algorithms
{
    using Population = List<TrackCollection>;

    public class GeneticSortAlgorithm : AbstractSortAlgorithm
    {
        private readonly int _numberOfIteration;
        private readonly int _populationSize;
        private readonly double _mutationProbability; // Probabilty of mutation out of 100

        public GeneticSortAlgorithm(ITracksDistance distance) : this(distance, 175, 175, 85) { }

        public GeneticSortAlgorithm(ITracksDistance distance, int numberOfIteration, int populationSize, double mutationProbabilty) : base(distance)
        {
            _numberOfIteration = numberOfIteration;
            _populationSize = populationSize;
            _mutationProbability = mutationProbabilty;
        }

        public override TrackCollection Sort(BackgroundWorker backgroundWorker, TrackCollection trackCollection, TrackCollection fixedTracks)
        {
            var population = CreateInitialPopulation(trackCollection);
            SortPopulation(population, 0, population.Count - 1);

            for (var k = 0; k < _numberOfIteration; k++)
            {
                if (backgroundWorker.CancellationPending)
                {
                    break;
                }

                CreateChildrenAndPutThemIntoPopulation(population);
                MutatePopulation(population);
                SortPopulation(population, 0, population.Count - 1);
                population = population.GetRange(0, _populationSize);
                backgroundWorker.ReportProgress(1000 * k / _numberOfIteration);
            }
            return population[0];
        }

        private void MutatePopulation(Population pop)
        {
            var  randomGenerator = new Random();
            for (var k = 0; k < pop.Count; k++)
            {
                if (!(randomGenerator.Next(100) < _mutationProbability))
                {
                    continue;
                }
                var mutant = pop[k];
                var index1 = randomGenerator.Next(mutant.Count);
                var index2 = randomGenerator.Next(mutant.Count);
                var tempTrack = mutant[index1];
                mutant[index1] = mutant[index2];
                mutant[index2] = tempTrack;
                pop[k] = mutant;
            }
        }

        private void CreateChildrenAndPutThemIntoPopulation(Population population)
        {
            for (var k = 0; k < population.Count / 2; k++)
            {
                population.Add(CreateChildrenFromParents(population[k], population[k + 1]));
                population.Add(CreateChildrenFromParents(population[k + 1], population[k]));
            }
        }

        private TrackCollection CreateChildrenFromParents(TrackCollection parent1, TrackCollection parent2)
        {
            var  children = new TrackCollection();
            for (var k = 0; k < (parent1.Count) / 2; k++)
            {
                children.Add(parent1[k]);
            }

            for (var i = (parent1.Count) / 2; i < parent1.Count; i++)
            {
                if (children.Contains(parent2[i]))
                {
                    foreach (var t in parent1)
                    {
                        if ((!children.Contains(t)) && (!parent2.GetRange((parent1.Count) / 2, (parent1.Count) / 2).Contains(t)))
                        {
                            children.Add(t);
                        }
                    }
                }
                else
                {
                    children.Add(parent2[i]);
                }
            }
            return children;
        }

        private void SortPopulation(Population population, int begin, int end)
        {
            var i = begin;
            var j = end;
            var pivot = population[(i + j) / 2];

            while (i <= j)
            {
                while (ComputeIndividualEvaluation(population[i]) < ComputeIndividualEvaluation(pivot))
                {
                    i++;
                }
                while (ComputeIndividualEvaluation(population[j]) > ComputeIndividualEvaluation(pivot))
                {
                    j--;
                }
                if (i <= j)
                {
                    var temp = population[i];
                    population[i] = population[j];
                    population[j] = temp;
                    i++;
                    j--;
                }
            }
            if (begin < j)
            {
                SortPopulation(population, begin, j);
            }
            if (i < end)
            {
                SortPopulation(population, i, end);
            }
        }

        private Population CreateInitialPopulation(TrackCollection trackCollection)
        {
            var population = new Population();
            var randomGenerator = new Random();
            population.Add(trackCollection);
            for (var k = 1; k < _populationSize; k++)
            {
                var individual = new TrackCollection();
                individual.AddRange(trackCollection);
                for (var i = 0; i < individual.Count; i++)
                {
                    var track = individual[i];
                    individual.Remove(track);
                    individual.Insert(randomGenerator.Next(individual.Count), track);
                }
                population.Add(individual);
            }
            return population;
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
    }
}
