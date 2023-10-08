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