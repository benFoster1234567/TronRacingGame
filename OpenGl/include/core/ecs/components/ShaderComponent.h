#pragma once

#include "core/assets/ShaderData.h"
#include "../coordinator/ECS.h"
#include "../../assets/AssetIds.h"

namespace Engine::Core::ECS
{
	struct ShaderComponent : public ComponentBase
	{
		ShaderComponent() = default;
		ShaderComponent(Engine::Core::ShaderId id) : shaderId(id) {}
		Engine::Core::ShaderId shaderId{};
	};
}