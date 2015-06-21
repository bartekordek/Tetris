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
	 * @brief Main loop method.
	 */
	void MainLoop();
	void StartGame();
	void SetMainGridBlockBackgroundImage();
	void SetMainGridSlabBackgroundImage();
	void SetWindowColor();
	void AddButton( CUInt x, CUInt y, String name, Path path );
	void QuitGame();
	CEventHandler eventHandler;

private:
	void m_SetGameSize( CUInt rows, CUInt columns );
	void m_MoveActiveBrick( const Direction direction = Direction::D );
	void m_RotateActualBrick( const bool clockWise = true );
	void m_ReleaseBrick();
	void m_ShowWindow();
	void m_ActualizeGrid( const CMainGrid& grid );
	void m_AddCurrentBrickToGrid();
	void m_StartEventPoolThread();
	void m_MainLoopThread();
	void m_WaitForMove();
	void m_CheckForFullLines();
	String m_GetQuitButtonLocation();
	CGame();
	virtual ~CGame();
	
	bool m_roundInProgress;

	CMainGrid mainGrid;
	static CGame* s_instance;
	Vector<CButton> m_buttons;
	std::thread* eventPoolThread;
	std::thread* mainLoopThread;
};

void QuitGame();
void EventPoolFunction();

#endif