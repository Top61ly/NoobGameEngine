#pragma once

#include "GLFW\glfw3.h"

class Mouse
{
public:
	static void MousePosCallBack(GLFWwindow* window, double _x, double _y);
	static void MouseButtonCallBack(GLFWwindow* window, int button, int action,int mods);

	static double GetMouseX();
	static double GetMouseY();

	static bool ButtonDown(int button);
	static bool ButtonUp(int button);
	static bool Button(int button);



private:
	static double x;
	static double y;

	static bool buttons[];
	static bool buttonsDown[];
	static bool buttonsUp[];
};
