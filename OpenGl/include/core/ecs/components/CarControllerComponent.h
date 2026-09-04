#pragma once

#include "core/input/Keys.h"
#include "core/ecs/coordinator/ECS.h"

namespace Engine::Core::ECS
{
	struct CarControllerComponent : public ComponentBase
	{
		KeyCode forward{ KeyCode::W };
		KeyCode backward{ KeyCode::S };
		KeyCode turnLeft{ KeyCode::A };
		KeyCode turnRight{ KeyCode::D };
		float accelerationRate{ 5.0f };
		float turnRate{ 2.0f };
		float frictionFactor{ 0.9f };
	};
}