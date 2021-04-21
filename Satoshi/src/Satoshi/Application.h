#ifndef APPLICATION_H
#define APPLICATION_H

#include <Satoshi/Core.h>
#include <Satoshi/Events/Event.h>
#include <Satoshi/Events/ApplicationEvent.h>

#include <Satoshi/Log.h>

#include <Satoshi/Window.h>

namespace Satoshi 
{
	class SATOSHI_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running;
	};

	Application* CreateApplication();
}

#endif
