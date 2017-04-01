#include "Engine.h"
#include "NodeFactoryRegular.h"
#include "Math/IPositionAdapter.h"
#include "KeyboardObservable.h"
#include "IKeyboardObserver.h"
#include "KeyFactorySDL.h"
#include "SDLRenderer.h"
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
		ITextureFactory2D* tf2D = static_cast<ITextureFactory2D*>( txtFactory2D );
		auto tf3D = static_cast<ITextureFactory3D*>( this->textureFactory3D.get() );
		this->nodeFactory.reset( new NodeFactoryRegular( tf2D, tf3D ) );
	}

	Engine::~Engine()
	{
		std::lock_guard<std::mutex> lck( mListMutex );
		mRenderableObjects.erase( mRenderableObjects.begin(), mRenderableObjects.end() );
		SDL_Quit();
	}

	void Engine::AddObject( const Path& filePath, const Math::MultiPoint<double>& position, const MyString& name )
	{
		Math::IPositionAdapter<double> positionAdapter( position );
		std::shared_ptr<ObjectNodeContent> newNode = nodeFactory->CreateFromImage( filePath, positionAdapter, name );
		AddObject( newNode, name );
	}

	void Engine::AddObject( const std::shared_ptr<ObjectNodeContent> node, const MyString& name )
	{
		std::lock_guard<std::mutex> renderableObjectLock( mRenderableObjectsMutex );
		mRenderableObjects.insert( node );
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
	
	ITextureFactory2D* Engine::get2DTextureFactory() const
	{
		auto ptr = static_cast<SDLRenderer*>( this->renderer2D.get() );
		return ptr;
	}
	
	ITextureFactory3D* Engine::get3DTextureFactory() const
	{
		return this->textureFactory3D.get();
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
//		SDL_UpdateWindowSurface( mScreenBuffor->GetScreen() ); TODO SDL Update frame need to be updated.
		++mFrameCount;
	}

	void Engine::Render( ObjectNodeContent& node )
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