#include "Engine.h"
#include "RendererSDL.h"
#include "NodeFactory2D.h"
#include "ITextureFactory3D.h"
#include "KeyboardObservableSDL.h"

#include <memory>
#include "ITimer.h"

namespace Moge
{
	Engine::Engine( void ):
		mainLoopIsRuning( true ),
		eventLoopActive( true ),
		frameSleepTimeMs( 0 ),
		fpsCalcSampleTimeSpan( 6 )
	{
		this->logUtil.reset( LogFactory::getConcrete() );
		this->logUtil->showMessage( "Log utility initialized" );
		this->logUtil->showMessage( "Creating renderer 2D..." );
		this->renderer2D.reset( new SDLRenderer() );
		this->logUtil->showMessage( "Creating renderer 2D...Done" );
		//this->renderer3D.reset( TODO: Add when OpenGL is ready. );
		auto txtFactory2D = static_cast<SDLRenderer*>( this->renderer2D.get() );
		this->nodeFactory.reset( new NodeFactory2D( txtFactory2D ) );
		this->renderer2D->setBackgroundColor( ColorE::RED );
		this->fpsCounter.reset( FPSCounterFactory::getConcreteFPSCounter() );
		this->fpsCounter->setAverageFpsSample( 4 );
		this->logUtil->showMessage( "Creating info loop thread...Done" );
		this->infoLoopThread = std::thread( &Engine::infoLoop, this );
		this->logUtil->showMessage( "Creating info loop thread...Done" );
		this->keyboardObservable.reset( new KeyboardObservableSDL() );
		this->keyboardEventObservable = dynamic_cast<IEventLoop*>( keyboardObservable.get() );
	}

	Engine::~Engine()
	{
		this->logUtil->showMessage( "Stoping loops..." );
		this->mainLoopIsRuning = false;
		std::lock_guard<std::mutex> lck( mListMutex );
		this->renderer2D.reset();
		this->nodeFactory.reset();
		this->infoLoopThread.join();
		this->logUtil->showMessage( "Stoping loops... Done." );
	}

	void Engine::createScreen( 
		Math::ISize<unsigned int>& size, 
		Math::IPosition<int>& position, 
		const std::string& label )const
	{
		this->renderer2D->createWindow( position, size, label );
	}
	
	void Engine::start()
	{
		mainLoop = std::thread( &Engine::renderingLoop2D, this );
		eventPool();
	}

	void Engine::close()
	{
		this->keyboardEventObservable->stopEventLoop();
		this->logUtil->showMessage( "Turning of main loop..." );
		this->mainLoopIsRuning = false;
		this->mainLoop.join();
		this->logUtil->showMessage( "Turning of main loop... Done." );
		this->eventLoopActive = false;
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

	IKeyboardObservable* Engine::getKeyboardObservable() const
	{
		return this->keyboardObservable.get();
	}

	void Engine::eventPool()
	{
		this->keyboardEventObservable->runEventLoop();
		this->logUtil->showMessage( "Quiting event loop... Done." );
	}

	void Engine::renderingLoop2D()
	{
		while( this->mainLoopIsRuning )
		{
			this->renderer2D->clear();
			QueueFrame();
		}
		this->logUtil->showMessage( "Quiting 2D render loop... Done." );
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
			std::string info = "FPS AVG: " + std::to_string( averageFpsCount4 );
			this->logUtil->showMessage( info.c_str() );
			if( averageFpsCount4 > fpsConst + framesDelta )
			{
				++this->frameSleepTimeMs;
				info = "Render sleep time increase: " + std::to_string( this->frameSleepTimeMs );
				
			}
			else if( averageFpsCount4 < fpsConst - framesDelta )
			{
				if( this->frameSleepTimeMs > 0 )
				{
					--this->frameSleepTimeMs;
					info = "Render sleep time decrease: " + std::to_string( this->frameSleepTimeMs );
				}
			}
			else
			{
				info = "Render sleep time is const.";
			}
			this->logUtil->showMessage( info.c_str() );
			ITimer::SleepSeconds( this->fpsCalcSampleTimeSpan );
		}
		this->logUtil->showMessage( "Quiting info loop... Done." );
	}
}