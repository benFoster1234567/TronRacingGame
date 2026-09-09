#pragma once
#include "../../SparseSet.h"

#include <stdexcept>
#include <bullet/btBulletDynamicsCommon.h>
#include <bullet/btBulletCollisionCommon.h>

#include "../../core/ecs/systems/PhysicsCommandsAndEvents.h"

//TODO: Implement Bullet3 into infrastructure -- detect collisions, rigidbody physics, vehicle physics

namespace Engine::Infra
{
	class BtPhysicsEngine
	{
	private:

		btDefaultCollisionConfiguration* collisionConfiguration{};
		btCollisionDispatcher* dispatcher{};
		btDbvtBroadphase* broadPhase{};
		btSequentialImpulseConstraintSolver* solver{};
		btDiscreteDynamicsWorld* dynamicsWorld{};

		SparseSet<btCollisionShape*> entityCollisionShapes{};

		const std::vector<Core::ECS::PhysicsEngineCommand>* commandQueue{nullptr};
		std::vector<Core::ECS::PhysicsEvent> eventCache{};

		Core::ECS::PhysicsEvent processCommand(const Core::ECS::PhysicsEngineCommand& command);

	public:

		BtPhysicsEngine() = default;
		~BtPhysicsEngine()
		{

		}


		BtPhysicsEngine(const BtPhysicsEngine&) = delete;
		BtPhysicsEngine& operator=(const BtPhysicsEngine&) = delete;
		BtPhysicsEngine(BtPhysicsEngine&& other) noexcept
		{

		}
		
		void createBoudingBox(Core::ECS::Entity, glm::vec3 dim);
		
		

		void loadPhysicsCommands(const std::vector<Core::ECS::PhysicsEngineCommand>& commandList);

		void runSimulation(); //evaluates the commands and creates appropriate events in reponse

		std::vector<Core::ECS::PhysicsEvent> pollEvents();

	};
}