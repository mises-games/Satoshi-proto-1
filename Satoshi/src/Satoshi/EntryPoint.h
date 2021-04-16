#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#include "Application.h"
#include "Log.h"
#include "FileHandler.h"

#include <codecvt>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;


#ifdef ST_PLATFORM_WINDOWS

extern Satoshi::Application* Satoshi::CreateApplication();

int main(int argc, char** argv) 
{
	Satoshi::Log::Init();
	
	std::string val;
	std::u16string val2;
	std::u32string val3;

	auto a = Satoshi::FileHandler::ReadFile<std::string>("files/reader.txt", &val);
	auto b = Satoshi::FileHandler::ReadFile<std::u16string>("files/reader2.txt", &val2);
	auto c = Satoshi::FileHandler::ReadFile<std::u32string>("files/reader3.txt", &val3);

	auto a_out = Satoshi::FileHandler::WriteFile<std::string>("files/writer.txt", val);
	auto b_out = Satoshi::FileHandler::WriteFile<std::u16string>("files/writer2.txt", val2);
	auto c_out = Satoshi::FileHandler::WriteFile<std::u32string>("files/writer3.txt", val3);

	auto app = Satoshi::CreateApplication();
	app->Run();
	delete app;

	Satoshi::Log::End();

	return 0;
}

#endif


#endif

