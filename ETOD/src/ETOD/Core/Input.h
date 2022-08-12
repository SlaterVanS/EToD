#pragma once

#include "ETOD/Core/KeyCodes.h"
#include "ETOD/Core/MouseCodes.h"

#include <glm/glm.hpp>

namespace ETOD {

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