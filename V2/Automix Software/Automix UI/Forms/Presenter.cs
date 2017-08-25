namespace Automix_UI.Forms
{
    internal class Presenter
    {
        private IViewWithTrackCollection mainForm;

        public Presenter(IViewWithTrackCollection mainForm)
        {
            this.mainForm = mainForm;
        }
    }
}