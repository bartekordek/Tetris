#include "EngineConcrete.hpp"

#include "IEngine.h"
#include "IKeyboardObserver.h"
#include "SDL2Wrapper/ISDL2Wrapper.hpp"
#include <iostream>
#include <memory>
#include "CUL/ITimer.hpp"

using namespace Moge;

EngineConcrete::EngineConcrete( void )
{
    this->sdlAdapter = new SDL2WrapperAdapter();
    this->renderer2D.reset( this->sdlAdapter );
    this->m_mainGameLoop = static_cast<IMainGameLoop*>( this->sdlAdapter );


    this->m_keyboardObservable = static_cast<IKeyboardObservable*>( this->sdlAdapter );
    //this->renderer3D.reset(  ); TODO: Add when OpenGL is ready.
    //this->nodeFactory.reset( new NodeFactory2D( this->sdlAdapter ) );
    
    this->fpsCounter.reset( FPSCounterFactory::getConcreteFPSCounter() );
    this->infoLoopThread = std::thread( &EngineConcrete::infoLoop, this );
    this->timer.reset( CUL::TimerFactory::getChronoTimer() );
}

EngineConcrete::~EngineConcrete()
{
    std::lock_guard<std::mutex> lck( mListMutex );
    this->renderer2D.reset();
    this->infoLoopThread.join();
}

IWindow* EngineConcrete::createWindow(
    const CUL::Math::Vector3Du& size,
    const CUL::Math::Vector3Di& position,
    const std::string& label)const
{
    IWindow* window = this->renderer2D->createWindow(
        size,
        position,
        label );
    return window;
}

void EngineConcrete::startMainLoop()
{
    m_mainLoop = std::thread( &EngineConcrete::renderingLoop2D, this );
    this->sdlAdapter->runMainLoop();
    mainLoop();
}

void EngineConcrete::stopEventLoop()
{
    this->mainLoopIsRuning = false;
    std::cout << "Waiting for main loop to stop...\n";
    this->m_mainLoop.join();
    std::cout << "Waiting for game loop to stop...\n";
    this->m_mainGameLoop->stopMainLoop();
}

void EngineConcrete::mainLoop()
{
    this->m_mainGameLoop->runMainLoop();
}

void EngineConcrete::renderingLoop2D()
{
    while( this->mainLoopIsRuning )
    {
        this->renderer2D->clear();
        QueueFrame();
    }
    std::cout << "Renderering loop ended.\n";
}

void EngineConcrete::QueueFrame()
{
    this->timer->reset();

    this->renderer2D->renderAllWindows();
    
    this->fpsCounter->increase();

    if( -1 != this->m_fpsCount )
    {
        auto uS = static_cast<unsigned>( this->m_frameData.getSleepTimeUs() );
        this->timer->sleepMicroSeconds( uS );
    }
   // auto lastFrameTimeUs = this->timer->getElapsed().getUs();
    //this->m_frameData.setLastFrimeTimeUs( lastFrameTimeUs );
    this->m_frameData.setLastFpsCount( this->fpsCounter->getCurrentFps() );
}

void EngineConcrete::infoLoop()
{
    while( this->mainLoopIsRuning )
    {
        double averageFpsCount = static_cast<double>(
            this->fpsCounter->getAverageFps() );
        std::cout << "FPS AVG: " << averageFpsCount << "\n";
        this->timer->sleepMiliSeconds( this->infoLoopPrintDelayMs );
    }
}

void EngineConcrete::registerKeyboardObserver( IKeyboardObserver* observer )
{
    this->m_keyboardObservable->registerKeyboardObserver( observer );
}

void EngineConcrete::unregisterKeyboardObserver( IKeyboardObserver* observer )
{
    this->m_keyboardObservable->unregisterKeyboardObserver( observer );
}

void EngineConcrete::lockFps( unsigned fpsCount )
{
    this->m_fpsCount = static_cast<int>( fpsCount );
    this->targetFrameTimeMs = 1000.0 / fpsCount;
}

void EngineConcrete::unlockFps()
{
    this->m_fpsCount = -1;
}

const bool EngineConcrete::isKeyDown( const IKey* key )const
{
    return this->m_keys.at( key->getKeyName() )->getKeyIsDown();
}