#include "MyForm.h"
#include "Track.h"
#include "TrackCollection.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace AMResources;

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	AutoMix_UI::MyForm form;
	Application::Run(%form);
}
