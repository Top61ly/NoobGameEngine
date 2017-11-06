#include "window.h"

using namespace graphics;

int main()
{
	Window* mainWindow = new Window("test", 1280, 720);

	while (!mainWindow->Closed())
	{
		mainWindow->Update();
		mainWindow->Render();
	}


	return 0;
}
