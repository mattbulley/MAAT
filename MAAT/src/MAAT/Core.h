#pragma once

#ifdef MAAT_PLATFORM_WINDOWS
	#ifdef MAAT_BUILD_DLL
		#define MAAT_API __declspec(dllexport)
	#else
		#define MAAT_API __declspec(dllimport)
	#endif
#else
	#error MAAT only supports Windows!
#endif

#ifdef MAAT_ENABLE_ASSERTS
	#define MAAT_ASSERT(x, ...) { if(!(x)) { MAAT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define MAAT_CORE_ASSERT(x, ...) { if(!(x)) { MAAT__CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define MAAT_ASSERT(x, ...)
	#define MAAT_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)