// Copyright (C) 2016-2017 LesProjecteurs - All Rights Reserved
// Maxime STEVENOT, Guillaume HANNES, Jordan ERNULT, Louis CARLIER, Pierre GABON
// 
// This file is part of Automix Software.
// 
// Unauthorized copying of this file, via any medium is strictly prohibited.
// You should have received a copy of the License along with this program.

using System.Windows.Forms;
using System.Drawing;

namespace Automix_UI
{
    public class AutomixColorTable : ProfessionalColorTable
    {
        public static Color MainColor => Color.FromArgb(163, 38, 56);
        public static Color DisabledColor => Color.FromArgb(171, 57, 74);
        public static Color SecondColor => Color.FromArgb(214, 28, 56);
        public static Color BackgroundColor => Color.FromArgb(64, 69, 69);

        private readonly Color _menuBackgroundColor;
        private readonly Color _menuBorderColor;
        private readonly Color _menuOverColor;
        private readonly Color _menuSelectionBorderColor;

        public AutomixColorTable()
        {
            _menuBackgroundColor = MainColor;
            _menuBorderColor = Color.White;
            _menuOverColor = SecondColor;
            _menuSelectionBorderColor = MainColor;
        }

        public override Color ToolStripBorder => _menuBorderColor;
        public override Color ToolStripDropDownBackground => _menuBackgroundColor;
        public override Color ToolStripGradientBegin => _menuBackgroundColor;
        public override Color ToolStripGradientEnd => _menuBackgroundColor;
        public override Color ToolStripGradientMiddle => _menuBackgroundColor;
        public override Color MenuBorder => _menuBorderColor;
        public override Color MenuItemBorder => _menuSelectionBorderColor;
        public override Color MenuItemPressedGradientBegin => _menuBackgroundColor;
        public override Color MenuItemPressedGradientEnd => _menuBackgroundColor;
        public override Color MenuItemPressedGradientMiddle => _menuBackgroundColor;
        public override Color MenuItemSelected => _menuOverColor;
        public override Color MenuItemSelectedGradientBegin => _menuBackgroundColor;
        public override Color MenuItemSelectedGradientEnd => _menuBackgroundColor;
        public override Color MenuStripGradientBegin => _menuBackgroundColor;
        public override Color MenuStripGradientEnd => _menuBackgroundColor;
        public override Color ImageMarginGradientBegin => _menuBackgroundColor;
        public override Color ImageMarginGradientMiddle => _menuBackgroundColor;
        public override Color ImageMarginGradientEnd => _menuBackgroundColor;
        public override Color ImageMarginRevealedGradientBegin => _menuBackgroundColor;
        public override Color ImageMarginRevealedGradientMiddle => _menuBackgroundColor;
        public override Color ImageMarginRevealedGradientEnd => _menuBackgroundColor;
    }
}
