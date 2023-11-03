#include "mtpch.h"
#include "MAAT/Core/Window.h"

#ifdef MAAT_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif

namespace MAAT
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
	#ifdef MAAT_PLATFORM_WINDOWS
			return CreateScope<WindowsWindow>(props);
	#else
			MAAT_CORE_ASSERT(false, "Unknown platform!");
			return nullptr;
	#endif
	}

}