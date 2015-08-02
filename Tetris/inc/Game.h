#ifndef __GAME_Z__
#define __GAME_Z__

#include <thread>

#include "MainGrid.h"
#include "Brick.h"
#include "Utils.h"
#include "Button.h"
#include "EventHandler.h"

/*
 * @brief Main game class. 
 * @details manages operation on different objects. This class is singleton.
 */
class CGame
{
public:
	static CGame* Instance();
	static void Destroy();
	/*
	 * @brief Basic initialization: sets main grid size and sets pictures.
	 * @param[in] const unsigned int - size in rows.
	 * @param[in] const unsigned int - size in col.
	 */
	void Initialize( CUInt rowsCount = 50, CUInt columnsCount = 10 );
	/*
	* @brief Initializes main game window.
	* @param[in] const unsigned int - window width.
	* @param[in] const unsigned int - window height.
	*/
	void InitWindow( CUInt width = 600, CUInt height = 400 );
	/*
	 * @brief Displays main grid.
	 */
	void ShowGrid();
	/*
	 * @brief Main loop method, handles events graphics and logic.
	 */
	void MainLoop();
	/*
	 * @brief Start game method. 
	 */
	void StartGame();
	/*
	 * @brief loads block background image. 
	 */
	void SetMainGridBlockBackgroundImage();
	/*
	 * @brief loads slab background image. 
	 */
	void SetMainGridSlabBackgroundImage();

	/*
	 * @brief quits the game. 
	 */
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
	CGame();
	
	bool m_roundInProgress;

	CMainGrid* m_mainGrid;
	static CGame* s_instance;
	std::thread* mainLoopThread;

	bool m_quit;
};

void QuitGame();

#endif
