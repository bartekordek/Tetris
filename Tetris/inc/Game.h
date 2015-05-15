#ifndef __GAME_Z__
#define __GAME_Z__

#include "MainGrid.h"
#include "Brick.h"

class CGame
{
public:
	static CGame* Instance();
	static void Destroy();

	void Initialize( const unsigned int xSize = 10, const unsigned ySize = 50 );
	void CreateWindow( const unsigned int xSize = 800, const unsigned ySize = 600 );
	void ShowGrid();
	void ShowStartButton();
	void MainLoop();
	void StartGame();

private:
	void m_SetGameSize( const unsigned int rows, const unsigned columns );
	void m_SetMainGridBlockBackgroundImage();
	void m_ReleaseBrick( const std::string& brickType );
	void m_ShowWindow();
	CGame();
	virtual ~CGame();
	
	bool m_roundInProgress;

	CMainGrid mainGrid;
	CBrick* m_activeBrick;
	static CGame* s_instance;

};

#endif