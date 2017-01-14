#include "MogeLibMain.h"
#include "Engine.h"

namespace Moge
{
	IEngine* EngineManager::initializeEngine()
	{
		auto engine = new Engine();
		engineInstance = std::make_shared<Engine>( *engine );
		return engineInstance.get();
	}

	IEngine* EngineManager::getEngine()
	{
		return engineInstance.get();
	}
}