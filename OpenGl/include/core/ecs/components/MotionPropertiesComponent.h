#pragma once

#include <glm/vec3.hpp>
#include "../coordinator/ECS.h"

namespace Engine::Core::ECS
{
	struct MotionPropertiesComponent : public ComponentBase
	{
		glm::vec3 velocity{};
		glm::vec3 acceleration{};
	};
}