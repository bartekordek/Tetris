#include "IMogeApp.h"

#include "MogeLibMain.h"

namespace Moge
{
	IMogeApp::IMogeApp( void )
	{
		this->engine = EngineManager::initializeEngine();
		initialize();
	}

	IMogeApp::~IMogeApp()
	{
		clean();
		EngineManager::destroyEngine();
	}

	const Engine* IMogeApp::getEngine()const
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

	void IMogeApp::initialize()
	{
	}

	void IMogeApp::clean()
	{
	}
}