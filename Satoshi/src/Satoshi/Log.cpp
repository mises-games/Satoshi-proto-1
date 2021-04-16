#include "Log.h"
#include <cstdint>

namespace Satoshi 
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] [%l] %n: %v%$");
		

		s_CoreLogger = spdlog::basic_logger_mt("CORE", "logs/core.txt");
				
		s_ClientLogger = spdlog::basic_logger_mt("APP","logs/client.txt");
	}
}