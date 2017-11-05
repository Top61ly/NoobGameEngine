#pragma once
#include <GLFW\glfw3.h>
#include <iostream>

namespace graphics
{
	class Window
	{
	private:
		const char *m_Name;
		int m_Width, m_Height;
		GLFWwindow *m_Window;
		bool m_Closed;
	public:
		Window(const char *name, int width, int height);
		~Window();
		void Update() const;

		void OnGui() const;

		bool Closed() const;
		void Clear() const;
	private:
		bool Init();
	};
}