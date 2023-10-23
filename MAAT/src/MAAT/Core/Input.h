#pragma once

#include "MAAT/Core/Core.h"
#include "MAAT/Core/KeyCodes.h"
#include "MAAT/Core/MouseCodes.h"

namespace MAAT {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	/*private:
		static Scope<Input> s_Instance;*/
	};
}