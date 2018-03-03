
#include "window.h"
#include "Mouse.h"
#include "Keyboard.h"

namespace graphics
{
	void setup(GLFWwindow* window);
	void renderer(ImDrawData* draw_data);


	void setup(GLFWwindow* window)
	{
		unsigned char* pixels;
		int width,
			height,
			display_width,
			display_height;
		GLuint g_FontTexture;

		ImGuiIO& io{ ImGui::GetIO() };

		io.Fonts->GetTexDataAsAlpha8(&pixels, &width, &height);

		// Upload texture to graphics system
		GLint last_texture;
		glGetIntegerv(GL_TEXTURE_BINDING_2D, &last_texture);
		glGenTextures(1, &g_FontTexture);
		glBindTexture(GL_TEXTURE_2D, g_FontTexture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, width, height, 0, GL_ALPHA, GL_UNSIGNED_BYTE, pixels);

		// Get display size
		glfwGetWindowSize(window, &width, &height);
		glfwGetFramebufferSize(window, &display_width, &display_height);

		io.DisplaySize = ImVec2((float)width, (float)height);
		io.RenderDrawListsFn = renderer;
		io.Fonts->TexID = (void *)(intptr_t)g_FontTexture;

		// Restore state
		glBindTexture(GL_TEXTURE_2D, last_texture);
	}

	/*! /brief Boilerplate function for OpenGL 2.0 rendering.
	*
	*  This function isn't written by us, but is mandatory
	*  boilerplate from the library. It can be copy/pasted
	*  into your projects, but should really be part of the
	*  library itself?
	*/
	void renderer(ImDrawData* draw_data)
	{
		ImGuiIO& io{ ImGui::GetIO() };
		int fb_width{ (int)(io.DisplaySize.x * io.DisplayFramebufferScale.x) };
		int fb_height{ (int)(io.DisplaySize.y * io.DisplayFramebufferScale.y) };

		draw_data->ScaleClipRects(io.DisplayFramebufferScale);

		GLint last_texture; glGetIntegerv(GL_TEXTURE_BINDING_2D, &last_texture);
		GLint last_viewport[4]; glGetIntegerv(GL_VIEWPORT, last_viewport);
		glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_TRANSFORM_BIT);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glDisable(GL_CULL_FACE);
		glDisable(GL_DEPTH_TEST);
		glEnable(GL_SCISSOR_TEST);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glEnable(GL_TEXTURE_2D);

		// Setup viewport, orthographic projection matrix
		glViewport(0, 0, (GLsizei)fb_width, (GLsizei)fb_height);
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		glOrtho(0.0f, io.DisplaySize.x, io.DisplaySize.y, 0.0f, -1.0f, +1.0f);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();

		// Render command lists
#define OFFSETOF(TYPE, ELEMENT) ((size_t)&(((TYPE *)0)->ELEMENT))
		for (int n = 0; n < draw_data->CmdListsCount; n++)
		{
			const ImDrawList* cmd_list = draw_data->CmdLists[n];
			const unsigned char* vtx_buffer = (const unsigned char*)&cmd_list->VtxBuffer.front();
			const ImDrawIdx* idx_buffer = &cmd_list->IdxBuffer.front();
			glVertexPointer(2, GL_FLOAT, sizeof(ImDrawVert), (void*)(vtx_buffer + OFFSETOF(ImDrawVert, pos)));
			glTexCoordPointer(2, GL_FLOAT, sizeof(ImDrawVert), (void*)(vtx_buffer + OFFSETOF(ImDrawVert, uv)));
			glColorPointer(4, GL_UNSIGNED_BYTE, sizeof(ImDrawVert), (void*)(vtx_buffer + OFFSETOF(ImDrawVert, col)));

			for (int cmd_i = 0; cmd_i < cmd_list->CmdBuffer.size(); cmd_i++)
			{
				const ImDrawCmd* pcmd = &cmd_list->CmdBuffer[cmd_i];
				if (pcmd->UserCallback)
				{
					pcmd->UserCallback(cmd_list, pcmd);
				}
				else
				{
					glBindTexture(GL_TEXTURE_2D, (GLuint)(intptr_t)pcmd->TextureId);
					glScissor((int)pcmd->ClipRect.x, (int)(fb_height - pcmd->ClipRect.w), (int)(pcmd->ClipRect.z - pcmd->ClipRect.x), (int)(pcmd->ClipRect.w - pcmd->ClipRect.y));
					glDrawElements(GL_TRIANGLES, (GLsizei)pcmd->ElemCount, sizeof(ImDrawIdx) == 2 ? GL_UNSIGNED_SHORT : GL_UNSIGNED_INT, idx_buffer);
				}
				idx_buffer += pcmd->ElemCount;
			}
		}
#undef OFFSETOF

		// Restore modified state
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glBindTexture(GL_TEXTURE_2D, last_texture);
		glMatrixMode(GL_MODELVIEW);
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glPopAttrib();
		glViewport(last_viewport[0], last_viewport[1], (GLsizei)last_viewport[2], (GLsizei)last_viewport[3]);
	}

	double Window::m_DeltaTime = 0;

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
		ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiCond_FirstUseEver);
		ImGui::ShowTestWindow();
		ImGui::Render();
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
		
		std::cout << "Success to create Glfw Window" << std::endl;
		glfwMakeContextCurrent(m_Window);
		

		//GLFW Setup
		int width, height;
		glfwGetFramebufferSize(m_Window, &width, &height);
		glfwSwapInterval(1);

		glfwSetCursorPosCallback(m_Window, Mouse::MousePosCallBack);
		glfwSetMouseButtonCallback(m_Window, Mouse::MouseButtonCallBack);
		glfwSetKeyCallback(m_Window, Keyboard::KeyboardCallback);

		setup(m_Window);

		const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

		int xPos = (mode->width - m_Width) / 2;
		int yPos = (mode->height - m_Height) / 2;

		glfwSetWindowPos(m_Window, xPos, yPos);

		//GL Setup		
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, width, 0, height, -10, 10);
		glDepthRange(-10, 10);
		glMatrixMode(GL_MODELVIEW);
		//Alpha Blending
		glEnable(GL_ALPHA_TEST);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		lastTime = glfwGetTime();

		return true;			
	}

	void Window::BeginRender() const
	{
		glClearColor(0.5, 0.5, 0.5, 0.5);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



		ImGui::NewFrame();
		OnGui();
	}

	void Window::EndRender() const
	{
		glfwSwapBuffers(m_Window);
	}

	void Window::Update()
	{
		double nowTime = glfwGetTime();
		m_DeltaTime = nowTime - lastTime;	
		lastTime = nowTime;
		glfwPollEvents();
	}

	bool Window::Closed() const
	{
		return glfwWindowShouldClose(m_Window);
	}

	const double Window::GetDeltaTime()
	{
		return m_DeltaTime;
	}

}