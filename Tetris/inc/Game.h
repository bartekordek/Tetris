#ifndef __GAME_Z__
#define __GAME_Z__

#include "MainGrid.h"
#include "Brick.h"
#include "Utils.h"

class CGame
{
public:
	static CGame* Instance();
	static void Destroy();

	void Initialize( CUInt xSize = 10, CUInt ySize = 50 );
	void InitWindow( CUInt xSize = 800, CUInt ySize = 600 );
	void ShowGrid();
	void MainLoop();
	void StartGame();
	void SetMainGridBlockBackgroundImage();
	void SetMainGridSlabBackgroundImage();
	void SetBrickImage();
	void SetWindowColor();

private:
	void m_SetGameSize( CUInt rows, CUInt columns );
	void m_MoveActiveBrick( const Direction direction = Direction::D );
	void m_ReleaseBrick();
	void m_ShowWindow();
	void m_ActualizeGrid( const CMainGrid& grid );
	CGame();
	virtual ~CGame();
	
	bool m_roundInProgress;

	CMainGrid mainGrid;
	static CGame* s_instance;

};

#endif