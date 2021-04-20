#ifndef APPLICATION_H
#define APPLICATION_H

#include <stpch.h>
#include "Core.h"
#include <Satoshi/Window.h>

namespace Satoshi 
{
	class SATOSHI_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;

		bool m_Running;
	};

	Application* CreateApplication();
}

#endif