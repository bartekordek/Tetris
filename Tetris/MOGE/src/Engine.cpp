#include "Engine.h"
#include "NodeFactory.h"

namespace MOGE
{
	MOGE::MOGE( void ):
		mScreenBuffor( nullptr )
	{
		SDL_Init( SDL_INIT_EVERYTHING );
	}

	MOGE::~MOGE()
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

	void MOGE::Initialize( const Size& size )
	{
		Singleton::Instance().CreateScreen( size );
		Singleton::Instance().StartMainLoop();
	}

	void MOGE::CreateScreen( const Size& size )
	{
		mScreenBuffor = NodeFactory::CreateScreen( size );
	}

	void MOGE::AddObject( const Path& filePath, const Position& positionn )
	{
		NodePtr newNode = NodeFactory::CreateFromImage( filePath, positionn );
		AddObject( newNode );
	}

	void MOGE::AddObject( NodePtr& node )
	{
		mListMutex.lock();
		mRenderableObjects[ node->GetPath().string() ] = node;
		mListMutex.unlock();
	}

	void MOGE::StartMainLoop()
	{
		//mainLoop.
	}

	void MOGE::StopMainLoop()
	{
		
	}

	void MOGE::QueueFrame()
	{
		for( auto it = mRenderableObjects.begin(); it != mRenderableObjects.end(); ++it )
		{
			Render( *it->second );
		}
	}

	void MOGE::Render( Node& node )
	{
		if( node.IsVisible() )
		{
			mListMutex.lock();
			SDL_BlitSurface( node.GetImage().get(), NULL, mScreenBuffor->GetImage().get(), node.GetGeometricsInfo() );
			mListMutex.unlock();
		}
	}
}