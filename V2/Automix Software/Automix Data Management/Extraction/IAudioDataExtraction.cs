using System.ComponentModel;
using Automix_Data_Management.Model;

namespace Automix_Data_Management.Extraction
{
    public interface IAudioDataExtraction
    {
        void ExtractData(BackgroundWorker bw, TrackCollection trackCollection);
    }
}
