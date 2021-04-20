#include "stpch.h"
#include "WindowsWindow.h"
#include "Satoshi/Log.h"

namespace Satoshi 
{
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description)
	{
		ST_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	unsigned WindowsWindow::GetWidth() const
	{
		return m_Data.Width;
	}

	unsigned WindowsWindow::GetHeight() const
	{
		return m_Data.Height;
	}

	void WindowsWindow::SetEventCallback(const EventCallbackFunction& callback)
	{
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
	}

	bool WindowsWindow::IsVSync() const
	{
		return false;
	}

	void* WindowsWindow::GetNativeWindow() const
	{
		return m_Window;
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		m_Data.Title = props.Title;

		ST_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			ST_CORE_ASSERT(success, "Couldn't initialize GLFW");
			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void WindowsWindow::Shutdown()
	{
	}
}