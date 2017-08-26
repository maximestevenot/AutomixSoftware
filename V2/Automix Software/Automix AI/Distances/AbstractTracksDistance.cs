using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Automix_Data_Management.Model;

namespace Automix_AI.Distances
{
    public abstract class AbstractTracksDistance : ITracksDistance
    {
        public double BpmPriority { get; set; }
        public double KeyNumberPriority { get; set; }
        public double KeyTonalityPriority { get; set; }
        public double DanceabilityPriority { get; set; }

        protected AbstractTracksDistance()
        {
            BpmPriority = 1;
            KeyNumberPriority = 1;
            KeyTonalityPriority = 1;
            DanceabilityPriority = 1;
        }

        public abstract double Compute(Track track1, Track track2);
    }
}
