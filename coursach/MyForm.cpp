#include "saves.h"

CONFIG GLOBALS;

#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
int main(array<String^>^ args) {
	GLOBALS.readFromFile();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	coursach::MyForm form;
	Application::Run(% form);
	return 0;
}