#pragma once
#include "../coordinator/ECS.h"
#include <glm/ext/vector_float3.hpp>
#include <glm/ext/quaternion_float.hpp>

namespace Engine::Core::ECS
{
	enum class PhysicsEngineCommandType
	{
		CreateRigidbody,
		DeleteRigidbody,
		UpdateTransform,

	};

	struct PhysicsEngineCommand
	{
		Entity entityId;

		glm::vec3 position;
		glm::quat rotation;
	};

	enum class PhysicsEventType
	{
		TransformUpdate,
		CollisionStarted,
		CollisionEnded,
		TriggerEntered
	};

	struct PhysicsEvent
	{
		PhysicsEventType eventType = PhysicsEventType::TransformUpdate;
		Entity entityA = 0;
		Entity entityB = 0;

		glm::vec3 position = {0,0,0};
		glm::quat rotation = {1, 0,0,0};
		glm::vec3 contactPoint = {0,0,0};
	};
}