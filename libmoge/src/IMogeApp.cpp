#include "IMogeApp.h"

#include "MogeLibMain.h"

#include <iostream>

namespace Moge
{
    IMogeApp::IMogeApp( void ):
        engine( EngineManager::initializeEngine() )
    {
        const CUL::Math::Vector3Du screenSize( 800, 600, 0 );
        const CUL::Math::Vector3Di screenPos( 100, 100, 0 );
        this->engine->createWindow( screenSize, screenPos );
    }

    IMogeApp::~IMogeApp()
    {
        EngineManager::destroyEngine();
    }

    IEngine* IMogeApp::getEngine()
    {
        return this->engine;
    }

    void IMogeApp::run()
    {
        this->frontEndLoopThread = std::thread( &IMogeApp::frontEndLoopWrapper, this );
        this->engine->startMainLoop();
        this->frontEndLoopThread.join();
    }

    void IMogeApp::frontEndLoopWrapper()
    {
        frontEndLoop();
        std::cout << "Stoping event loop...\n";
        this->engine->stopEventLoop();
        std::cout << "Stoping event loop... Done\n";
    }

    void IMogeApp::stopApp()
    {
        
    }

    void IMogeApp::initialize()
    {
        
    }
}