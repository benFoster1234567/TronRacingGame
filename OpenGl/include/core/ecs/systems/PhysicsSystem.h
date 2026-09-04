#pragma once

#include "core/ecs/coordinator/System.h"

namespace Engine::Core::ECS
{
	class Coordinator;

	class PhysicsSystem : public System
	{
	public:
		void update(Coordinator& coordinator, float deltaTime);
	};
}