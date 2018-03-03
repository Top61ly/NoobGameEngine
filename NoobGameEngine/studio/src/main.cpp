#include "window.h"
#include "sprite.h"
#include "Mouse.h"
#include "Keyboard.h"

using namespace graphics;

int main()
{
	Window* mainWindow = new Window("test", 1280, 720);

	Sprite testSprite = Sprite("resources/Biplane.png",10,10);

	testSprite.SetScale(0.1);

	double speed = 100;

	while (!mainWindow->Closed())
	{
		mainWindow->Update();
		testSprite.Update();

		//testSprite.MoveTo((float)Mouse::GetMouseX(),(float)Mouse::GetMouseY());
		
		if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))
		{
			testSprite.RotateBy(10);
		}

		if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_RIGHT))
		{
			testSprite.RotateBy(-10);
		}

		if (Mouse::Button(GLFW_MOUSE_BUTTON_MIDDLE))
		{
			testSprite.RotateBy(10);
		}

		if (Keyboard::Key(GLFW_KEY_W))
		{
			testSprite.MoveBy(0,speed*mainWindow->GetDeltaTime());
		}

		if (Keyboard::Key(GLFW_KEY_S))
		{
			testSprite.MoveBy(0,-speed*mainWindow->GetDeltaTime());
		}

		if (Keyboard::Key(GLFW_KEY_A))
		{
			testSprite.MoveBy(-speed*mainWindow->GetDeltaTime(),0);
		}

		if (Keyboard::Key(GLFW_KEY_D))
		{
			testSprite.MoveBy(speed*mainWindow->GetDeltaTime(),0);
		}

		mainWindow->BeginRender();
		testSprite.Render();
		mainWindow->EndRender();
	}

	return 0;
}
