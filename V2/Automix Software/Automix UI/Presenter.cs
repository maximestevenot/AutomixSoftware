using System.Collections.Generic;

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
    }
}