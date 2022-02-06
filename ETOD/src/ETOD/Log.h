#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace ETOD {
	class ETOD_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog :: logger> s_CoreLogger;
		static std::shared_ptr<spdlog :: logger> s_ClientLogger;
	};
}

//Core log macros
#define ETOD_CORE_TRACE(...)     ::ETOD::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ETOD_CORE_INFO(...)      ::ETOD::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ETOD_CORE_WARN(...)      ::ETOD::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ETOD_CORE_ERROR(...)     ::ETOD::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ETOD_CORE_FATAL(...)     ::ETOD::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define ETOD_TRACE(...)          ::ETOD::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ETOD_INFO(...)           ::ETOD::Log::GetClientLogger()->info(__VA_ARGS__)
#define ETOD_WARN(...)           ::ETOD::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ETOD_ERROR(...)          ::ETOD::Log::GetClientLogger()->error(__VA_ARGS__)
#define ETOD_FATAL(...)          ::ETOD::Log::GetClientLogger()->fatal(__VA_ARGS__)
