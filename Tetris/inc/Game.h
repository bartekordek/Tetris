#ifndef __GAME_Z__
#define __GAME_Z__

#include "MainGrid.h"

class CGame
{
public:
	static CGame* Instance();
	static void Destroy();

	void Initialize( const unsigned int xSize = 10, const unsigned ySize = 50 );
	void CreateWindow( const unsigned int xSize = 800, const unsigned ySize = 600 );
	void ShowGrid();
	void MainLoop();

private:
	void m_SetGameSize( const unsigned int xSize, const unsigned ySize );
	void m_SetMainGridBlockBackgroundImage();
	CGame();
	
	bool m_roundInProgress;
	CMainGrid mainGrid;

	static CGame* s_instance;

};

#endif