#pragma once

#include <memory>

#include "ETOD/Core/PlatformDetection.h"

#ifdef ETOD_DEBUG
#if defined(ETOD_PLATFORM_WINDOWS)
#define ETOD_DEBUGBREAK() __debugbreak()
#elif defined(ETOD_PLATFORM_LINUX)
#include <signal.h>
#define ETOD_DEBUGBREAK() raise(SIGTRAP)
#else
#error "Platform doesn't support debugbreak yet!"
#endif
#define ETOD_ENABLE_ASSERTS
#else
#define ETOD_DEBUGBREAK()
#endif

#define ETOD_EXPAND_MACRO(x) x
#define ETOD_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define ETOD_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

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

#include "ETOD/Core/Log.h"
#include "ETOD/Core/Assert.h"
