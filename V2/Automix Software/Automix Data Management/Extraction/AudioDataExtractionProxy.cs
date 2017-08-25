using System.ComponentModel;
using Automix_Data_Management.Model;

namespace Automix_Data_Management.Extraction
{
    public class AudioDataExtractionProxy : IAudioDataExtraction
    {
        private readonly IAudioDataExtraction _realSubject;

        public AudioDataExtractionProxy()
        {
            _realSubject = new AudioDataExtraction();
        }

        public void ExtractData(BackgroundWorker backgroundWorker, TrackCollection trackCollection)
        {
            _realSubject.ExtractData(backgroundWorker, trackCollection);
        }
    }
}
