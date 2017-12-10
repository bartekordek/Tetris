#include "Engine.h"
#include "IKeyboardObserver.h"
#include "SDLRenderer.hpp"
#include "NodeFactory2D.h"
#include "ITextureFactory3D.h"

#include <iostream>
#include <memory>
#include "ITimer.h"

using namespace Moge;

Engine::Engine( void ):
    mainLoopIsRuning( true ),
    frameSleepTimeMs( 0 )
{
    auto sdlRenderer = new SDLRenderer();
    this->renderer2D.reset( sdlRenderer );
    this->m_mainGameLoop = static_cast<IMainGameLoop*>( sdlRenderer );

    this->m_keyboardObservable = static_cast<IKeyboardObservable*>( sdlRenderer );
    //this->renderer3D.reset(  ); TODO: Add when OpenGL is ready.
    this->nodeFactory.reset( new NodeFactory2D( sdlRenderer ) );
    this->fpsCounter.reset( FPSCounterFactory::getConcreteFPSCounter() );
    this->fpsCounter->setAverageFpsSampleMs( infoLoopPrintDelayMs / 2 );
    this->infoLoopThread = std::thread( &Engine::infoLoop, this );
    this->timer.reset( TimerFactory::getChronoTimer() );
}

Engine::~Engine()
{
    std::lock_guard<std::mutex> lck( mListMutex );
    this->nodeFactory.reset();
    this->renderer2D.reset();
    this->infoLoopThread.join();
}

void Engine::createScreen( 
    Math::ISize<unsigned int>& size, 
    Math::IPosition<int>& position, 
    const std::string& label )const
{
    this->renderer2D->createWindow( position, size, label );
}
    
void Engine::startMainLoop()
{
    m_mainLoop = std::thread( &Engine::renderingLoop2D, this );
    mainLoop();
}

void Engine::stopEventLoop()
{
    this->mainLoopIsRuning = false;
    std::cout << "Waiting for main loop to stop...\n";
    this->m_mainLoop.join();
    std::cout << "Waiting for game loop to stop...\n";
    this->m_mainGameLoop->stopMainLoop();
}
    
ITextureFactory* Engine::get2DTextureFactory() const
{
    auto ptr = static_cast<SDLRenderer*>( this->renderer2D.get() );
    return ptr;
}
    
ITextureFactory* Engine::get3DTextureFactory() const
{
    return this->textureFactory3D.get();
}

INodeFactory* Engine::get2DNodeFactory() const
{
    return this->nodeFactory.get();
}

INodeFactory* Engine::get3DNodeFactory() const
{
    return nullptr;//TODO
}

void Engine::mainLoop()
{
    this->m_mainGameLoop->runMainLoop();
}

void Engine::renderingLoop2D()
{
    while( this->mainLoopIsRuning )
    {
        this->renderer2D->clear();
        QueueFrame();
    }
    std::cout << "Renderering loop ended.\n";
}

void Engine::QueueFrame()
{
    this->timer->reset();
    std::lock_guard<std::mutex> renderableObjectLock( this->mRenderableObjectsMutex );
    auto& nodeIt = this->get2DNodeFactory()->getNodes();
    if( false == nodeIt.isEmpty() )
    {
        while( nodeIt.hasNext() )
        {
            auto& node = *nodeIt.next().get();
            if( node.GetVisible() )
            {
                this->renderer2D->render( node );
            }
        }
    }
    this->renderer2D->updateScreen();
    this->fpsCounter->increase();

    if( -1 != this->m_fpsCount )
    {
      //  std::cout << "Last frame time: " << this->lastFrameTimeMs << "\n";
        if( this->lastFrameTimeMs > targetFrameTime )
        {
            this->frameSleepMs -= 0.1;
        }
        else if( this->lastFrameTimeMs < targetFrameTime )
        {
            this->frameSleepMs += 0.1;
        }
       // std::cout << "SleepTime: " << this->frameSleepMs << "\n";
    }
    auto uS = static_cast<unsigned>( this->frameSleepMs * 1000 );
    this->timer->sleepMicroSeconds( uS );
    this->lastFrameTimeMs = this->timer->getElapsed().getMs();
}

void Engine::infoLoop()
{
    while( this->mainLoopIsRuning )
    {
        double averageFpsCount = static_cast<double>( this->fpsCounter->getAverageFps() );
        std::cout << "FPS AVG: " << averageFpsCount << "\n";
        /* 
        if (averageFpsCount > fpsConst + framesDelta)
        {
            ++this->frameSleepTimeMs;
            std::cout << "Render sleep time increase: " << this->frameSleepTimeMs << "\n";
        }
        else if (averageFpsCount < fpsConst - framesDelta)
        {
            if (this->frameSleepTimeMs > 0)
            {
                --this->frameSleepTimeMs;
                std::cout << "Render sleep time decrease: " << this->frameSleepTimeMs << "\n";
            }
        }
        else
        {
            std::cout << "Render sleep time is const.\n";
        }
        */
        this->timer->sleepMiliSeconds( this->infoLoopPrintDelayMs );
    }
}

void Engine::registerObserver( IKeyboardObserver* observer )
{
    this->m_keyboardObservable->registerObserver( observer );
}

void Engine::unregisterObserver( IKeyboardObserver* observer )
{
    this->m_keyboardObservable->unregisterObserver( observer );
}

void Engine::lockFps( unsigned fpsCount )
{
    this->m_fpsCount = static_cast<int>( fpsCount );
    this->targetFrameTime = 1000.0 / fpsCount;
}

void Engine::unlockFps()
{
    this->m_fpsCount = -1;
}