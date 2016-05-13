#include "Engine.h"
#include "NodeCreator.h"

namespace MOGE
{
	Engine::Engine( void )
	{
		SDL_Init( SDL_INIT_EVERYTHING );
	}

	Engine::~Engine()
	{
		StopMainLoop();
		std::lock_guard<std::mutex> lck( mListMutex );

		mRenderableObjects.erase( mRenderableObjects.begin(), mRenderableObjects.end() );

		SDL_Quit();
	}

	void Engine::CreateScreen( const Size& size )
	{
		std::lock_guard<std::mutex> lck( mListMutex );
		mScreenBuffor = NodeCreator::CreateScreen( size );
		mScreenBuffor.SetXY( -1024, 256 );
		mScreenBuffor.Initialize();
	}

	void Engine::AddObject( const Path& filePath, const Position3d& position, const String& name )
	{
		ObjectNode newNode = NodeCreator::CreateFromImage( filePath, position, name );
		AddObject( newNode, name );
	}

	void Engine::AddObject( const ObjectNode  node, const String& name )
	{
		mRenderableObjectsMutex.lock();
		mRenderableObjects.insert( node );
		mRenderableObjectsMutex.unlock();
	}

	const unsigned int Engine::ObjectCount()const
	{
		return mRenderableObjects.size();
	}

	void Engine::StartMainLoop()
	{
		mMainLoopMutex.lock();
		mainLoopIsRuning = true;
		mMainLoopMutex.unlock();
		mainLoop = std::thread( &Engine::MainLoop, this );
	}

	void Engine::StopMainLoop()
	{
		mMainLoopMutex.lock();
		mainLoopIsRuning = false;
		mMainLoopMutex.unlock();
		mainLoop.join();
	}

	void Engine::MainLoop()
	{
		while( mainLoopIsRuning )
		{
			QueueFrame();
		}
	}

	void Engine::QueueFrame()
	{
		mRenderableObjectsMutex.lock();
		for( auto& object : mRenderableObjects )
		{
			Render( *object );
		}
		mRenderableObjectsMutex.unlock();
		//SDL_RenderPresent( mScreenBuffor.GetRenderer() );
		SDL_UpdateWindowSurface( mScreenBuffor.GetScreen() );
		++mFrameCount;
	}

	void Engine::Render( ObjectNodeContent& node )
	{
		if( node.GetVisible() )
		{
			std::lock_guard<std::mutex> lck( mListMutex );
			SDL_Rect* screenRect = node.GetGeometricsInfo();
			SDL_Rect* imageRect = nullptr;
			SDL_BlitSurface( node.GetSurface()->GetSdlSurface(), imageRect, mScreenBuffor.GetSdlSurface(), screenRect );

			/*
			SDL_Surface* screen = mScreenBuffor->GetImage().get();
			SDL_Rect* screenRect = node.GetGeometricsInfo();
			SDL_Surface* image = node.GetImage().get();
			SDL_Rect* imageRect = nullptr;
			SDL_BlitSurface( image, imageRect, screen, screenRect );*/
			//TODO
		}
	}
}