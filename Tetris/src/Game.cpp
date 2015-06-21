#include "Game.h"
#include "SDLWrapper.h"
#include "BrickFactory.h"
#include "MTime.h"
#include <cstddef>
#include <boost/timer/timer.hpp>

//#include <functional>


CGame* CGame::s_instance = NULL;

CGame::CGame()
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

void CGame::Initialize( CUInt rowsCount, CUInt columnsCount )
{
	m_SetGameSize( rowsCount, columnsCount );
	SetMainGridBlockBackgroundImage();
	SetMainGridSlabBackgroundImage();
	m_StartEventPoolThread();
}

void CGame::m_StartEventPoolThread()
{
	CGame* gameInstance = CGame::Instance();
	eventHandler.AddQuitActionHandler( std::bind( &CGame::QuitGame, this ) );
	eventPoolThread = new std::thread( EventPoolFunction );
}

void QuitGame()
{
	CGame::Instance()->QuitGame();
}

void EventPoolFunction()
{
	CGame::Instance()->eventHandler.MainEventLoop();
}

void CGame::InitWindow( CUInt xSize, CUInt ySize )
{
	CSDLWrapper::Instance()->CreateWindow( xSize, ySize );
	CSDLWrapper::Instance()->AddImage( mainGrid.SlabPictureLoc() );
	CSDLWrapper::Instance()->AddImage( mainGrid.EmptySlabPictureLoc() );
	CSDLWrapper::Instance()->AddImage( m_GetQuitButtonLocation() );
}

void CGame::StartGame()
{
	AddButton( 200, 50, "Quit", m_GetQuitButtonLocation() );
	m_ReleaseBrick();
	ShowGrid();
}

void CGame::AddButton( CUInt x, CUInt y, String name, Path path )
{
	m_buttons.push_back( CButton( x, y, name, path ) );
	CSDLWrapper::Instance()->Display( m_buttons.back() );
}

String CGame::m_GetQuitButtonLocation()
{
	Path picDir = Fs::current_path();
	picDir = picDir.parent_path() / "pic" / "ButtonQuit.bmp";
	String buttonLocationPathAsString( picDir.string() );
	return buttonLocationPathAsString;
}

void CGame::MainLoop()
{
	mainLoopThread = new std::thread( &CGame::m_MainLoopThread, this );
	mainLoopThread->join();
}

void CGame::m_MainLoopThread()
{
	bool quit = false;
	SDL_Event event;
	while( true )
	{
		if( false == mainGrid.CheckIfBlockCanBeMoved( Direction::D ) )
		{
			m_AddCurrentBrickToGrid();
			m_ReleaseBrick();
		}
		std::thread waitForSleep( &CGame::m_WaitForMove, this );
		std::cout << "Waiting for user input..." << std::endl;
		while( SDL_PollEvent( &event ) )
		{
			if( event.type == SDL_KEYDOWN )
			{
				switch( event.key.keysym.sym )
				{
					case SDLK_q:
						QuitGame();
						break;
					case SDLK_h:
						std::cout << "h pressed " << std::endl;
						break;
				}
			}
		}
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
	mainGrid.ReLeaseBrick();
	ShowGrid();
}

void CGame::ShowGrid()
{
	CSDLWrapper::Instance()->Display( mainGrid );
	CSDLWrapper::Instance()->Actualize();
}

void CGame::m_AddCurrentBrickToGrid()
{
	mainGrid.AddCurrentBrickToGrid();
}

void CGame::m_MoveActiveBrick( const Direction direction )
{
	mainGrid.MoveActualBrick( direction );
	m_ActualizeGrid( mainGrid );
	ShowGrid();
}

void CGame::m_ActualizeGrid( const CMainGrid& grid )
{
	CSDLWrapper::Instance()->Actualize();
}

void CGame::m_ShowWindow()
{
	//FLTKWrapper::Instance()->StartEventHandler();
}

void CGame::SetMainGridBlockBackgroundImage()
{
	Path picDir = Fs::current_path();
	picDir = picDir.parent_path() / "pic" / "BackGroundBlock.bmp";
	mainGrid.SetBackgroundPicture( picDir, 10, 10 );
}

void CGame::SetMainGridSlabBackgroundImage()
{
	Path picDir = Fs::current_path();
	picDir = picDir.parent_path() / "pic" / "Block.bmp";
	mainGrid.SetSlabPic( picDir, 10, 10 );
}

void CGame::m_SetGameSize( CUInt rows, CUInt columns )
{
	mainGrid.SetSize( rows, columns );
}

void CGame::QuitGame()
{
	Destroy();
}

CGame::~CGame()
{
	delete eventPoolThread;
}