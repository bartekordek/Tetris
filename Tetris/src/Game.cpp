#include "Game.h"
#include "FLTKWrapper.h"
#include "BrickFactory.h"
#include <cstddef>
#include <boost/timer/timer.hpp>

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
	m_SetMainGridBlockBackgroundImage();
}

void CGame::CreateWindow( const unsigned int xSize, const unsigned ySize)
{
	FLTKWrapper::Instance()->InitWindow();
}

void CGame::ShowGrid()
{
	FLTKWrapper::Instance()->Display( mainGrid );
}

void CGame::ShowStartButton()
{

}

void CGame::MainLoop()
{
	m_ShowWindow();
	m_ReleaseBrick( "L" );
}

void CGame::m_ShowWindow()
{
	FLTKWrapper::Instance()->ShowWindow();
}

void CGame::StartGame()
{

}

void CGame::m_ReleaseBrick( const std::string& brickType )
{
	m_activeBrick = CBrickFactory::GetBrick( brickType );
}

void CGame::m_SetGameSize( const unsigned int rows, const unsigned columns )
{
	mainGrid.SetSize( rows, columns );
}

void CGame::m_SetMainGridBlockBackgroundImage()
{
	boost::filesystem::path picDir = boost::filesystem::current_path();
	picDir = picDir.parent_path() / "pic" / "BackGroundBlock.bmp";
	mainGrid.SetBackgroundPicture( picDir, 10, 10 );
}

CGame::~CGame()
{
	delete m_activeBrick;
}

CGame* CGame::s_instance = NULL;