#pragma once
#include <glm/ext/vector_float3.hpp>
#include "../coordinator/ECS.h"

namespace Engine::Core::ECS
{
	struct StaticPointLightComponent : ComponentBase
	{
		glm::vec3 color{};
		float radius{};
		float intensity{ 1.0f };
		bool castShadows{ false };
	};

	struct ShadowCastComponent : ComponentBase
	{
	};

}