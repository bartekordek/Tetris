#include "MogeLibMain.h"
#include "Engine.h"

namespace Moge
{
	Engine* EngineManager::engineInstance = nullptr;

	Engine* EngineManager::initializeEngine()
	{
		engineInstance = Engine::instancePtr();
		return engineInstance;
	}

	Engine* EngineManager::getEngine()
	{
		return engineInstance;
	}

	void EngineManager::destroyEngine()
	{
		Engine::destroy();
	}

}