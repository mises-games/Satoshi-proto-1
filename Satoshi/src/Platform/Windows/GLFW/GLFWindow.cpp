#include "stpch.h"
#include "GLFWindow.h"

#include <Satoshi/Log.h>

#include <Satoshi/Events/KeyEvent.h>
#include <Satoshi/Events/MouseEvent.h>
#include <Satoshi/Events/ApplicationEvent.h>

#include <Platform/Renderer/OpenGL/OpenGLContext.h>

#include <glad/gl.h>

namespace Satoshi
{
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description)
	{
		ST_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	Window* Window::Create(const WindowProps& props)
	{
		return new GLFWindow(props);
	}

	GLFWindow::GLFWindow(const WindowProps& props)
	{
		Init(props);
	}

	GLFWindow::~GLFWindow()
	{
		Shutdown();
	}

	void GLFWindow::OnUpdate()
	{
		glfwPollEvents();
		m_Context->SwapBuffers();
	}

	unsigned GLFWindow::GetWidth() const
	{
		return m_Data.Width;
	}

	unsigned GLFWindow::GetHeight() const
	{
		return m_Data.Height;
	}

	void GLFWindow::SetEventCallback(const EventCallbackFunction& callback)
	{
		m_Data.EventCallback = callback;
	}

	void GLFWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool GLFWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

	void* GLFWindow::GetNativeWindow() const
	{
		return m_Window;
	}

	void* GLFWindow::GetImGuiLayer() const
	{
		return m_ImGuiLayer;
	}

	void GLFWindow::Init(const WindowProps& props)
	{
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		m_Data.Title = props.Title;

		m_ImGuiLayer = new OpenGLImGuiLayer();

		ST_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			ST_CORE_ASSERT(success,"Couldn't initialize GLFW");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
		
		m_Context = new OpenGLContext(m_Window);
		m_Context->Init();

		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		SetGLCallbacks();
	}

	void GLFWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void GLFWindow::SetGLCallbacks()
	{
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;

			WindowResizeEvent event((unsigned) width, (unsigned) height);
			data.EventCallback(event);
		});
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallback(event);

		});
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS: 
				{
					KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break; 
				}
				case GLFW_RELEASE: 
				{
					KeyReleasedEvent event(key);
					data.EventCallback(event);
					break; 
				}
				case GLFW_REPEAT: 
				{
					KeyPressedEvent event(key, 1);
					data.EventCallback(event);
					break; 
				}
			}
		});
		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned keycode)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			KeyTypedEvent event(keycode);
			data.EventCallback(event);
		});
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action)
			{
				case GLFW_PRESS: 
				{
					MouseButtonPressedEvent event(button);
					data.EventCallback(event);
					break; 
				}
				case GLFW_RELEASE: 
				{
					MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break; 
				}
			}
		});
		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.EventCallback(event);
		});
		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseMovedEvent event((float)xPos, (float)yPos);
			data.EventCallback(event);
		});
	}


}
