#include <stpch.h>
#include "Application.h"

#include <Satoshi/Events/ApplicationEvent.h>
#include <Satoshi/Log.h>

Satoshi::Application::Application() 
{

}

Satoshi::Application::~Application()
{
}

void Satoshi::Application::Run()
{
	WindowResizeEvent e(1280, 720);
	std::cout << "Teste Ativo" << std::endl;
	/*if (e.IsInCategory(EventCategoryApplication) || e.IsInCategory(EventCategoryApplication))
		ST_TRACE(e);*/
	while (true);
}
