#include "Game.h"

#include "BrickFactory.h"
#include "MTime.h"
#include <cstddef>
#include <boost/timer/timer.hpp>

CGame::CGame(): m_roundInProgress(false),m_quit(false)
{
}


CGame::~CGame()
{
}

void CGame::Initialize( CUInt rowsCount, CUInt columnsCount )
{
	SetGameSize( rowsCount, columnsCount );
	SetMainGridBlockBackgroundImage();
	SetMainGridSlabBackgroundImage();
}

void CGame::InitWindow( CUInt xSize, CUInt ySize )
{
	sdlWrapper.CreateWindow( xSize, ySize );
	sdlWrapper.AddImage( m_mainGrid.SlabPictureLoc() );
	sdlWrapper.AddImage( m_mainGrid.EmptySlabPictureLoc() );
}

void CGame::StartGame()
{
	ReleaseBrick();
	ShowGrid();
}

void CGame::MainLoop()
{
	SDL_Event event;
	m_mainLoopThread = Thread( &CGame::MainLoopThread, this );
	while( false == m_quit)
	{
		while( SDL_PollEvent( &event ) )
		{
			if(  true == QuitHasBeenHit(event) )
			{
				m_quit = true;
			}
			else if( IsKeyDown(event) )
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
	sdlWrapper.Display( m_mainGrid );
}

void CGame::AddCurrentBrickToGrid()
{
	m_mainGrid.AddCurrentBrickToGrid();
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

void CGame::ActualizeGrid( )
{
	sdlWrapper.Actualize();
}

void CGame::SetMainGridBlockBackgroundImage()
{
	//Path picDir = Fs::current_path().parent_path();
	//picDir =  picDir / "pic" / "BackGroundBlock.bmp";
	m_mainGrid.SetBackgroundPicture( "D:\\Dev\\Tetris\\Tetris\\pic\\BackGroundBlock.bmp", 10, 10 );
}

void CGame::SetMainGridSlabBackgroundImage()
{
	//Path picDir = Fs::current_path();
	//picDir = picDir.parent_path() / "pic" / "Block.bmp";
	m_mainGrid.SetSlabPic( "D:\\Dev\\Tetris\\Tetris\\pic\\Block.bmp", 10, 10 );
}

const bool CGame::QuitHasBeenHit( const SDL_Event event )
{
	if( event.type == SDL_QUIT || ( event.type == SDL_KEYDOWN && SDLK_q == event.key.keysym.sym ) )
	{
		return true;
	}
	return false;
}

void CGame::SetGameSize( CUInt rows, CUInt columns )
{
	m_mainGrid.SetSize( rows, columns );
}