#include "Game.h"
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

void CGame::Initialize()
{

}

void CGame::MainLoop()
{

}

CGame* CGame::s_instance = NULL;