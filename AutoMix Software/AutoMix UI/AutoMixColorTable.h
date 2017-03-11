#pragma once

namespace AutoMixUI {

	public ref class AutoMixColorTable : public System::Windows::Forms::ProfessionalColorTable
	{
	public:
		AutoMixColorTable();

		property System::Drawing::Color ToolStripBorder { virtual System::Drawing::Color get() override; }
		property System::Drawing::Color ToolStripDropDownBackground { virtual System::Drawing::Color get() override; }
		property System::Drawing::Color ToolStripGradientBegin { virtual System::Drawing::Color get() override; }
		property System::Drawing::Color ToolStripGradientEnd { virtual System::Drawing::Color get() override; }
		property System::Drawing::Color ToolStripGradientMiddle { virtual System::Drawing::Color get() override; }
		property System::Drawing::Color MenuBorder { virtual System::Drawing::Color get() override; }
		property System::Drawing::Color MenuItemBorder { virtual System::Drawing::Color get() override; }
		property System::Drawing::Color MenuItemPressedGradientBegin { virtual System::Drawing::Color get() override; }
		property System::Drawing::Color MenuItemPressedGradientEnd { virtual System::Drawing::Color get() override; }
		property System::Drawing::Color MenuItemPressedGradientMiddle { virtual System::Drawing::Color get() override; }
		property System::Drawing::Color MenuItemSelected { virtual System::Drawing::Color get() override; }
		property System::Drawing::Color MenuItemSelectedGradientBegin { virtual System::Drawing::Color get() override; }
		property System::Drawing::Color MenuItemSelectedGradientEnd { virtual System::Drawing::Color get() override; }
		property System::Drawing::Color MenuStripGradientBegin { virtual System::Drawing::Color get() override; }
		property System::Drawing::Color MenuStripGradientMiddle { virtual System::Drawing::Color get() override; }
		property System::Drawing::Color MenuStripGradientEnd { virtual System::Drawing::Color get() override; }
		property System::Drawing::Color ImageMarginGradientBegin { virtual System::Drawing::Color get() override; }
		property System::Drawing::Color ImageMarginGradientMiddle { virtual System::Drawing::Color get() override; }
		property System::Drawing::Color ImageMarginGradientEnd { virtual System::Drawing::Color get() override; }
		property System::Drawing::Color ImageMarginRevealedGradientBegin { virtual System::Drawing::Color get() override; }
		property System::Drawing::Color ImageMarginRevealedGradientMiddle { virtual System::Drawing::Color get() override; }
		property System::Drawing::Color ImageMarginRevealedGradientEnd { virtual System::Drawing::Color get() override; }

	private :

		System::Drawing::Color BACKGROUND_COLOR;
		System::Drawing::Color BORDER_COLOR;
		System::Drawing::Color OVER_COLOR;
		System::Drawing::Color PRESSED_COLOR;
		System::Drawing::Color SELECTION_BORDER_COLOR;
	};

}
