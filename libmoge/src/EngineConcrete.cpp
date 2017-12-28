#include "EngineConcrete.hpp"

#include "IEngine.h"
#include "IKeyboardObserver.h"
#include "SDLRenderer.hpp"
#include "NodeFactory2D.h"
#include "ITextureFactory3D.h"

#include <iostream>
#include <memory>
#include "ITimer.h"

using namespace Moge;

EngineConcrete::EngineConcrete( void ):
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
    this->infoLoopThread = std::thread( &EngineConcrete::infoLoop, this );
    this->timer.reset( TimerFactory::getChronoTimer() );
}

EngineConcrete::~EngineConcrete()
{
    std::lock_guard<std::mutex> lck( mListMutex );
    this->nodeFactory.reset();
    this->renderer2D.reset();
    this->infoLoopThread.join();
}
void EngineConcrete::createScreen(
    Math::ISize<unsigned int>& size,
    Math::IPosition<int>& position,
    const std::string& label )const
{
    this->renderer2D->createWindow( position, size, label );
}

void EngineConcrete::startMainLoop()
{
    m_mainLoop = std::thread( &EngineConcrete::renderingLoop2D, this );
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

ITextureFactory* EngineConcrete::get2DTextureFactory() const
{
    auto ptr = static_cast<SDLRenderer*>( this->renderer2D.get() );
    return ptr;
}

ITextureFactory* EngineConcrete::get3DTextureFactory() const
{
    return this->textureFactory3D.get();
}

INodeFactory* EngineConcrete::get2DNodeFactory() const
{
    return this->nodeFactory.get();
}

INodeFactory* EngineConcrete::get3DNodeFactory() const
{
    return nullptr;//TODO
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
        if( this->lastFrameTimeMs > targetFrameTimeMs )
        {
            this->frameSleepMs -= 0.1;
        }
        else if( this->lastFrameTimeMs < targetFrameTimeMs )
        {
            this->frameSleepMs += 0.1;
        }
        // std::cout << "SleepTime: " << this->frameSleepMs << "\n";
    }
    auto uS = static_cast<unsigned>( this->frameSleepMs * 1000 );
    this->timer->sleepMicroSeconds( uS );
    this->lastFrameTimeMs = this->timer->getElapsed().getMs();
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

void EngineConcrete::registerObserver( IKeyboardObserver* observer )
{
    this->m_keyboardObservable->registerObserver( observer );
}

void EngineConcrete::unregisterObserver( IKeyboardObserver* observer )
{
    this->m_keyboardObservable->unregisterObserver( observer );
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
