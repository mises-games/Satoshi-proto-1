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
