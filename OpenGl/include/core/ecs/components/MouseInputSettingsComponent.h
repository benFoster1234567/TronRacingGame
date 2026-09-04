#pragma once

#include <glm/vec2.hpp>
#include "../coordinator/ECS.h"

namespace Engine::Core::ECS
{
	struct MouseInputSettings : public ComponentBase
	{
		glm::vec2 sensitivity{ 0.07f, 0.05f };
	};
}