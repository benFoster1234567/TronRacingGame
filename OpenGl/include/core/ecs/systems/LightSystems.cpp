#include "LightSystems.h"

#include "../coordinator/Coordinator.h"
#include "../components/PointlightComponents.h"
#include "../components/TransformComponent.h"

namespace Engine::Core::ECS
{
	void StaticLightRenderSetupSystem::fill(Coordinator& coordinator, std::vector<StaticPointLightRendererData>& queue)
	{
		for (auto entity : entities)
		{
			const auto& light = coordinator.getComponent<StaticPointLightComponent>(entity);
			const auto& transform = coordinator.getComponent<TransformComponent>(entity);

			StaticPointLightRendererData rd{};
			rd.color = light.color;
			rd.position = transform.position;
			rd.radius = light.radius;
			rd.intensity = light.intensity;

			queue.push_back(rd);
		}
	} 

	std::vector<StaticPointLightRendererData> ShadowPointSystem::getShadowCastingPointlights(Coordinator& coordinator)
	{
		std::vector<StaticPointLightRendererData> lights{};

		for (Entity entity : entities)
		{
			auto& shadowProps = coordinator.getComponent<ShadowCastComponent>(entity);
			const auto& light = coordinator.getComponent<StaticPointLightComponent>(entity);
			const auto& transform = coordinator.getComponent<TransformComponent>(entity);

			StaticPointLightRendererData rd{};
			rd.color = light.color;
			rd.position = transform.position;
			rd.radius = light.radius;
			rd.intensity = light.intensity;
			
			lights.push_back(rd);
		}

		return lights;
	} 
}