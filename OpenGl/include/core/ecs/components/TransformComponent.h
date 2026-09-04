#pragma once

#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>
#include "../coordinator/ECS.h"

namespace Engine::Core::ECS
{
	struct TransformComponent : public ComponentBase
	{
		glm::vec3 position{ 0.0f, 0.0f, 0.0f };
		glm::quat rotation{ 1.0f, 0.0f, 0.0f, 0.0f };
		glm::vec3 scale{ 1.0f, 1.0f, 1.0f };
	};
}