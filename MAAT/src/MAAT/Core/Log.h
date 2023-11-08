#pragma once

#include "MAAT/Core/Core.h"

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

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

template<typename OStream, glm::length_t L, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::vec<L, T, Q>& vector)
{
	return os << glm::to_string(vector);
}

template<typename OStream, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::mat<C, R, T, Q>& matrix)
{
	return os << glm::to_string(matrix);
}

template<typename OStream, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, glm::qua<T, Q> quaternion)
{
	return os << glm::to_string(quaternion);
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
