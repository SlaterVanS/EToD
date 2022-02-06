#pragma once

#ifdef ETOD_PLATFORM_WINDOWS
	#ifdef ETOD_BUILD_DLL
		#define ETOD_API _declspec(dllexport)
	#else
		#define ETOD_API _declspec(dllimport)
	#endif
#else
	#error ETOD only support Windows!
#endif

#ifdef ETOD_ENABLE_ASSERTS
	#define ETOD_ASSERT(x, ...) { if(!(x)) { ETOD_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ETOD_CORE_ASSERT(x, ...) { if(!(x)) { ETOD_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ETOD_ASSERT(x, ...)
	#define ETOD_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)