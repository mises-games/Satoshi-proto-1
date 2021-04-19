#ifndef CORE_H
#define CORE_H

	#ifdef ST_PLATFORM_WINDOWS
		#ifdef ST_BUILD_DLL
			#define SATOSHI_API _declspec(dllexport)
		#else
			#define SATOSHI_API _declspec(dllimport)
		#endif 
	#else
		#error Satoshi unsupported on this platform
	#endif

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