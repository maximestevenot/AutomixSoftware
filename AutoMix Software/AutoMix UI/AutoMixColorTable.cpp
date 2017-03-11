#include "AutoMixColorTable.h"

namespace AutoMixUI {

	using namespace System::Drawing;
	using namespace System::Windows::Forms;

	AutoMixColorTable::AutoMixColorTable() : ProfessionalColorTable()
	{
		BACKGROUND_COLOR = Color::DarkMagenta;
		BORDER_COLOR = Color::White;
		SELECTION_BORDER_COLOR = Color::DarkMagenta; //Color::FromArgb(0, 192, 192);
		OVER_COLOR = Color::FromArgb(0, 192, 192);
	}

	Color AutoMixColorTable::SelectionColor::get()
	{ 
		return Color::FromArgb(0, 192, 192);
	}

	Color AutoMixColorTable::BackGroundColor::get()
	{
		return Color::FromArgb(19, 23, 27);
	}

	Color AutoMixColorTable::ToolStripBorder::get()
	{
		return BORDER_COLOR;
	}

	Color AutoMixColorTable::ToolStripDropDownBackground::get()
	{
		return BACKGROUND_COLOR;
	}

	Color AutoMixColorTable::ToolStripGradientBegin::get()
	{
		return BACKGROUND_COLOR;
	}

	Color AutoMixColorTable::ToolStripGradientEnd::get()
	{
		return BACKGROUND_COLOR;
	}

	Color AutoMixColorTable::ToolStripGradientMiddle::get()
	{
		return BACKGROUND_COLOR;
	}

	Color AutoMixColorTable::MenuBorder::get()
	{
		return BORDER_COLOR;
	}

	Color AutoMixColorTable::MenuItemBorder::get()
	{
		return SELECTION_BORDER_COLOR;
	}

	Color AutoMixColorTable::MenuItemPressedGradientBegin::get()
	{
		return BACKGROUND_COLOR;
	}

	Color AutoMixColorTable::MenuItemPressedGradientEnd::get()
	{
		return BACKGROUND_COLOR;
	}

	Color AutoMixColorTable::MenuItemPressedGradientMiddle::get()
	{
		return BACKGROUND_COLOR;
	}

	Color AutoMixColorTable::MenuItemSelected::get()
	{
		return OVER_COLOR;
	}

	Color AutoMixColorTable::MenuItemSelectedGradientBegin::get()
	{
		return BACKGROUND_COLOR;
	}

	Color AutoMixColorTable::MenuItemSelectedGradientEnd::get()
	{
		return BACKGROUND_COLOR;
	}

	Color AutoMixColorTable::MenuStripGradientBegin::get()
	{
		return BACKGROUND_COLOR;
	}

	Color AutoMixColorTable::MenuStripGradientEnd::get()
	{
		return BACKGROUND_COLOR;
	}

	Color AutoMixColorTable::ImageMarginGradientBegin::get()
	{
		return BACKGROUND_COLOR;
	}

	Color AutoMixColorTable::ImageMarginGradientMiddle::get()
	{
		return BACKGROUND_COLOR;
	}

	Color AutoMixColorTable::ImageMarginGradientEnd::get()
	{
		return BACKGROUND_COLOR;
	}

	Color AutoMixColorTable::ImageMarginRevealedGradientBegin::get()
	{
		return BACKGROUND_COLOR;
	}

	Color AutoMixColorTable::ImageMarginRevealedGradientMiddle::get()
	{
		return BACKGROUND_COLOR;
	}

	Color AutoMixColorTable::ImageMarginRevealedGradientEnd::get()
	{
		return BACKGROUND_COLOR;
	}
}