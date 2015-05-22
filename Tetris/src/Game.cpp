#include "Game.h"
#include "FLTKWrapper.h"
#include "BrickFactory.h"
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
}

void CGame::Initialize( const unsigned int xSize, const unsigned ySize )
{
	m_SetGameSize( xSize, ySize );
	SetMainGridBlockBackgroundImage();
	SetBrickImage();
}

void CGame::InitWindow( const unsigned int xSize, const unsigned int ySize)
{
	FLTKWrapper::Instance()->InitWindow();
}

void CGame::ShowGrid()
{
	FLTKWrapper::Instance()->Display( mainGrid );
	m_ShowWindow();
}

void CGame::ShowStartButton()
{
}

void CGame::StartGame()
{
	MainLoop();
}

void CGame::MainLoop()
{
	m_ReleaseBrick( "L" );
	m_ShowBrick();
}

void CGame::m_ShowBrick()
{
	FLTKWrapper::Instance()->Display( *m_activeBrick );
}

void CGame::m_MoveActiveBrick( const Direction direction )
{
	m_activeBrick->Move(direction);
}

void CGame::m_ShowWindow()
{
	FLTKWrapper::Instance()->ShowWindow();
}


void CGame::SetMainGridBlockBackgroundImage()
{
	Path picDir = Fs::current_path();
	picDir = picDir.parent_path() / "pic" / "BackGroundBlock.bmp";
	mainGrid.SetBackgroundPicture( picDir, 10, 10 );
}

void CGame::SetBrickImage()
{
	Path picDir = Fs::current_path();
	picDir = picDir.parent_path() / "pic" / "Block.bmp";
	CBrick::SetBackgroundImage( picDir );
}

void CGame::m_ReleaseBrick( const std::string& brickType )
{
	m_activeBrick = CBrickFactory::GetBrick( brickType );
}

void CGame::m_SetGameSize( const unsigned int rows, const unsigned columns )
{
	mainGrid.SetSize( rows, columns );
}

CGame::~CGame()
{
	delete m_activeBrick;
}