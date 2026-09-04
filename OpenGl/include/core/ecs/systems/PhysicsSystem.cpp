#include "PhysicsSystem.h"

#include "core/ecs/coordinator/Coordinator.h"
#include "../components/MotionPropertiesComponent.h"
#include "../components/TransformComponent.h"

namespace Engine::Core::ECS
{
	void PhysicsSystem::update(Coordinator& coordinator, float deltaTime)
	{
		for (Entity entity : entities)
		{
			MotionPropertiesComponent& motionProps = coordinator.getComponent<MotionPropertiesComponent>(entity);
			TransformComponent& transform = coordinator.getComponent<TransformComponent>(entity);

			float t{ deltaTime };

			glm::vec3 deltaVelocity = motionProps.acceleration * t;
			glm::vec3 deltaPos = t * (motionProps.velocity + (0.5f * motionProps.acceleration * t));

			motionProps.velocity += deltaVelocity;
			transform.position += deltaPos;
		}
	}

}