#include "Engine.h"


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
		for( auto it = mRenderableObjects.begin(); it != mRenderableObjects.end(); ++it )
		{
			it->second.~ObjectNode();
		}
		SDL_Quit();
	}

	void Engine::Initialize( const Size& size )
	{
		Singleton::Instance().CreateScreen( size );
		Singleton::Instance().StartMainLoop();
	}

	void Engine::CreateScreen( const Size& size )
	{
		std::lock_guard<std::mutex> lck( mListMutex );
//		mScreenBuffor = NodeFactory::CreateScreen( size );
	}

	void Engine::AddObject( const Path& filePath, const Position& positionn, const String name )
	{
		std::lock_guard<std::mutex> lck( mListMutex );
	//	NodePtr newNode = NodeFactory::CreateFromImage( filePath, positionn );
	//	AddObject( newNode, name );//TODO MOVE TO FACTORY
	}

	void Engine::AddObject( ObjectNode& node, std::string name )
	{
		std::lock_guard<std::mutex> lck( mListMutex );
		if( name.empty() )
		{
			static unsigned int namelessObjectIndex = 0;
			name = "Object_" + std::to_string( namelessObjectIndex++ );
		}
		mRenderableObjects[name] = node;
	}

	void Engine::RenderFrame()
	{
	/*	QueueFrame();
		std::lock_guard<std::mutex> lck( mListMutex );
		SDL_RenderPresent( mScreenBuffor->GetImage().get() );
		SDL_Flip(  );*/
		// TODO
	}

	void Engine::StartMainLoop()
	{
		//mainLoop.
	}

	void Engine::StopMainLoop()
	{
		
	}

	void Engine::QueueFrame()
	{
		unsigned int index = 0;
		for( auto object : mRenderableObjects )
		{
	//		Render( *object.second );
			++index;
		}
	}

	void Engine::Render( Node& node )
	{
		if( node.GetVisible() )
		{
			/*std::lock_guard<std::mutex> lck( mListMutex );
			SDL_Surface* screen = mScreenBuffor->GetImage().get();
			SDL_Rect* screenRect = node.GetGeometricsInfo();
			SDL_Surface* image = node.GetImage().get();
			SDL_Rect* imageRect = nullptr;
			SDL_BlitSurface( image, imageRect, screen, screenRect );*/
			//TODO
		}
	}
}