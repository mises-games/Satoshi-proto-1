#ifndef APPLICATION_H
#define APPLICATION_H

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