#pragma once
#include "core/assets/AssetManager.h"
#include "Renderer.h"


namespace Engine::Infra
{
	class GpuAssetLoader
	{
	public:
		static void fillRenderer(Core::AssetManager& am, Renderer& renderer)
		{
			for (auto textureData : am.textureList())
			{
				std::string textureName = textureData->name;
				Core::TextureId id = am.getTextureId(textureName);

				renderer.cacheTexture(id, textureData);
				renderer.gpuTextureCache.get(id).get()->genTexture();
			}

			int c = 0;
			for (auto meshData : am.meshList())
			{
				c++;
				meshData->recomputeNormalsAndTangents();
				std::cout << c << " meshes loaded!\n";
				std::string meshName = meshData->name;
				Core::MeshId id = am.getMeshId(meshName);

				renderer.cacheMesh(id, meshData);
				renderer.gpuMeshCache.get(id)->genBuffers();
			}
			
			renderer.screenQuad.create();
			
			for (auto shaderData : am.shaderList())
			{
				std::string shaderName = shaderData->name;
				Core::ShaderId id = am.getShaderId(shaderName);

				renderer.cacheShader(id, shaderData);
				renderer.gpuShaderCache.get(id).get()->compileShaders();

				if (shaderName == "depthCubemap")
				{
					renderer.shadowCubemapShader = renderer.gpuShaderCache.get(id).get();
					std::cout << "depth cube map found!\n";
				}
			}
		}
	};


}