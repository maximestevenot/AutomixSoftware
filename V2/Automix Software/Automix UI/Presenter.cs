using System.Collections.Generic;
using System.ComponentModel;

namespace Automix_UI
{
    internal class Presenter
    {
        private IViewWithTrackCollection mainForm;

        public Presenter(IViewWithTrackCollection mainForm)
        {
            this.mainForm = mainForm;
        }

        public bool IsTrackCollectionFilled { get; set; }

        public void ExportPlaylistInTextFile(string dialogFileName)
        {
            throw new System.NotImplementedException();
        }

        public void StopMix()
        {
            throw new System.NotImplementedException();
        }

        public void ClearDataBase()
        {
            throw new System.NotImplementedException();
        }

        public void MoveTrack(int dropIndex, string dragItemText)
        {
            throw new System.NotImplementedException();
        }

        public void RemoveTracks(List<string> selection)
        {
            throw new System.NotImplementedException();
        }

        public object LoadTracks(BackgroundWorker backgroundWorker, string[] fileNames)
        {
            throw new System.NotImplementedException();
        }

        public void Notify()
        {
            throw new System.NotImplementedException();
        }

        public object SortTrackCollection(BackgroundWorker backgroundWorker)
        {
            throw new System.NotImplementedException();
        }

        public void ExportTrackList(BackgroundWorker backgroundWorker, string fileName)
        {
            throw new System.NotImplementedException();
        }

        public void Seek(double d)
        {
            throw new System.NotImplementedException();
        }

        public void PlayMix(string exportPath)
        {
            throw new System.NotImplementedException();
        }

        public void ResumeMix()
        {
            throw new System.NotImplementedException();
        }

        public void PauseMix()
        {
            throw new System.NotImplementedException();
        }

        public long GetPlayerPosition()
        {
            throw new System.NotImplementedException();
        }

        public long GetPlayerLength()
        {
            throw new System.NotImplementedException();
        }
    }
}