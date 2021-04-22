#ifndef APPLICATION_H
#define APPLICATION_H

#include <Satoshi/Core.h>
#include <Satoshi/Events/Event.h>
#include <Satoshi/Events/ApplicationEvent.h>

#include <Satoshi/Log.h>

#include <Satoshi/Window.h>
#include <Satoshi/LayerStack.h>

namespace Satoshi 
{
	class SATOSHI_API Application
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
		bool m_Running;
		LayerStack m_LayerStack;

		static Application* s_Instance;
	};

	Application* CreateApplication();
}

#endif
