using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using AutomixDataManagement.Model;

namespace AutomixDataManagement.Exportation
{
    class SmoothMix : IExportation
    {
        int TransitionDuration { get; set; }

        public void ExportMix(BackgroundWorker bw, TrackCollection collection, string outputFile)
        {
            throw new NotImplementedException();
        }
    }
}
