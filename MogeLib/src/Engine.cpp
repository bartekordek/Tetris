#include "Engine.h"
#include "NodeFactoryRegular.h"
#include "IPositionAdapter.h"
#include "KeyboardObservable.h"
#include "IKeyboardObserver.h"
#include "KeyFactorySDL.h"
#include <SDL.h>

namespace Moge
{
	Engine::Engine( void )
	{
		SDL_Init( SDL_INIT_EVERYTHING );
        this->sdlKey = SDL_GetKeyboardState( nullptr );
        this->keyFactory.reset( new KeyFactorySDL() );
        this->keys = this->keyFactory->createKeys();
        this->nodeFactory.reset( new NodeFactoryRegular() );
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
		mScreenBuffor = nodeFactory->CreateScreen( resolution );
		mScreenBuffor->initialize();
	}

	void Engine::AddObject( const Path& filePath, const Math::MultiPoint<int>& position, const MyString& name )
	{
		Math::IPositionAdapter<int> positionAdapter( position );
		ObjectNode newNode = nodeFactory->CreateFromImage( filePath, positionAdapter, name );
		AddObject( newNode, name );
	}

	void Engine::AddObject( const ObjectNode  node, const MyString& name )
	{
		std::lock_guard<std::mutex> renderableObjectLock( mRenderableObjectsMutex );
		mRenderableObjects.insert( node );
	}

	const std::shared_ptr<ScreenNode> Engine::getScreen()const
	{
		return this->mScreenBuffor;
	}

    INodeFactory* Engine::getNodeFactory()
    {
        return this->nodeFactory.get();
    }

	void Engine::startMainLoop()
	{
		mainLoop = std::thread( &Engine::renderingLoop, this );
		eventPool();
	}

	void Engine::stopEventLoop()
	{
		this->mainLoopIsRuning = false;
		this->mainLoop.join();
		this->eventLoopActive = false;
	}

	void Engine::eventPool()
	{
		SDL_Event event;
		while( true == this->eventLoopActive )
		{
            if( ( SDL_PollEvent( &event ) > 0) && 
                ( event.type == SDL_KEYDOWN || event.type == SDL_KEYUP ) )
            {
                 auto scancode = SDL_GetScancodeFromKey( event.key.keysym.sym );
                if( SDL_SCANCODE_UNKNOWN != scancode )
                {
                    const bool keyIsDown = ( SDL_KEYDOWN == event.type ) ? true : false;
                    const auto keyIndex = static_cast<unsigned int>( scancode );
                    auto key = this->keys.at( keyIndex );
                    key->setKeyIsDown( keyIsDown );
                    this->notifyKeyboardObservers( key.get() );
                }
            }
		}
	}

	void Engine::renderingLoop()
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