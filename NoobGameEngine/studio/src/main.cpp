#include "window.h"
#include "sprite.h"
#include "Mouse.h"

using namespace graphics;

int main()
{
	Window* mainWindow = new Window("test", 1280, 720);

	Sprite testSprite = Sprite("resources/Biplane.png",10,10);

	while (!mainWindow->Closed())
	{
		mainWindow->Update();
		testSprite.Update();

		testSprite.SetPos((float)Mouse::GetMouseX(),(float)Mouse::GetMouseY());


		mainWindow->BeginRender();
		testSprite.Render();
		mainWindow->EndRender();
	}


	return 0;
}
