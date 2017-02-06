#include "Engine.h"
#include "NodeCreator.h"
#include "IPositionAdapter.h"
#include "KeyboardObservable.h"
#include "IKeyboardObserver.h"
#include <SDL.h>

namespace Moge
{
	Engine::Engine( void )
	{
		SDL_Init( SDL_INIT_EVERYTHING );
		keyboardObservable.reset( new KeyboardObservable() );
	}

	Engine::~Engine()
	{
		std::lock_guard<std::mutex> lck( mListMutex );
		mRenderableObjects.erase( mRenderableObjects.begin(), mRenderableObjects.end() );
		SDL_Quit();
	}

	void Engine::createScreen( const Math::MultiPoint<unsigned int>& resolution )
	{
		std::lock_guard<std::mutex> lck( mListMutex );
		mScreenBuffor = NodeCreator::CreateScreen( resolution );
		mScreenBuffor->initialize();
	}

	void Engine::AddObject( const Path& filePath, const Math::MultiPoint<int>& position, const MyString& name )
	{
		Math::IPositionAdapter<int> positionAdapter( position );
		ObjectNode newNode = NodeCreator::CreateFromImage( filePath, positionAdapter, name );
		AddObject( newNode, name );
	}

	void Engine::AddObject( const ObjectNode  node, const MyString& name )
	{
		std::lock_guard<std::mutex> renderableObjectLock( mRenderableObjectsMutex );
		mRenderableObjects.insert( node );
	}

	const std::shared_ptr< ScreenNode > Engine::getScreen()const
	{
		return this->mScreenBuffor;
	}

	void Engine::initialize()
	{
		mainLoop = std::thread( &Engine::MainLoop, this );
		eventPool();
	}

	void Engine::stop()
	{
		this->mainLoopIsRuning = false;
		this->mainLoop.join();
		this->eventLoopActive = false;
	}

	void Engine::registerKeyboardListener( IKeyboardObserver* observer )
	{
		keyboardObservable->registerObserver( observer );
	}

	void Engine::eventPool()
	{
		SDL_Event event;
		while( this->eventLoopActive )
		{
			SDL_PollEvent( &event );
		}
	}

	void Engine::MainLoop()
	{
		while( this->mainLoopIsRuning )
		{
			QueueFrame();
		}
	}

	void Engine::QueueFrame()
	{
		std::lock_guard<std::mutex> renderableObjectLock( this->mRenderableObjectsMutex );
		for( auto& object : mRenderableObjects )
		{
			Render( *object );
		}
		SDL_UpdateWindowSurface( mScreenBuffor->GetScreen() );
		++mFrameCount;
	}

	void Engine::Render( ObjectNodeContent& node )
	{
		if( node.GetVisible() )
		{
			std::lock_guard<std::mutex> lck( mListMutex );
			SDL_Rect* screenRect = node.GetGeometricsInfo();
			SDL_Rect* imageRect = nullptr;
			SDL_BlitSurface( node.GetSurface()->GetSdlSurface(), imageRect, mScreenBuffor->GetSdlSurface(), screenRect );
		}
	}
}