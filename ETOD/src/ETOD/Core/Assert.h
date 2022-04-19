#pragma once

#include "ETOD/Core/Base.h"
#include "ETOD/Core/Log.h"
#include <filesystem>

#ifdef ETOD_ENABLE_ASSERTS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define ETOD_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { ETOD##type##ERROR(msg, __VA_ARGS__); ETOD_DEBUGBREAK(); } }
#define ETOD_INTERNAL_ASSERT_WITH_MSG(type, check, ...) ETOD_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define ETOD_INTERNAL_ASSERT_NO_MSG(type, check) ETOD_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", ETOD_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define ETOD_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define ETOD_INTERNAL_ASSERT_GET_MACRO(...) ETOD_EXPAND_MACRO( ETOD_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, ETOD_INTERNAL_ASSERT_WITH_MSG, ETOD_INTERNAL_ASSERT_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define ETOD_ASSERT(...) ETOD_EXPAND_MACRO( ETOD_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define ETOD_CORE_ASSERT(...) ETOD_EXPAND_MACRO( ETOD_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define ETOD_ASSERT(...)
#define ETOD_CORE_ASSERT(...)
#endif
