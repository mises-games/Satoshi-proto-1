#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#include "Application.h"
#include "Log.h"
#include "./Utils/FileHandler.h"
#include "./Utils/StringHandler.h"

#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

#ifdef ST_PLATFORM_WINDOWS

extern Satoshi::Application* Satoshi::CreateApplication();

int main(int argc, char** argv) 
{
	Satoshi::Log::Init();

	auto app = Satoshi::CreateApplication();
	app->Run();
	delete app;

	Satoshi::Log::End();

	return 0;
}

#endif


#endif

