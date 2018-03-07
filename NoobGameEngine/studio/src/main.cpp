#include "window.h"
#include "sprite.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Vector3.h"

using namespace graphics;

int main()
{
	Window* mainWindow = new Window("test", 1280, 720);

	Vector3 initPosition(10, 10, 0);

	Sprite testSprite = Sprite("resources/Biplane.png",initPosition);

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
			testSprite.MoveBy(0,speed*Window::GetDeltaTime());
		}

		if (Keyboard::Key(GLFW_KEY_S))
		{
			testSprite.MoveBy(0,-speed*Window::GetDeltaTime());
		}

		if (Keyboard::Key(GLFW_KEY_A))
		{
			testSprite.MoveBy(-speed*Window::GetDeltaTime(),0);
		}

		if (Keyboard::Key(GLFW_KEY_D))
		{
			testSprite.MoveBy(speed*Window::GetDeltaTime(),0);
		}

		mainWindow->BeginRender();
		testSprite.Render();
		mainWindow->EndRender();
	}

	return 0;
}
