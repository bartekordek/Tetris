#include "Engine.h"
#include "NodeFactory.h"

namespace MOGE
{
	Engine::Engine( void ): mScreenBuffor( nullptr )
	{
		SDL_Init( SDL_INIT_EVERYTHING );
	}

	Engine::~Engine()
	{
		StopMainLoop();
		mScreenBuffor.~shared_ptr();
		mListMutex.lock();
		for( auto it = mRenderableObjects.begin(); it != mRenderableObjects.end(); ++it )
		{
			it->second.~shared_ptr();
		}
		mListMutex.unlock();
		SDL_Quit();
	}

	void Engine::Initialize( const Size& size )
	{
		Singleton::Instance().CreateScreen( size );
		Singleton::Instance().StartMainLoop();
	}

	void Engine::CreateScreen( const Size& size )
	{
		mScreenBuffor = NodeFactory::CreateScreen( size );
	}

	void Engine::AddObject( const Path& filePath, const Position& positionn, const String name )
	{
		NodePtr newNode = NodeFactory::CreateFromImage( filePath, positionn );
		//TODO MOVE TO FACTORY
		AddObject( newNode );
		
	}

	void Engine::AddObject( NodePtr& node, std::string name )
	{
		mListMutex.lock();
		if( name.empty() )
		{
			static unsigned int namelessObjectIndex = 0;
			name = "Object_" + std::to_string( namelessObjectIndex++ );
		}
		mRenderableObjects[name] = node;
		mListMutex.unlock();
	}

	NodePtr& Engine::GetNode( const std::string& nodeName )const
	{
		static NodePtr node;
		return node;
	}

	NodePtr& Engine::GetNode( CUInt noodeIt )const
	{
		static NodePtr node;
		return node;
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
		for( auto it = mRenderableObjects.begin(); it != mRenderableObjects.end(); ++it )
		{
			Render( *it->second );
		}
	}

	void Engine::Render( Node& node )
	{
		if( node.GetVisible() )
		{
			mListMutex.lock();
			SDL_BlitSurface( node.GetImage().get(), NULL, mScreenBuffor->GetImage().get(), node.GetGeometricsInfo() );
			mListMutex.unlock();
		}
	}
}