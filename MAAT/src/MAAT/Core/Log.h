#pragma once

#include "MAAT/Core/Core.h"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#pragma warning(pop)

namespace MAAT {

	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define MAAT_CORE_TRACE(...)      ::MAAT::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MAAT_CORE_INFO(...)       ::MAAT::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MAAT_CORE_WARN(...)       ::MAAT::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MAAT_CORE_ERROR(...)      ::MAAT::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MAAT_CORE_CRITICAL(...)   ::MAAT::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define MAAT_TRACE(...)           ::MAAT::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MAAT_INFO(...)            ::MAAT::Log::GetClientLogger()->info(__VA_ARGS__)
#define MAAT_WARN(...)            ::MAAT::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MAAT_ERROR(...)           ::MAAT::Log::GetClientLogger()->error(__VA_ARGS__)
#define MAAT_CRITICAL(...)        ::MAAT::Log::GetClientLogger()->critical(__VA_ARGS__)
