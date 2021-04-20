#include <stpch.h>
#include "Application.h"

#include <Satoshi/Events/ApplicationEvent.h>
#include <Satoshi/Log.h>

Satoshi::Application::Application() 
{
	m_Window = std::unique_ptr<Window>(Window::Create());
}

Satoshi::Application::~Application()
{
}

void Satoshi::Application::Run()
{
	while (m_Running) 
	{
		m_Window->OnUpdate();
	}
}
