#ifndef __GAME_Z__
#define __GAME_Z__

#include "MainGrid.h"
#include "Brick.h"
#include "Utils.h"

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
	void InitWindow( CUInt width = 800, CUInt height = 600 );
	/*
	 * @brief Initializes main game window.
	 * @param[in] const unsigned int - size in rows.
	 * @param[in] const unsigned int - size in col.
	 */
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
	void m_AddCurrentBrickToGrid();
	CGame();
	virtual ~CGame();
	
	bool m_roundInProgress;

	CMainGrid mainGrid;
	static CGame* s_instance;

};

#endif