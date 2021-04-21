#include <stpch.h>
#include "Application.h"

#include <GLFW/glfw3.h>

#define BIND_EVENT_FUNCTION(x) std::bind(&Satoshi::Application::x, this, std::placeholders::_1)

Satoshi::Application::Application() 
{
	m_Window = std::unique_ptr<Window>(Window::Create());
	m_Window->SetEventCallback(BIND_EVENT_FUNCTION(OnEvent));
}

Satoshi::Application::~Application()
{
}

void Satoshi::Application::Run()
{
	while (m_Running) 
	{
		glClearColor(0,0.5,0.25,1);
		glClear(GL_COLOR_BUFFER_BIT);
		m_Window->OnUpdate();
	}
}

void Satoshi::Application::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNCTION(OnWindowClose));

	ST_CORE_TRACE("{0}", e.ToString());
}

bool Satoshi::Application::OnWindowClose(WindowCloseEvent& e)
{
	m_Running = false;
	return true;
}
