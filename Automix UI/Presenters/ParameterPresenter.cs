// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using Automix_Data_Management.Storage;
using Automix_UI.Forms;

namespace Automix_UI.Presenters
{
    public class ParameterPresenter
    {
        private ParameterForm _form;
        private ParameterStorage _storage;

        public ParameterPresenter(ParameterForm form, ParameterStorage storage)
        {
            _form = form;
            _storage = storage;
        }


    }
}