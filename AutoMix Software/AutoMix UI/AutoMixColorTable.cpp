#include "AutoMixColorTable.h"

namespace AutoMixUI {

	using namespace System::Drawing;
	using namespace System::Windows::Forms;

	AutoMixColorTable::AutoMixColorTable() : ProfessionalColorTable()
	{
		BACKGROUND_COLOR = MainColor;
		BORDER_COLOR = Color::White;
		SELECTION_BORDER_COLOR = MainColor;
		OVER_COLOR = SecondColor;
	}

	Color AutoMixColorTable::MainColor::get()
	{
		return Color::FromArgb(163, 38, 56);
	}

	Color AutoMixColorTable::SecondColor::get()
	{
		return Color::FromArgb(214, 28, 56);
	}

	Color AutoMixColorTable::DisabledColor::get()
	{
		return Color::FromArgb(171, 57, 74);
	}

	Color AutoMixColorTable::BackgroundColor::get()
	{
		return Color::FromArgb(64,69,69);
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