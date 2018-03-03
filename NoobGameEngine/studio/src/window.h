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
		static double m_DeltaTime;
	public:
		Window(const char *name, int width, int height);
		~Window();
		void Update();

		void OnGui() const;

		void BeginRender() const;
		void EndRender() const;
		bool Closed() const;

	public:
		static const double GetDeltaTime();
	private:
		double lastTime;
		bool Init();
	};
}