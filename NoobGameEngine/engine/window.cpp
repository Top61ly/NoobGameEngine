#include "window.h"

namespace graphics
{
	Window::Window(const char *name, int width, int height)
	{
		m_Name = name;
		m_Width = width;
		m_Height = height;
		if (!Init())
			glfwTerminate();
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::OnGui() const
	{

	}

	bool Window::Init()
	{
		if (!glfwInit())
		{
			std::cout << "Failed to initialize GLFW" << std::endl;
			return false;
		}
		m_Window = glfwCreateWindow(m_Width, m_Height, m_Name, NULL, NULL);
		if (!m_Window)
		{
			std::cout << "Failed to create Glfw Window" << std::endl;
			return false;
		}
		else
		{
			std::cout << "Success to create Glfw Window" << std::endl;
			glfwMakeContextCurrent(m_Window);
			return true;
		}
	}

	void Window::Clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::Update() const
	{
		glfwPollEvents();

		OnGui();

		glfwSwapBuffers(m_Window);
	}

	bool Window::Closed() const
	{
		return glfwWindowShouldClose(m_Window);
	}
}