#include "window.h"
#include "sprite.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Vector3.h"

#include "Flapper.h"

#include <iostream>

int main()
{
	Window* mainWindow = new Window("test", 1280, 720);

	Vector3 initPosition(10, 10, 0);

	Sprite testSprite = Sprite("resources/Biplane.png",initPosition);

	testSprite.SetScale(0.1);

	double speed = 100;

	Flapper player(testSprite);

	while (!mainWindow->Closed())
	{
		mainWindow->Update();
		player.Update();

		//testSprite.MoveTo((float)Mouse::GetMouseX(),(float)Mouse::GetMouseY());
		
		if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))
		{
			player.GetSprite().RotateBy(10);
		}

		if (Mouse::ButtonDown(GLFW_MOUSE_BUTTON_RIGHT))
		{
			player.GetSprite().RotateBy(-10);
		}

		if (Mouse::Button(GLFW_MOUSE_BUTTON_MIDDLE))
		{
			player.GetSprite().RotateBy(10);
		}

		if (Keyboard::Key(GLFW_KEY_W))
		{
			player.GetSprite().MoveBy(0,speed*Window::GetDeltaTime());
		}

		if (Keyboard::Key(GLFW_KEY_S))
		{
			player.GetSprite().MoveBy(0,-speed*Window::GetDeltaTime());
		}

		if (Keyboard::Key(GLFW_KEY_A))
		{
			player.GetSprite().MoveBy(-speed*Window::GetDeltaTime(),0);
		}

		if (Keyboard::Key(GLFW_KEY_D))
		{
			player.GetSprite().MoveBy(speed*Window::GetDeltaTime(),0);
		}

		mainWindow->BeginRender();
		player.Render();
		mainWindow->EndRender();
	}

	return 0;
}
