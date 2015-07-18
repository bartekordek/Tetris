#include "Game.h"
#include "SDLWrapper.h"
#include "BrickFactory.h"
#include "MTime.h"
#include <cstddef>
#include <boost/timer/timer.hpp>

CGame* CGame::s_instance = NULL;

CGame::CGame(): mainLoopThread(NULL)
{
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
}

CGame::~CGame()
{
}

void CGame::Initialize( CUInt rowsCount, CUInt columnsCount )
{
	//m_SetGameSize( rowsCount, columnsCount );
	//SetMainGridBlockBackgroundImage();
	//SetMainGridSlabBackgroundImage();
}

void QuitGame()
{
	CGame::Instance()->QuitGame();
}

void CGame::InitWindow( CUInt xSize, CUInt ySize )
{
//	CSDLWrapper::Instance()->CreateWindow( xSize, ySize );
//	CSDLWrapper::Instance()->AddImage( mainGrid.SlabPictureLoc() );
//	CSDLWrapper::Instance()->AddImage( mainGrid.EmptySlabPictureLoc() );
//	CSDLWrapper::Instance()->AddImage( m_GetQuitButtonLocation() );
}

//void CGame::StartGame()
//{
//	m_ReleaseBrick();
//	ShowGrid();
//}

String CGame::m_GetQuitButtonLocation()
{
	Path picDir = Fs::current_path();
	picDir = picDir.parent_path() / "pic" / "ButtonQuit.bmp";
	String buttonLocationPathAsString( picDir.string() );
	return buttonLocationPathAsString;
}

void CGame::MainLoop()
{
	/*SDL_Event event;
	mainLoopThread = new std::thread( &CGame::m_MainLoopThread, this );
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
	}*/
}
//
//void CGame::m_MainLoopThread()
//{
//	while( false == m_quit )
//	{
//		if( false == mainGrid.CheckIfBlockCanBeMoved( Direction::D ) )
//		{
//			m_AddCurrentBrickToGrid();
//			m_CheckForFullLines();
//			m_ReleaseBrick();
//		}
//		std::thread waitForSleep( &CGame::m_WaitForMove, this );
//		waitForSleep.join();
//		m_MoveActiveBrick( Direction::D );
//	}
//}

void CGame::m_WaitForMove()
{
	CTimeMod::SleepMiliSeconds( 500 );
}

//void CGame::m_ReleaseBrick()
//{
//	mainGrid.ReLeaseBrick();
//	ShowGrid();
//}

//void CGame::ShowGrid()
//{
//	CSDLWrapper::Instance()->Display( mainGrid );
//	CSDLWrapper::Instance()->Actualize();
//}
//
//void CGame::m_AddCurrentBrickToGrid()
//{
//	mainGrid.AddCurrentBrickToGrid();
//}
//
//void CGame::m_CheckForFullLines()
//{
//	mainGrid.ManageFullLine();
//	m_ActualizeGrid();
//}
//
//void CGame::m_MoveActiveBrick( const Direction direction )
//{
//	mainGrid.MoveActualBrick( direction );
//	m_ActualizeGrid();
//	ShowGrid();
//}
//
//void CGame::m_RotateActualBrick( const bool clockWise )
//{
//	mainGrid.RotateActualBrick( clockWise );
//	m_ActualizeGrid();
//	ShowGrid();
//}

void CGame::m_ActualizeGrid( )
{
	CSDLWrapper::Instance()->Actualize();
}

void CGame::m_ShowWindow()
{
}

//void CGame::SetMainGridBlockBackgroundImage()
//{
//	Path picDir = Fs::current_path();
//	picDir = picDir.parent_path() / "pic" / "BackGroundBlock.bmp";
//	mainGrid.SetBackgroundPicture( picDir, 10, 10 );
//}
//
//void CGame::SetMainGridSlabBackgroundImage()
//{
//	Path picDir = Fs::current_path();
//	picDir = picDir.parent_path() / "pic" / "Block.bmp";
//	mainGrid.SetSlabPic( picDir, 10, 10 );
//}
//
//void CGame::m_SetGameSize( CUInt rows, CUInt columns )
//{
//	mainGrid.SetSize( rows, columns );
//}

void CGame::QuitGame()
{
	Destroy();
}