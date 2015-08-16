#ifndef __GAME_Z__
#define __GAME_Z__

#include <thread>

#include "MainGrid.h"
#include "Brick.h"
#include "Utils.h"
#include "Button.h"
#include "EventHandler.h"

class CGame
{
public:
	CGame();
	void Initialize( CUInt rowsCount = 50, CUInt columnsCount = 10 );
	void InitWindow( CUInt width = 600, CUInt height = 400 );
	void ShowGrid();
	void MainLoop();
	void StartGame();
	void SetMainGridBlockBackgroundImage();
	void SetMainGridSlabBackgroundImage();
	void QuitGame();
	CEventHandler eventHandler;
	virtual ~CGame();

private:
	void m_SetGameSize( CUInt rows, CUInt columns );
	void m_MoveActiveBrick( const Direction direction = Direction::D );
	void m_RotateActualBrick( const bool clockWise = true );
	void m_ReleaseBrick();
	void m_ShowWindow();
	void m_ActualizeGrid();
	void m_AddCurrentBrickToGrid();
	void m_MainLoopThread();
	void m_WaitForMove();
	void m_CheckForFullLines();
	String m_GetQuitButtonLocation();

	bool m_roundInProgress;

	CMainGrid m_mainGrid;
	std::thread m_mainLoopThread;

	bool m_quit;
};

void QuitGame();

#endif
