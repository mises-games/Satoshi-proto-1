#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#include "Application.h"
#include "Log.h"

#ifdef ST_PLATFORM_WINDOWS

extern Satoshi::Application* Satoshi::CreateApplication();

int main(int argc, char** argv) 
{
	Satoshi::Log::Init();

	ST_CORE_INFO("Teste japonês: おめでとう, vamos por mais valores");
	unsigned a = 8;
	ST_ERR("Hello Var={0}",a);

	auto app = Satoshi::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif


#endif

