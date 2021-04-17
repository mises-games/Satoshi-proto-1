#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#include "Application.h"
#include "Log.h"
#include "FileHandler.h"
#include "StringHandler.h"

#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

#ifdef ST_PLATFORM_WINDOWS

extern Satoshi::Application* Satoshi::CreateApplication();

int main(int argc, char** argv) 
{
	Satoshi::Log::Init();

	auto a = Satoshi::Log::GetCoreLogger();

	Satoshi::FileHandler::ExtractPathFromFile("./folder/subfolder/text.txt");
	std::string result = Satoshi::StringHandler::Concatenate<std::string>("5","3");

	auto app = Satoshi::CreateApplication();
	app->Run();
	delete app;

	Satoshi::Log::End();

	return 0;
}

#endif


#endif

