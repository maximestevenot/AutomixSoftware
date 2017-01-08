#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace AutoMixDataManagement;

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	AutoMixUI::MainForm form;
	Application::Run(%form);
}
