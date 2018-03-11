using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Automix_Data_Management.Model;
using Automix_AI.Distances;

namespace Automix_UI
{
    public class PresenterParameter
    {
        private readonly List<IViewWithParameters> _views;
        private Parameters _parameters;
        private IProfileDistance _sortProfile;


        public PresenterParameter()
        {
            _views = new List<IViewWithParameters>();
            _parameters = new Parameters();
        }

        public PresenterParameter(IViewWithParameters view) : this()
        {
            _views.Add(view);
        }

        public void setProfile(IProfileDistance profile)
        {
            _sortProfile = profile;
            foreach (IViewWithParameters view in _views)
            {
                view.LoadParameters(_parameters);
            }
        }

    }
}
