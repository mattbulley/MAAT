#pragma once

#include "MAAT/Core/PlatformDetection.h"

#include <memory>

#ifdef MAAT_DEBUG
#if defined(MAAT_PLATFORM_WINDOWS)
#define MAAT_DEBUGBREAK() __debugbreak()
#elif defined(MAAT_PLATFORM_LINUX)
#include <signal.h>
#define MAAT_DEBUGBREAK() raise(SIGTRAP)
#else
#error "Platform doesn't support debugbreak yet!"
#endif
#define MAAT_ENABLE_ASSERTS
#else
#define MAAT_DEBUGBREAK()
#endif

#define MAAT_EXPAND_MACRO(x) x
#define MAAT_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define MAAT_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace MAAT {

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

#include "MAAT/Core/Log.h"
#include "MAAT/Core/Assert.h"