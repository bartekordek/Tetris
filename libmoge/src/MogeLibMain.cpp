#include "MogeLibMain.h"
#include "EngineConcrete.hpp"

namespace Moge
{
    IEngine* EngineManager::engineInstance = nullptr;

    IEngine* EngineManager::initializeEngine()
    {
        engineInstance = new EngineConcrete();
        return engineInstance;
    }

    IEngine* EngineManager::getEngine()
    {
        return engineInstance;
    }

    void EngineManager::destroyEngine()
    {
        delete engineInstance;
        engineInstance = nullptr;
    }

}