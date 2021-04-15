#include "Log.h"
#include <cstdint>

namespace Satoshi 
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_CoreLogger = spdlog::rotating_logger_mt("SATOSHI","logs/core.txt", UINT32_MAX, 1);
				
		s_ClientLogger = spdlog::rotating_logger_mt("APP","logs/client.txt", UINT32_MAX, 1);
	}
}