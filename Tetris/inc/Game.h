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

	void Initialize( const unsigned int xSize = 10, const unsigned ySize = 50 );
	void InitWindow( const unsigned int xSize = 800, const unsigned int ySize = 600 );
	void ShowGrid();
	void ShowStartButton();
	void MainLoop();
	void StartGame();
	void SetMainGridBlockBackgroundImage();
	void SetBrickImage();
	void SetWindowColor();

private:
	void m_SetGameSize( const unsigned int rows, const unsigned columns );
	void m_MoveActiveBrick( const COrientation::Direction direction = COrientation::Direction::D );
	void m_ReleaseBrick( const std::string& brickType );
	void m_ShowWindow();
	void m_ShowBrick();
	CGame();
	virtual ~CGame();
	
	bool m_roundInProgress;

	CMainGrid mainGrid;
	CBrick* m_activeBrick;
	static CGame* s_instance;

};

#endif