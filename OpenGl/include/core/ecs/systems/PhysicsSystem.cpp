#include "PhysicsSystem.h"

#include "core/ecs/coordinator/Coordinator.h"
#include "../components/MotionPropertiesComponent.h"
#include "../components/TransformComponent.h"

namespace Engine::Core::ECS
{
	void PhysicsSystem::update(Coordinator& coordinator, float deltaTime)
	{
		commandQueue.clear();
		for (Entity entity : entities)
		{
			auto transform = coordinator.getComponent<TransformComponent>(entity);
			PhysicsEngineCommand pec
			{
				.entityId = entity,
				.position = transform.position,
				.rotation = transform.rotation
			};
			commandQueue.push_back(pec);
		}
	}

	std::vector<PhysicsEngineCommand> PhysicsSystem::getCommands()
	{
		return commandQueue;
	}

	void PhysicsSystem::pollPhysicsEngine(const std::vector<PhysicsEvent>& eventList)
	{
		eventQueue = eventList;
	}

}