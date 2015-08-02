#include "Game.h"
#include "SDLWrapper.h"
#include "BrickFactory.h"
#include "MTime.h"
#include <cstddef>
#include <boost/timer/timer.hpp>

CGame* CGame::s_instance = NULL;

CGame::CGame(): m_roundInProgress(false), m_mainGrid(NULL),m_quit(false)
{
	m_mainGrid = new CMainGrid();
}

CGame* CGame::Instance()
{
	if( NULL == s_instance )
	{
		s_instance = new CGame();
	}
	return s_instance;
}

void CGame::Destroy()
{
	CSDLWrapper::Destroy();
	delete s_instance;
	s_instance = NULL;
}

CGame::~CGame()
{
	delete m_mainGrid;
}

void CGame::Initialize( CUInt rowsCount, CUInt columnsCount )
{
	m_SetGameSize( rowsCount, columnsCount );
	SetMainGridBlockBackgroundImage();
	SetMainGridSlabBackgroundImage();
}

void QuitGame()
{
	CGame::Instance()->QuitGame();
}

void CGame::InitWindow( CUInt xSize, CUInt ySize )
{
	CSDLWrapper::Instance()->CreateWindow( xSize, ySize );
	CSDLWrapper::Instance()->AddImage( m_mainGrid->SlabPictureLoc() );
	CSDLWrapper::Instance()->AddImage( m_mainGrid->EmptySlabPictureLoc() );
}

void CGame::StartGame()
{
	m_ReleaseBrick();
	ShowGrid();
}

void CGame::MainLoop()
{
	SDL_Event event;
	m_mainLoopThread = std::thread( &CGame::m_MainLoopThread, this );
	while( false == m_quit)
	{
		while( SDL_PollEvent( &event ) )
		{
			if( event.type == SDL_QUIT )
			{
				m_quit = true;
			}
			else if( event.type == SDL_KEYDOWN )
			{
				switch( event.key.keysym.sym )
				{
					case SDLK_q:
						m_quit = true;
						break;
					case SDLK_RIGHT:
						m_MoveActiveBrick( Direction::R );
						break;
					case SDLK_LEFT:
						m_MoveActiveBrick( Direction::L );
						break;
					case SDLK_DOWN:
						m_MoveActiveBrick( Direction::D );
						break;
					case SDLK_SPACE:
						m_RotateActualBrick();
				}
			}
		}
	}
	m_mainLoopThread.join();
}

void CGame::m_MainLoopThread()
{
	while( false == m_quit )
	{
		if( false == m_mainGrid->CheckIfBlockCanBeMoved( Direction::D ) )
		{
			m_AddCurrentBrickToGrid();
			m_CheckForFullLines();
			m_ReleaseBrick();
		}
		std::thread waitForSleep( &CGame::m_WaitForMove, this );
		waitForSleep.join();
		m_MoveActiveBrick( Direction::D );
	}
}

void CGame::m_WaitForMove()
{
	CTimeMod::SleepMiliSeconds( 500 );
}

void CGame::m_ReleaseBrick()
{
	m_mainGrid->ReLeaseBrick();
	ShowGrid();
}

void CGame::ShowGrid()
{
	CSDLWrapper::Instance()->Display( *m_mainGrid );
	CSDLWrapper::Instance()->Actualize();
}

void CGame::m_AddCurrentBrickToGrid()
{
	m_mainGrid->AddCurrentBrickToGrid();
}

void CGame::m_CheckForFullLines()
{
	m_mainGrid->ManageFullLine();
	m_ActualizeGrid();
}

void CGame::m_MoveActiveBrick( const Direction direction )
{
	m_mainGrid->MoveActualBrick( direction );
	m_ActualizeGrid();
	ShowGrid();
}

void CGame::m_RotateActualBrick( const bool clockWise )
{
	m_mainGrid->RotateActualBrick( clockWise );
	m_ActualizeGrid();
	ShowGrid();
}

void CGame::m_ActualizeGrid( )
{
	CSDLWrapper::Instance()->Actualize();
}

void CGame::m_ShowWindow()
{
}

void CGame::SetMainGridBlockBackgroundImage()
{
	Path picDir = Fs::current_path().parent_path();
	picDir =  picDir / "pic" / "BackGroundBlock.bmp";
	m_mainGrid->SetBackgroundPicture( picDir, 10, 10 );
}

void CGame::SetMainGridSlabBackgroundImage()
{
	Path picDir = Fs::current_path();
	picDir = picDir.parent_path() / "pic" / "Block.bmp";
	m_mainGrid->SetSlabPic( picDir, 10, 10 );
}

void CGame::m_SetGameSize( CUInt rows, CUInt columns )
{
	m_mainGrid->SetSize( rows, columns );
}

void CGame::QuitGame()
{
	Destroy();
}
