#include "IMogeApp.h"

#include "MogeLibMain.h"

namespace Moge
{
	IMogeApp::IMogeApp( void )
	{
		this->engine = EngineManager::initializeEngine();
	}

	IMogeApp::~IMogeApp()
	{
		EngineManager::destroyEngine();
	}

	Engine* IMogeApp::getEngine()
	{
		return this->engine;
	}

	void IMogeApp::startApp()
	{
		initialize();
	}

	void IMogeApp::initialize()
	{
		this->engine->initialize();
	}
}