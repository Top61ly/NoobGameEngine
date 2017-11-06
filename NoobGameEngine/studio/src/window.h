#pragma once
#include <iostream>  
#include <imgui.h>
#include <stdio.h>
#include <GLFW/glfw3.h>

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

		void Render() const;
		bool Closed() const;
	private:
		bool Init();
	};
}