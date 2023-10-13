#pragma once

#include <memory>

#ifdef MAAT_PLATFORM_WINDOWS
#if MAAT_DYNAMIC_LINK
	#ifdef MAAT_BUILD_DLL
		#define MAAT_API __declspec(dllexport)
	#else
		#define MAAT_API __declspec(dllimport)
	#endif
#else
	#define MAAT_API
#endif
#else
	#error MAAT only supports Windows!
#endif
/*
#ifdef MAAT_DEBUG
	#define MAAT_ENABLE_ASSERTS
#endif
*/

#ifdef MAAT_ENABLE_ASSERTS
	#define MAAT_ASSERT(x, ...) { if(!(x)) { MAAT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define MAAT_CORE_ASSERT(x, ...) { if(!(x)) { MAAT__CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define MAAT_ASSERT(x, ...)
	#define MAAT_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define MAAT_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace MAAT {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;
}