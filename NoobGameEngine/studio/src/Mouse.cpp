#include "Mouse.h"

double Mouse::x = 0;
double Mouse::y = 0;

bool Mouse::buttons[GLFW_MOUSE_BUTTON_LAST] = {0};
bool Mouse::buttonsDown[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsUp[GLFW_MOUSE_BUTTON_LAST] = { 0 };

void Mouse::MousePosCallBack(GLFWwindow* window, double _x, double _y)
{
	int width, height;

	glfwGetFramebufferSize(window, &width, &height);

	x = _x;
	y = height - _y;
}

void Mouse::MouseButtonCallBack(GLFWwindow* window, int button, int action, int mods)
{
	if (button < 0)
		return;

	if (action != GLFW_RELEASE && buttons[button] == false)
	{
		buttonsDown[button] = true;
		buttonsUp[button] = false;
	}

}