#include "window.h"
#include "sprite.h"

using namespace graphics;

int main()
{
	Window* mainWindow = new Window("test", 1280, 720);

	Sprite testSprite = Sprite("resources/Biplane.png",10,10);

	while (!mainWindow->Closed())
	{
		mainWindow->Update();
		testSprite.Update();
		mainWindow->BeginRender();
		testSprite.Render();
		mainWindow->EndRender();
	}


	return 0;
}
