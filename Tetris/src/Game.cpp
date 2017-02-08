#include "Game.h"
#include "MultiPointFactory.h"

#include "MainGrid.h"
#include "MogeLibMain.h"

namespace Tetris
{
	using namespace Moge;
	CGame::CGame()
	{
	}

	CGame::~CGame()
	{
		EngineManager::destroyEngine();
	}

	void CGame::initialize( CUInt rowsCount, CUInt columnsCount, CUInt winWidth, CUInt winHeight )
	{
		EngineManager::initializeEngine();
		EngineManager::getEngine()->createScreen( Math::MultiPointFactory::create2d<unsigned int>( winWidth, winHeight ) );
		m_mainGrid = new CMainGrid();
        EngineManager::getEngine()->registerObserver( this );
		EngineManager::getEngine()->initialize();
		m_mainGrid->SetSize( rowsCount, columnsCount );
	}

	void CGame::StartGame()
	{
		m_mainGrid->ReLeaseBrick();
	}

	void CGame::keyboardEvent( IKey* data )
	{
		if( "q" == data->getKeyName() && data->getKeyIsDown() )
		{
			m_quit = true;
			return;
		}

		if( data->getKeyIsDown() )
		{
			std::cout << "Key " << data->getKeyName() << " is down." << std::endl;
		}
	}
	/*
	void CGame::userInputLoop()
	{
		SDL_Event event;
		while( false == m_quit )
		{
			SDL_PollEvent( &event );
		}
		
		while( false == m_quit )
		{
			while( SDL_PollEvent( &event ) )
			{
				if( true == QuitHasBeenHit( event ) )
				{
					m_quit = true;
				}
				else if( IsKeyDown( event ) )
				{
					HandleKeys( event.key.keysym.sym );
				}
			}
		}
	}
	*/
	//const bool CGame::IsKeyDown( const SDL_Event event )
	//{
	//	if( SDL_KEYDOWN == event.type )
	//	{
	//		return true;
	//	}
	//	return false;
	//}

	//void CGame::HandleKeys( SDL_Keycode sdlkey )
	//{
	//	if( SDLK_RIGHT == sdlkey )
	//	{
	//		m_mainGrid->MoveActualBrick( Moge::Math::Directions::R );
	//	}
	//	else if( SDLK_LEFT == sdlkey )
	//	{
	//		m_mainGrid->MoveActualBrick( Moge::Math::Directions::L );
	//	}
	//	else if( SDLK_DOWN == sdlkey )
	//	{
	//		m_mainGrid->MoveActualBrick( Moge::Math::Directions::D );
	//	}
	//	else if( SDLK_SPACE == sdlkey )
	//	{
	//		m_mainGrid->RotateActualBrick( true );
	//	}
	//}

	void CGame::frontEndLoop()
	{
		while( false == m_quit )
		{
			m_mainGrid->updateGrid();
		}
	}


	//const bool CGame::QuitHasBeenHit( const SDL_Event event )
	//{
	//	if( 
	//		SDL_QUIT == event.type || (
	//			SDL_KEYDOWN == event.type &&
	//			SDLK_q == event.key.keysym.sym ) )
	//	{
	//		return true;
	//	}
	//	return false;
	//}
}
