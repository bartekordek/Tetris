#include "Game.h"
//#include "FLTKWrapper.h"
#include "SDLWrapper.h"
#include "BrickFactory.h"
#include "MTime.h"
#include <cstddef>
#include <boost/timer/timer.hpp>

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

void CGame::Initialize( CUInt xSize, CUInt ySize )
{
	m_SetGameSize( xSize, ySize );
	SetMainGridBlockBackgroundImage();
	SetMainGridSlabBackgroundImage();
	SetBrickImage();
}

void CGame::InitWindow( CUInt xSize, CUInt ySize )
{
	CSDLWrapper::Instance()->CreateWindow( 800, 600 );
	CSDLWrapper::Instance()->AddImage( mainGrid.SlabPictureLoc() );
	CSDLWrapper::Instance()->AddImage( mainGrid.EmptySlabPictureLoc() );
}

void CGame::ShowGrid()
{
	CSDLWrapper::Instance()->Display( mainGrid );
//	m_ShowWindow();
	CSDLWrapper::Instance()->Actualize();
}

void CGame::StartGame()
{
	m_ReleaseBrick();
	ShowGrid();
}

void CGame::m_ReleaseBrick()
{
	mainGrid.ReLeaseBrick();
}

void CGame::MainLoop()
{
	bool quit = false;
	while( true )
	{
		if( false == mainGrid.CheckIfBlockCanBeMoved( Direction::D  ) )
		{
			m_AddCurrentBrickToGrid();
			m_ReleaseBrick();
		}
		CTimeMod::SleepMiliSeconds( 500 );
		m_MoveActiveBrick( Direction::D );
	}
}

void CGame::m_AddCurrentBrickToGrid()
{
	mainGrid.AddCurrentBrickToGrid();
}

void CGame::m_ActualizeGrid( const CMainGrid& grid )
{
	//FLTKWrapper::Instance()->Actualize( grid );
}

void CGame::m_MoveActiveBrick( const Direction direction )
{
	//m_activeBrick->Move(direction);
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

void CGame::SetBrickImage()
{
	Path picDir = Fs::current_path();
	picDir = picDir.parent_path() / "pic" / "Block.bmp";
	CBrick::SetBackgroundImage( picDir );
}


void CGame::m_SetGameSize( CUInt rows, CUInt columns )
{
	mainGrid.SetSize( rows, columns );
}

CGame::~CGame()
{
}