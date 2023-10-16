#pragma once

#include <memory>

// Platform detection using predefined macros
#ifdef _WIN32
	/* Windows x64/x86 */
	#ifdef _WIN64
		/* Windows x64 */
		#define MAAT_PLATFORM_WINDOWS
	#else
		/* Windows x64 */
		#error "x86 Builds are not supported!"
	#endif
#elif defined(__APPLE__) || define(__MACH__)
	#include <TargetConditionals.h>
	/* TARGET_OS_MAC exists on all the platforms
	 * so we must check all of them (in this order)
	 * to ensure that we're running on MAC
	 * and not some other Apple platform */
	#if TARGET_IPHONE_SIMULATOR == 1
		#error "IOS simulator is not supported!"
	#elif TARGET_OS_IPHONE == 1
		#define MAAT_PLATFORM_IOS
		#error "IOS is not supported!"
	#elif TARGET_OS_MAC == 1
		#define MAAT_PLATFORM_MACOS
		#error "MacOS is not supported!"
	#else
		#error "Unknown Apple Platform!"
	#endif

/* We also have to check __ANDROID__ before __linux__
 * since android is based on the linux kernel
 * it has __linux__ defined */
#elif defined(__ANDROID__)
	#define MAAT_PLATFORM_ANDROID
	#error "Android is not supported!"
#elif defined(__linux__)
	#define MAAT_PLATFORM_LINUX
	#error "Linux is not supported"
#else
	/* Unknown compiler/platform */
	#error "Unknown platform!"
#endif // End of platform detection

// DLL support
#ifdef MAAT_PLATFORM_WINDOWS
	#if MAAT_DYNAMIC_LINK
		#ifdef MAAT_BUILD_DLL
			#define MAAT_API __declspec(dllexport)
		#else
			#define MAAT_API __declspec(dllexport)
		#endif
	#else
		#define MAAT_API
	#endif
#else
	#error MAAT only supports Windows!
#endif // End of DLL support


#ifdef MAAT_DEBUG
	#define MAAT_ENABLE_ASSERTS
#endif


#ifdef MAAT_ENABLE_ASSERTS
	#define MAAT_ASSERT(x, ...) { if(!(x)) { MAAT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define MAAT_CORE_ASSERT(x, ...) { if(!(x)) { MAAT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
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