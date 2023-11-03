#pragma once

#include "MAAT/Core/Core.h"
#include "MAAT/Core/Log.h"
#include <filesystem>

#ifdef MAAT_ENABLE_ASSERTS

// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
#define MAAT_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { MAAT##type##ERROR(msg, __VA_ARGS__); MAAT_DEBUGBREAK(); } }
#define MAAT_INTERNAL_ASSERT_WITH_MSG(type, check, ...) MAAT_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
#define MAAT_INTERNAL_ASSERT_NO_MSG(type, check) MAAT_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", MAAT_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

#define MAAT_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
#define MAAT_INTERNAL_ASSERT_GET_MACRO(...) MAAT_EXPAND_MACRO( MAAT_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, MAAT_INTERNAL_ASSERT_WITH_MSG, MAAT_INTERNAL_ASSERT_NO_MSG) )

// Currently accepts at least the condition and one additional parameter (the message) being optional
#define MAAT_ASSERT(...) MAAT_EXPAND_MACRO( MAAT_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
#define MAAT_CORE_ASSERT(...) MAAT_EXPAND_MACRO( MAAT_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
#define MAAT_ASSERT(...)
#define MAAT_CORE_ASSERT(...)
#endif