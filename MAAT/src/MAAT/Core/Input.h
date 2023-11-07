#pragma once

#include "MAAT/Core/KeyCodes.h"
#include "MAAT/Core/MouseCodes.h"

#include <glm/glm.hpp>

namespace MAAT {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}