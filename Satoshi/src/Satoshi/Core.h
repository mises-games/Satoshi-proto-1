#ifndef CORE_H
#define CORE_H

#include <stpch.h>

#ifdef ST_PLATFORM_MSDOS
	#if ST_DYNAMIC_LINK
		#ifdef ST_BUILD_DLL
			#define SATOSHI_API _declspec(dllexport)
		#else
			#define SATOSHI_API _declspec(dllimport)
		#endif
	#else
		#define SATOSHI_API
	#endif
#else
	#error Satoshi unsupported on this platform
#endif

#ifdef ST_DEBUG
	#define ST_ENABLE_ASSERTS
#endif

#ifdef ST_ENABLE_ASSERTS
	#define ST_ASSERT(x, ...) {if(!(x)) { ST_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define ST_CORE_ASSERT(x, ...) {if(!(x)) { ST_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define ST_ASSERT(x, ...)
	#define ST_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define ST_BIND_EVENT_FUNCTION(fn) std::bind(&fn, this, std::placeholders::_1)

#endif
