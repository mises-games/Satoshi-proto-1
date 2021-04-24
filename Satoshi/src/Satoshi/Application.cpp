#include <stpch.h>
#include "Application.h"

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <Satoshi/Input.h>
#include <Satoshi/KeyCodes.h>
#include <Samples/Samples.h>

#define BIND_EVENT_FUNCTION(x) std::bind(&Satoshi::Application::x, this, std::placeholders::_1)

Satoshi::Application* Satoshi::Application::s_Instance = nullptr;

Satoshi::Application::Application() 
{
	ST_CORE_ASSERT(!s_Instance, "Application already created!");
	s_Instance = this;

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
		Sample1();
		glClearColor(0, 0.5, 0.25, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		for (Layer* layer : m_LayerStack)
			layer->OnUpdate();

		m_Window->OnUpdate();
	}
}

void Satoshi::Application::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNCTION(OnWindowClose));

	for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); ) 
	{
		it--;
		(*it)->OnEvent(e);
		if (e.m_Handled)
			break;
	}
}

void Satoshi::Application::PushLayer(Layer* layer)
{
	m_LayerStack.PushLayer(layer);
	layer->OnAttach();
}

void Satoshi::Application::PushOverlay(Layer* layer)
{
	m_LayerStack.PushOverlay(layer);
	layer->OnAttach();
}

Satoshi::Window& Satoshi::Application::GetWindow()
{
	return *m_Window;
}

bool Satoshi::Application::OnWindowClose(WindowCloseEvent& e)
{
	m_Running = false;
	return true;
}
