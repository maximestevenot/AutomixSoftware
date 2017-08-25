using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Automix_UI.Drawing
{
    internal class ListViewDrawer
    {
        private readonly Color _insertionLineColor;
        private readonly ListView _musicListView;

        public ListViewDrawer(ListView musicListView, Color insertionLineColor)
        {
            _insertionLineColor = insertionLineColor;
            _musicListView = musicListView;
        }

        public void DrawColumnHeader(DrawListViewColumnHeaderEventArgs e)
        {
            e.DrawBackground();
            e.DrawText(TextFormatFlags.TextBoxControl);
        }

        public void DrawItem(DrawListViewItemEventArgs e)
        {
            if (e.Item.Selected)
            {
                e.Graphics.FillRectangle(new SolidBrush(AutomixColorTable.SecondColor), e.Bounds);
            }
        }

        public void DrawSubItem(DrawListViewSubItemEventArgs e)
        {
            if (e.Item.Selected)
            {
                e.Graphics.FillRectangle(new SolidBrush(AutomixColorTable.SecondColor), e.Bounds);
            }
            e.DrawText(TextFormatFlags.TextBoxControl);
        }

        public void DrawInsertionLine(int x, int y, int width)
        {
            var graphics = _musicListView.CreateGraphics();
            var x2 = x + width;
            const int arrowHeadSize = 7;

            var leftArrowHead = new[] { new Point(x, y - (arrowHeadSize / 2)),
                new Point(x + arrowHeadSize, y), new Point(x, y + (arrowHeadSize / 2))};

            var rightArrowHead = new[] { new Point(x2, y - (arrowHeadSize / 2)),
                new Point(x2 - arrowHeadSize, y), new Point(x2, y + (arrowHeadSize / 2)) };

            var pen = new Pen(_insertionLineColor);

            graphics.DrawLine(pen, x, y, x2 - 1, y);
            var brush = new SolidBrush(_insertionLineColor);
            graphics.FillPolygon(brush, leftArrowHead);
            graphics.FillPolygon(brush, rightArrowHead);
        }
    }
}