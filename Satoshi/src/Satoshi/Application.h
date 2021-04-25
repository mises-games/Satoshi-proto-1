#ifndef APPLICATION_H
#define APPLICATION_H

#include <Satoshi/Core.h>
#include <Satoshi/Events/Event.h>
#include <Satoshi/Events/ApplicationEvent.h>

#include <Satoshi/Log.h>

#include <Satoshi/Window.h>
#include <Satoshi/LayerStack.h>
#include <Satoshi/ImGui/ImGuiLayer.h>

namespace Satoshi 
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow();

		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running;
		LayerStack m_LayerStack;

		static Application* s_Instance;
		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
	};

	Application* CreateApplication();
}

#endif
