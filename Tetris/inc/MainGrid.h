#ifndef __MAIN_GRID_Y__
#define __MAIN_GRID_Y__

#include <vector>
#include "Utils.h"
#include "Slab.h"
#include "Brick.h"
#include "Picture.h"

/*
 * @brief This class manages main grid operations. 
 */
class CMainGrid
{
public:
	CMainGrid( );
	virtual ~CMainGrid();
	/*
	 * @brief Sets size of grid. 
	 * @param[in] CUInt rowsCount size in rows.
	 * @param[in] CUInt columnsCount size in columns.
	 * @param[in] CUInt initialX - offset in x. 
	 * @param[in] CUInt initialy - offset in y. 
	 */
	void SetSize( CUInt rowsCount, CUInt columnsCount, CUInt initialX = 0,  CUInt initialY = 0 );
	/*
	 * @brief Sets background Picture. 
	 * @param[in] Path picLocation - location of picture. 
	 * @param[in] CUInt width - width of picture. 
	 * @param[in] CUInt height - height of picture. 
	 */
	void SetBackgroundPicture( const Path picLocation, CUInt width, CUInt height );
	/*
	 * @brief Sets slab picture. 
	 * @param[in] Path picLocation - location of picture. 
	 * @param[in] CUInt width - width of picture. 
	 * @param[in] CUInt height - height of picture. 
	 */
	void SetSlabPic( const Path picLocation, CUInt width, CUInt height );
	/*
	 * @brief Adds brick to not moving slab pool.  
	 * @param[in] Brick to be added.
	 */
	void AddBrick( const CBrick* brick );
	/*
	 * @brief Creates randomly a brick and puts it on grid. 
	 */
	void ReLeaseBrick();
	/*
	 * @brief Returns rows count. 
	 * @param[out] const unsigned int row count.
	 */
	CUInt GetRowsCount()const;
	/*
	 * @brief Returns columns count. 
	 * @param[out] const unsigned int columns count.
	 */
	CUInt GetColumnsCount()const;
	/*
	 * @brief Returns slab picture location. 
	 * @param[out] const std:: string location of slab picture.
	 */
	const String SlabPictureLoc()const;
	/*
	 * @brief Returns empty slab picture location. 
	 * @param[out] const std:: string location of empty slab picture.
	 */
	const String EmptySlabPictureLoc()const;
	/*
	 * @brief Returns image width. 
	 * @param[out] const unsigned int image wdith. 
	 */
	CUInt GetImgWidth()const;
	/*
	 * @brief Returns image height. 
	 * @param[out] const unsigned int image wdith. 
	 */
	CUInt GetImgHeight()const;
	/*
	 * @brief Returns selected slab row. 
	 * @param[in] const unsigned int slab index. 
	 * @param[out] const unsigned int slab row. 
	 */
	CUInt GetSlabRow( CUInt slabIndex )const;
	/*
	 * @brief Returns selected slab column. 
	 * @param[in] const unsigned int slab index. 
	 * @param[out] const unsigned int slab column. 
	 */
	CUInt GetSlabCol( CUInt slabIndex )const;
	/*
	 * @brief Checks if slab is a part of brick. 
	 * @param[in] const unsigned int slab index. 
	 * @param[out] bool true if is a part of brick. 
	 */
	const bool PartOfSlab( CUInt slabIndex )const;
	/*
	 * @brief Checks if slab is empty. 
	 * @param[in] const unsigned int slab row. 
	 * @param[in] const unsigned int slab column. 
	 * @param[out] bool true if is a part of brick. 
	 */
	const bool Empty( CUInt rowIndex, CUInt colIndex )const;
	/*
	 * @brief Returns slab count. 
	 * @param[out] const unsigned int count of slabs. 
	 */
	CUInt SlabCount()const;
	/*
	 * @brief Gets active brick coordinates. 
	 * @param[out] vector of coordinates. 
	 */
	const CoordinatestList ActiveBrickCoords()const;
	/*
	 * @brief Checks if selected slab exist. 
	 * @param[in] const unsigned int slab row. 
	 * @param[in] const unsigned int slab column. 
	 * @param[out] bool true if slab exist. 
	 */
	const bool SlabExist( CUInt rowIndex, CUInt colIndex )const;
	/*
	 * @brief Converts current brick to main grid slabs. 
	 */
	void AddCurrentBrickToGrid();
	/*
	 * @brief Checks if selected slab is part of brick. 
	 * @param[in] const unsigned int slab row. 
	 * @param[in] const unsigned int slab column. 
	 * @param[out] bool true if slab is a part of brick. 
	 */
	const bool PartOfCurrentBrick( CUInt rowIndex, CUInt colIndex )const;
	/*
	 * @brief Moves actual brick in selected direction. 
	 * @param[in] direction of move. 
	 */
	void MoveActualBrick( const Direction direction );
	/*
	 * @brief Check if block is movable. 
	 * @param[in] direction of move.. 
	 */
	const bool CheckIfBlockCanBeMoved( const Direction direction )const;
	/*
	 * @brief Rotates brick. 
	 * @param[in] bool rotation direction. 
	 */
	void RotateActualBrick( const bool clockWise = true );
	/*
	 * @brief Checks for full lines and manages them. 
	 */
	void ManageFullLine();

private:
	/*
	 * @brief converts row and column indexes to slab index. 
	 */
	CUInt m_RowColToSlabIndex( CUInt rowIndex, CUInt colIndex )const;
	void m_MoveActualBlock( const Direction direction );
	void m_RemoveActualBlockSlabsFromGrid();
	void m_SetToSlab( CUInt slabIndex );
	const bool m_LineIsFull( CUInt rowIndex )const;
	const bool m_CheckIfBlockCanBePlaced( const CBrick* brick );
	void m_MoveDownAllLines( CUInt toLineIndex );
	CBrick* m_activeBrick;
	std::vector<CSlab> m_slab;
	UInt m_columnsCount;
	UInt m_rowsCount;
	CPicture m_slabBackground;
	CPicture m_brickBckd;
};

#endif
