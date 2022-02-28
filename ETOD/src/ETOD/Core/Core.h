#pragma once

#include <memory>

// Platform detection using predefined macros
#ifdef _WIN32
	/* Windows x64/x86 */
	#ifdef _WIN64
		/* Windows x64 */
		#define ETOD_PALTFROM_WINDOWS
	#else
		/* Windows x86 */
		#error "x86 Builds are not supported!"
	#endif
#elif defined(__APPLE__) || defined(__MACH__)
	#include <TargetConditionals.h>
	/* TARGET_OS_MAC exists on all the platforms
	 * so we must check all of them (in this order)
	 * to ensure that we're running on MAC
	 * and not some other Apple platform */
	#if TARGET_IPHONE_SIMULATOR == 1
		#error "IOS simulator is not supported!"
	#elif TARGET_OS_IPHONE == 1
		#define ETOD_PLATFORM_IOS
		#error "IOS is not supported!"
	#elif TARGET_OS_MAC == 1
		#define ETOD_PLATFORM_MACOS
		#error "MacOS is not supported!"
	#else
		#error "Unknown Apple platform!"
	#endif
/* We also have to check __ANDROID__ before __linux__
 * since android is based on the linux kernel
 * it has __linux__ defined */
#elif defined(__ANDROID__)
	#define ETOD_PLATFORM_ANDROID
	#error "Android is not supported!"
#elif defined(__linux__)
	#define ETOD_PLATFORM_LINUX
	#error "Linux is not supported!"
#else
	/* Unknow compiler/platform */	
	#error "Unknow platform!"
#endif // End of platform detection

#ifdef ETOD_DEBUG
	#define ETOD_ENABLE_ASSERTS
#endif

#ifdef ETOD_PLATFORM_WINDOWS
#if ETOD_DYNAMIC_LINK
	#ifdef ETOD_BUILD_DLL
		#define ETOD_API _declspec(dllexport)
	#else
		#define ETOD_API _declspec(dllimport)
	#endif
#else
	#define ETOD_API
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

#define ETOD_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace ETOD {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}