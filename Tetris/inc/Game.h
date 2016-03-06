#ifndef __GAME_Z__
#define __GAME_Z__

#include "MainGrid.h"
#include "Brick.h"
#include "Utilities.h"
#include "Engine.h"
//#include "SDLWrapper.h"

struct Resolution
{
	Resolution( const unsigned int width, const unsigned int height ):
		width( width ),
		height( height )
	{

	}
	unsigned int width;
	unsigned int height;
};

class CGame
{
public:
	CGame();
	void Initialize( CUInt rowsCount = 50, CUInt columnsCount = 10, const Resolution& resoltion = Resolution( 640, 480 ) );
	void ShowGrid();
	void MainLoop();
	void StartGame();
	void QuitGame();
	virtual ~CGame();

private:
	void SetMainGridEmptySlabImage();
	void SetMainGridFilledSlabImage();
	void CreateGrid();
	const bool QuitHasBeenHit( const SDL_Event event );
	const bool IsKeyDown( const SDL_Event event );
	void HandleKeys( SDLKey sdlkey );
	void SetMainGridSize( CUInt rows, CUInt columns );
	void MoveActiveBrick( const Direction direction = Direction::D );
	void RotateActualBrick( const bool clockWise = true );
	void ReleaseBrick();
	void ActualizeGrid();
	void AddCurrentBrickToGrid();
	void MainLoopThread();
	void WaitForMove();
	void CheckForFullLines();

	MOGE::ImagePtr mEmptySlabImage;
	MOGE::ImagePtr mFilledSlabImage;

	Vector<MOGE::NodePtr> slabs;

	String GetQuitButtonLocation();
	CMainGrid m_mainGrid;
	Thread m_mainLoopThread;
	bool m_roundInProgress;
	bool m_quit;

	std::string emptySlabName = "emptySlab";
	std::string slabName = "slab";
};
#endif 
