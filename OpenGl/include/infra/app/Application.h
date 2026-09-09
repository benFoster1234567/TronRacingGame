#pragma once
#include "core/assets/AssetManager.h"
#include "infra/renderer/Renderer.h"
#include "infra/app/Window.h"
#include "core/assets/AssetPipeline.h"
#include "infra/app/GlfwKeyHandler.h"
#include "core/engine/Engine.h"
#include "infra/engine/DebugConsoleUI.h"
#include "../bullet/BtPhysicsEngine.h"

namespace Engine::Infra
{

	class Application
	{
	private:
		Infra::Renderer renderer;
		Infra::GlfwKeyHandler keyHandler;
		std::unique_ptr<DebugConsoleUi> debugConsoleUi;
		std::unique_ptr<Window> window;

		BtPhysicsEngine btPhysicsEngine{};

	public:
		Application();
		~Application() = default;
		
		Engine::Core::EngineSystem engine;
		
		void setupDebugCommands();
		void setupWindowCallbacks();
		void setupImportCallbacks();
		
		void importAssets();
		void sendTexturesToRenderer();
		void run();

	};

}