#include "User.h"
#include "MyForm.h"
#include <Windows.h>
using namespace EduPractice;
[STAThread]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew User);
	return 0;
}


