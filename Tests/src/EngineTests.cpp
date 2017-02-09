#include "EngineTests.h"
#include "MogeLibMain.h"

Moge::Engine* EngineTests::engine = nullptr;

void EngineTests::SetUpTestCase()
{
    engine = Moge::EngineManager::initializeEngine();
}

void EngineTests::TearDownTestCase()
{
    Moge::EngineManager::destroyEngine();
}
