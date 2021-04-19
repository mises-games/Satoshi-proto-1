#ifndef APPLICATION_H
#define APPLICATION_H

#include <stpch.h>
#include "Core.h"

namespace Satoshi 
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

#endif