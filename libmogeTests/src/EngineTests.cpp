#include "EngineTests.h"
#include "MogeLibMain.h"

Moge::Engine* EngineTests::engine = nullptr;

EngineTests::EngineTests( void )
{
    engine = Moge::EngineManager::initializeEngine();
}

EngineTests::~EngineTests()
{
    Moge::EngineManager::destroyEngine();
}

void EngineTests::SetUpTestCase()
{
    
}

void EngineTests::TearDownTestCase()
{
    
}
