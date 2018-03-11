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

        public PresenterParameter()
        {
            _views = new List<IViewWithParameters>();
            _parameters = new Parameters();
        }

        public PresenterParameter(IViewWithParameters view) : this()
        {
            _views.Add(view);
        }

        public void SetProfile(IProfileDistance profile)
        {
            _parameters.BpmPriority = profile.BpmPriority.ToString();
            _parameters.KeyNumberPriority = profile.KeyNumberPriority.ToString();
            _parameters.KeyTonalityPriority = profile.KeyTonalityPriority.ToString();
            _parameters.DanceabilityPriority = profile.DanceabilityPriority.ToString();

            UpdateViews();
        }

        public void SaveParameters()
        {
            _parameters.Save();
        }

        internal void SetTransitionDuration(decimal value)
        {
            _parameters.TransitionDuration = value.ToString();
        }

        internal void SetMixDuration(decimal value)
        {
            _parameters.MixDuration = value.ToString();
        }

        public void UpdateViews()
        {
            foreach (IViewWithParameters view in _views)
            {
                view.LoadParameters(_parameters);
            }
        }
    }
}
