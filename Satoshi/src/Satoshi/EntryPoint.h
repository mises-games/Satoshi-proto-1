#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#include "Application.h"
#include "Log.h"

#include <codecvt>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;


#ifdef ST_PLATFORM_WINDOWS

extern Satoshi::Application* Satoshi::CreateApplication();

int main(int argc, char** argv) 
{
	Satoshi::Log::Init();

	
	ST_CORE_INFO(u8"Teste japonês: おめでとう, vamos por mais valores");
	ST_CORE_INFO(u8"君はポルトガル語を話しますか。");

	json j2 = 
	{
	  {"pi", 3.141},
	  {"happy", true},
	  {"name", "Niels"},
	  {"nothing", nullptr},
	  {"answer", {
		{"everything", 42}
	  }},
	  {"list", {1, 0, 2}},
	  {"object", {
		{"currency", "USD"},
		{"value", 42.99}
	  }}
	};

	double a = 3.141;
	ST_ERR(u8"Hello Var={0}", "string");
	ST_WARN(u8"Nova string");

	auto app = Satoshi::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif


#endif

