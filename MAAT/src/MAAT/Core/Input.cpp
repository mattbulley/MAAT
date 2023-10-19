#include "mtpch.h"
#include "MAAT/Core/Input.h"

#ifdef MAAT_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsInput.h"
#endif

namespace MAAT {

	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
#ifdef MAAT_PLATFORM_WINDOWS
		return CreateScope<WindowsInput>();
#else
		MAAT_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}
}