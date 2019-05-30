#pragma once

#include "IEngine.h"

namespace Moge
{
    class MogeLib_API EngineManager
    {
    public:
        static IEngine* initializeEngine();
        static IEngine* getEngine();
        static void destroyEngine();
    protected:
    private:
        static IEngine* engineInstance;
    };
    
}