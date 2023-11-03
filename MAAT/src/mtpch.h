#pragma once

#include "MAAT/Core/PlatformDetection.h"

#ifdef HZ_PLATFORM_WINDOWS
	#ifndef NOMINMAX
		// See github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-  min-  the-max-and-the-macro
		#define NOMINMAX
	#endif
#endif

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "MAAT/Core/Core.h"

#include "MAAT/Core/Log.h"

#include "MAAT/Debug/Instrumentor.h"

#ifdef MAAT_PLATFORM_WINDOWS
	#include <Windows.h>
#endif