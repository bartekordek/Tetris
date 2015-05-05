#include "Game.h"
#include "FLTKWrapper.h"
#include <cstddef>

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

void CGame::MainLoop()
{
	FLTKWrapper::Instance()->ShowWindow();
}

void CGame::m_SetGameSize( const unsigned int xSize, const unsigned ySize )
{
	mainGrid.SetSize( xSize, ySize );
}

void CGame::m_SetMainGridBlockBackgroundImage()
{
	boost::filesystem::path picDir = boost::filesystem::current_path();
	picDir = picDir.parent_path() / "pic" / "BackGroundBlock.bmp";
	mainGrid.SetBackgroundPicture( picDir, 10, 10 );
}

CGame* CGame::s_instance = NULL;