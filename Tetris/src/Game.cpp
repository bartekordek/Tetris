#include "Game.h"
#include "BrickFactory.h"
#include "NodeCreator.h"
#include "MultiPointFactory.h"
#include "IPositionAdapter.h"
#include "NodeImageCreator.h"

#include <cstddef>

#include <SDL.h>
#include <SDL_keyboard.h>
#include <SDL_keycode.h>
#include <SDL_events.h>

namespace Tetris
{
	CGame::CGame()
	{
	}

	CGame::~CGame()
	{
	}

	void CGame::Initialize( CUInt rowsCount, CUInt columnsCount, const Resolution& resoltion )
	{
		Moge::Engine::Instance().CreateScreen( Moge::Math::MultiPointFactory::create2d<unsigned int>( 640, 480 ) );
		Moge::Engine::Instance().StartMainLoop();
		m_mainGrid.SetSize( rowsCount, columnsCount );
	}

	void CGame::StartGame()
	{
		m_mainGrid.ReLeaseBrick();
	}

	void CGame::MainLoop()
	{
		m_mainLoopThread = std::thread( &CGame::MainLoopThread, this );
		userInputLoop();
		m_mainLoopThread.join();
	}

	void CGame::userInputLoop()
	{
		SDL_Event event;
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

	const bool CGame::IsKeyDown( const SDL_Event event )
	{
		if( SDL_KEYDOWN == event.type )
		{
			return true;
		}
		return false;
	}

	void CGame::HandleKeys( SDL_Keycode sdlkey )
	{
		if( SDLK_RIGHT == sdlkey )
		{
			m_mainGrid.MoveActualBrick( Directions::R );
		}
		else if( SDLK_LEFT == sdlkey )
		{
			m_mainGrid.MoveActualBrick( Directions::L );
		}
		else if( SDLK_DOWN == sdlkey )
		{
			m_mainGrid.MoveActualBrick( Directions::D );
		}
		else if( SDLK_SPACE == sdlkey )
		{
			m_mainGrid.RotateActualBrick( true );
		}
	}

	void CGame::MainLoopThread()
	{
		while( false == m_quit )
		{
			m_mainGrid.updateGrid();
		}
	}

	const bool CGame::QuitHasBeenHit( const SDL_Event event )
	{
		if( 
			SDL_QUIT == event.type || (
				SDL_KEYDOWN == event.type &&
				SDLK_q == event.key.keysym.sym ) )
		{
			return true;
		}
		return false;
	}
}