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

	m_ImGuiLayer = (ImGuiLayer *)m_Window->GetImGuiLayer();
	PushOverlay(m_ImGuiLayer);

	glGenVertexArrays(1, &m_VertexArray);
	glBindVertexArray(m_VertexArray);

	glGenBuffers(1, &m_VertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);

	float vertices [9] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

	glGenBuffers(1, &m_IndexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,m_IndexBuffer);

	unsigned int indices[3] = { 0, 1, 2 };
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
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

		glBindVertexArray(m_VertexArray);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

		for (Layer* layer : m_LayerStack)
			layer->OnUpdate();

		m_ImGuiLayer->Begin();
		for (Layer* layer : m_LayerStack)
			layer->OnImGuiRender();
		m_ImGuiLayer->End();

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
}

void Satoshi::Application::PushOverlay(Layer* layer)
{
	m_LayerStack.PushOverlay(layer);
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
