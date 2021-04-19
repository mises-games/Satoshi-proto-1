#include <stpch.h>
#include "Log.h"

#include <spdlog/sinks/basic_file_sink.h>

namespace Satoshi 
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	std::string Log::s_CoreFilename;
	std::string Log::s_ClientFilename;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] [%l] %n: %v%$");
		
		s_CoreFilename = "./logs/core.txt";
		s_ClientFilename = "./logs/client.txt";

		s_CoreLogger = spdlog::basic_logger_mt("CORE", s_CoreFilename);
		s_ClientLogger = spdlog::basic_logger_mt("APP",s_ClientFilename);
	}

	void Log::End()
	{
		s_CoreLogger->~logger();
		s_ClientLogger->~logger();

		remove(s_CoreFilename.c_str());
		remove(s_ClientFilename.c_str());
	}
}