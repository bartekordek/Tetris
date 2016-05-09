#include "Game.h"
#include "NodeFactory.h"

#include "BrickFactory.h"
#include "MTime.h"

#include <cstddef>
#include <boost/timer/timer.hpp>

namespace Tetris
{
	CGame::CGame():
		m_roundInProgress( false ),
		m_quit( false )
	{
	}

	CGame::~CGame()
	{
	}

	void CGame::Initialize( CUInt rowsCount, CUInt columnsCount, const Resolution& resoltion )
	{
		MOGE::Engine::Instance().Initialize( MOGE::Size( resoltion.width, resoltion.height ) );
		SetMainGridSize( rowsCount, columnsCount );
		SetMainGridFilledSlabImage();
		SetMainGridEmptySlabImage();
		CreateGrid();
	}

	void CGame::SetMainGridSize( CUInt rows, CUInt columns )
	{
		m_mainGrid.SetSize( rows, columns );
	}

	void CGame::SetMainGridFilledSlabImage()
	{
		mFilledSlabImage = MOGE::ImageCreator::CreateSurfaceFromImage( "D:\\Dev\\Tetris\\Tetris\\pic\\Block.bmp"  );
	}

	void CGame::SetMainGridEmptySlabImage()
	{
		mEmptySlabImage = MOGE::ImageCreator::CreateSurfaceFromImage( "D:\\Dev\\Tetris\\Tetris\\pic\\BackGroundBlock.bmp" );
	}

	void CGame::CreateGrid()
	{
		MOGE::Size size( 10, 10 );// TODO: Removed magic number '10'.
		for( CSlab& slab : m_mainGrid.GetSlabs() )
		{
			MOGE::Position position( slab.Col() * size.GetWidth(), slab.Row() * size.GetHeight() );

			MOGE::ObjectNode slabNode = MOGE::Node

			MOGE::NodePtr slabNode = MOGE::NodeFactory::CreateEmpty( position, size );
			slab.SetNode( slabNode );
			slab.GetNode()->SetImage( mEmptySlabImage );

			slabNode->SetVisible();
			MOGE::Engine::Instance().AddObject( slabNode );//TODO: redundant add, should be moved to NodeMgr
		}
	}

	void CGame::StartGame()
	{
		ReleaseBrick();
		ShowGrid();
	}

	void CGame::MainLoop()
	{
		SDL_Event event;
		MainLoopThread();
		//m_mainLoopThread = Thread( &CGame::MainLoopThread, this );
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
		m_mainLoopThread.join();
	}

	const bool CGame::IsKeyDown( const SDL_Event event )
	{
		if( SDL_KEYDOWN == event.type )
		{
			return true;
		}
		return false;
	}

	void CGame::HandleKeys( SDLKey sdlkey )
	{
		if( SDLK_RIGHT == sdlkey )
		{
			MoveActiveBrick( Direction::R );
		}
		else if( SDLK_LEFT == sdlkey )
		{
			MoveActiveBrick( Direction::L );
		}
		else if( SDLK_DOWN == sdlkey )
		{
			MoveActiveBrick( Direction::D );
		}
		else if( SDLK_SPACE == sdlkey )
		{
			RotateActualBrick();
		}
	}

	void CGame::MainLoopThread()
	{
		while( false == m_quit )
		{
			if( false == m_mainGrid.CheckIfBlockCanBeMoved( Direction::D ) )
			{
				AddCurrentBrickToGrid();
				CheckForFullLines();
				ReleaseBrick();
			}
			std::thread waitForSleep( &CGame::WaitForMove, this );
			waitForSleep.join();
			MoveActiveBrick( Direction::D );
		}
	}

	void CGame::WaitForMove()
	{
		CTimeMod::SleepMiliSeconds( 500 );
	}

	void CGame::ReleaseBrick()
	{
		m_mainGrid.ReLeaseBrick();
		ShowGrid();
	}

	void CGame::ShowGrid()
	{
		MOGE::Engine::Instance().RenderFrame();
	}

	void CGame::AddCurrentBrickToGrid()
	{
		CBrick* currentBrick = m_mainGrid.GetCurrentBrick();
		if( currentBrick )
		{
			for( auto& coord : currentBrick->GetBlockPositions() )
			{
				CSlab& slab = m_mainGrid.GetSlab( coord.Row(), coord.Col() );
				slab.Empty( false );
				slab.GetNode()->SetImage( mFilledSlabImage );
			}
		}
	}

	void CGame::CheckForFullLines()
	{
		m_mainGrid.ManageFullLine();
		ActualizeGrid();
	}

	void CGame::MoveActiveBrick( const Direction direction )
	{
		m_mainGrid.MoveActualBrick( direction );
		ActualizeGrid();
		ShowGrid();
	}

	void CGame::RotateActualBrick( const bool clockWise )
	{
		m_mainGrid.RotateActualBrick( clockWise );
	}

	void CGame::ActualizeGrid()
	{
		MOGE::Engine::Instance().RenderFrame();
	}

	const bool CGame::QuitHasBeenHit( const SDL_Event event )
	{
		if( event.type == SDL_QUIT || ( event.type == SDL_KEYDOWN && SDLK_q == event.key.keysym.sym ) )
		{
			return true;
		}
		return false;
	}
}