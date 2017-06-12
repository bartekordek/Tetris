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

	void IMogeApp::run()
	{
		this->frontEndLoopThread = std::thread( &IMogeApp::frontEndLoopWrapper, this );
		this->engine->start();
		this->frontEndLoopThread.join();
	}

	void IMogeApp::frontEndLoopWrapper()
	{
		frontEndLoop();
		this->engine->close();
	}

	void IMogeApp::stopApp()
	{
		
	}

	void IMogeApp::initialize()
	{
		
	}
}