#include <iostream>

#include "BtPhysicsEngine.h"
#define PIPELINE_TESTING_MODE

namespace Engine::Infra
{
	void BtPhysicsEngine::createBoudingBox(Core::ECS::Entity, glm::vec3 dim)
	{

	}


	void BtPhysicsEngine::loadPhysicsCommands(const std::vector<Core::ECS::PhysicsEngineCommand>& commandList)
	{
		commandQueue = &commandList;
	}

	void BtPhysicsEngine::runSimulation()
	{
		for (const auto& command : *commandQueue)
		{
			Core::ECS::PhysicsEvent newEvent;

			//For testing...
#ifdef PIPELINE_TESTING_MODE

			auto entityId = command.entityId;
			auto entityPosition = command.position;
			auto entityRotation = command.rotation;

			if (entityPosition.x < 0)
			{
				std::cout << "x is negative\n";
			}
#else
			throw std::logic_error("The true code has not been implemented!");
#endif
		}

	}

	std::vector<Core::ECS::PhysicsEvent> Engine::Infra::BtPhysicsEngine::pollEvents()
	{
		return std::vector<Core::ECS::PhysicsEvent>();
	}



}
