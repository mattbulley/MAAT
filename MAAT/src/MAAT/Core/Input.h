#pragma once

#include <glm/glm.hpp>

#include "MAAT/Core/KeyCodes.h"
#include "MAAT/Core/MouseCodes.h"

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