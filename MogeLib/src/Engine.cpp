#include "Engine.h"
#include "IKeyboardObserver.h"
#include "SDLRenderer.hpp"
#include "NodeFactory2D.h"
#include "ITextureFactory3D.h"

#include <iostream>
#include <memory>
#include "ITimer.h"

namespace Moge
{
	Engine::Engine( void ):
		mainLoopIsRuning( true ),
		frameSleepTimeMs( 0 ),
		fpsCalcSampleTimeSpan( 6 )
	{
		auto sdlRenderer = new SDLRenderer();
		this->renderer2D.reset( sdlRenderer );
		this->m_mainGameLoop = static_cast<IMainGameLoop*>( sdlRenderer );
		this->m_keyboardObservable = static_cast<IKeyboardObservable*>( sdlRenderer );
		//this->renderer3D.reset( TODO: Add when OpenGL is ready. );
		auto txtFactory2D = static_cast<SDLRenderer*>( this->renderer2D.get() );
		this->nodeFactory.reset( new NodeFactory2D( txtFactory2D ) );
		this->renderer2D->setBackgroundColor( ColorE::RED );
		this->fpsCounter.reset( FPSCounterFactory::getConcreteFPSCounter() );
		this->fpsCounter->setAverageFpsSample( 4 );
		this->infoLoopThread = std::thread( &Engine::infoLoop, this );
	}

	Engine::~Engine()
	{
		std::lock_guard<std::mutex> lck( mListMutex );
		this->renderer2D.reset();
		this->nodeFactory.reset();
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
		this->m_mainLoop.join();
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
	}

	void Engine::QueueFrame()
	{
		
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
		ITimer::SleepMiliSeconds( this->frameSleepTimeMs );
	}

	void Engine::infoLoop()
	{
		while( this->mainLoopIsRuning )
		{
			int averageFpsCount4 = static_cast<int>( this->fpsCounter->getAverageFps() );
			std::cout << "FPS AVG: " << averageFpsCount4 << "\n";
			if( averageFpsCount4 > fpsConst + framesDelta )
			{
				++this->frameSleepTimeMs;
				std::cout << "Render sleep time increase: " << this->frameSleepTimeMs << "\n";
				
			}
			else if( averageFpsCount4 < fpsConst - framesDelta )
			{
				if( this->frameSleepTimeMs > 0 )
				{
					--this->frameSleepTimeMs;
					std::cout << "Render sleep time decrease: " << this->frameSleepTimeMs << "\n";
				}
			}
			else
			{
				std::cout << "Render sleep time is const.\n";
			}
			ITimer::SleepSeconds( this->fpsCalcSampleTimeSpan );
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
}