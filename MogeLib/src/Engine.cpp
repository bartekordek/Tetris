#include "Engine.h"
#include "Math/IPositionAdapter.h"
#include "KeyboardObservable.h"
#include "IKeyboardObserver.h"
#include "KeyFactorySDL.h"
#include "SDLRenderer.h"
#include "NodeFactory2D.h"
#include "ITextureFactory3D.h"
#include "ListFactory.h"

#include <SDL.h>

#include <memory>

namespace Moge
{
	Engine::Engine( void )
	{
		this->renderer2D.reset( new SDLRenderer() );
		//this->renderer3D.reset( TODO: Add when OpenGL is ready. );
		this->sdlKey = SDL_GetKeyboardState( nullptr );
		this->keyFactory.reset( new KeyFactorySDL() );
		this->keys = this->keyFactory->createKeys();
		auto txtFactory2D = static_cast<SDLRenderer*>( this->renderer2D.get() );
		this->nodeFactory.reset( new NodeFactory2D( txtFactory2D ) );
		this->renderer2D->setBackgroundColor( ColorE::RED );
		this->someList.reset( ListFactory<double>::createLinkedListPtr() );
		this->someList->pushBack( 4 );
	}

	Engine::~Engine()
	{
		std::lock_guard<std::mutex> lck( mListMutex );
		this->renderer2D.reset();
		this->nodeFactory.reset();
		//auto rndrPtr = this->renderer2D.release();
		//delete rndrPtr;
		SDL_Quit();
	}

	IRenderer* Engine::getRenderer()
	{
		return nullptr;
	}

	void Engine::createScreen( 
		Math::ISize<unsigned int>& size, 
		Math::IPosition<int>& position, 
		const std::string& label )
	{
		this->renderer2D->createWindow( position, size, label );
	}
	
	void Engine::startMainLoop()
	{
		mainLoop = std::thread( &Engine::renderingLoop2D, this );
		eventPool();
	}

	void Engine::stopEventLoop()
	{
		this->mainLoopIsRuning = false;
		this->mainLoop.join();
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

	void Engine::eventPool()
	{
		SDL_Event event;
		while( true == this->eventLoopActive )
		{
			if (SDL_PollEvent(&event) > 0)
			{
				if((event.type == SDL_KEYDOWN || event.type == SDL_KEYUP))
				{
					auto scancode = SDL_GetScancodeFromKey(event.key.keysym.sym);
					if (SDL_SCANCODE_UNKNOWN != scancode)
					{
						const bool keyIsDown = (SDL_KEYDOWN == event.type) ? true : false;
						const auto keyIndex = static_cast<unsigned int>(scancode);
						auto key = this->keys.at(keyIndex);
						key->setKeyIsDown(keyIsDown);
						this->notifyKeyboardObservers(key.get());
					}
				}
			}

		}
	}

	void Engine::renderingLoop2D()
	{
		while( this->mainLoopIsRuning )
		{
			QueueFrame();
		}
	}

	void Engine::QueueFrame()
	{
		// Need to have a Iterator. TODO: CREATE ITERATOR AND PUT IT HERE.
		std::lock_guard<std::mutex> renderableObjectLock( this->mRenderableObjectsMutex );
		auto& nodeIt = this->get2DNodeFactory()->getNodes();
		if( false == nodeIt.isEmpty() )
		{
			unsigned int i = 0;
			while( nodeIt.hasNext() )
			{
				if( i == 218 )
				{
					auto dupa = 23;
				}
				this->renderer2D->render( *nodeIt.next().get() );
				++i;
			}
		}
		this->renderer2D->updateScreen();
		++mFrameCount;

//		for( auto& object : this->nodeFactory-> )
//		{
//			Render( *object );
//		}
//		this->renderer2D->updateScreen();
////		
//		
	}

	void Engine::Render( Node& node )
	{
		if( node.GetVisible() )
		{
			//std::lock_guard<std::mutex> lck( mListMutex );
			//SDL_Rect* screenRect = node.GetGeometricsInfo();
			//SDL_Rect* imageRect = nullptr;
			//SDL_BlitSurface( node.GetSurface()->GetSdlSurface(), imageRect, mScreenBuffor->GetSdlSurface(), screenRect );
            //TODO: Needs new texture logic.
		}
	}
}