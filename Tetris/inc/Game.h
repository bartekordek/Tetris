#ifndef __GAME_Z__
#define __GAME_Z__

#include "MainGrid.h"
#include "Brick.h"
#include "Utilities.h"
#include "SDLWrapper.h"

class CGame
{
public:
	CGame();
	void Initialize( CUInt rowsCount = 50, CUInt columnsCount = 10 );
	void InitWindow( CUInt width = 600, CUInt height = 400 );
	void ShowGrid();
	void MainLoop();
	void StartGame();
	void QuitGame();
	virtual ~CGame();

private:
	void SetMainGridBlockBackgroundImage();
	void SetMainGridSlabBackgroundImage();
	const bool QuitHasBeenHit( const SDL_Event event );
	const bool IsKeyDown( const SDL_Event event );
	void HandleKeys( SDLKey sdlkey );
	void SetGameSize( CUInt rows, CUInt columns );
	void MoveActiveBrick( const Direction direction = Direction::D );
	void RotateActualBrick( const bool clockWise = true );
	void ReleaseBrick();
	void ActualizeGrid();
	void AddCurrentBrickToGrid();
	void MainLoopThread();
	void WaitForMove();
	void CheckForFullLines();

	String GetQuitButtonLocation();
	CMainGrid m_mainGrid;
	CSDLWrapper sdlWrapper;
	Thread m_mainLoopThread;
	bool m_roundInProgress;
	bool m_quit;
};
#endif 
