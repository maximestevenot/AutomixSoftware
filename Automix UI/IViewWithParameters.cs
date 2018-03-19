using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Automix_Data_Management.Model;

namespace Automix_UI
{
    public interface IViewWithParameters
    {
        void LoadParameters(Parameters param);
    }
}
