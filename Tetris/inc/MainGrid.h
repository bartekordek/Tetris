#ifndef __MAIN_GRID_Y__
#define __MAIN_GRID_Y__

#include <vector>
#include "Utils.h"
#include "Slab.h"
#include "Brick.h"
#include "Picture.h"

class CMainGrid
{
public:
	CMainGrid( CUInt rowsCount = 0, CUInt columnsCount = 0, CUInt initialX = 0, CUInt initialY = 0 );
	virtual ~CMainGrid();
	void SetSize( CUInt rowsCount, CUInt columnsCount, CUInt initialX = 0,  CUInt initialY = 0 );
	void SetBackgroundPicture( const Path& picLocation, CUInt width, CUInt height );
	void SetSlabPic( const Path& picLocation, CUInt width, CUInt height );
	void AddBrick( const CBrick& brick );
	void ReLeaseBrick();

	CUInt GetRowsCount()const;
	CUInt GetColumnsCount()const;
	const String SlabPictureLoc()const;
	const String EmptySlabPictureLoc()const;
	CUInt GetImgWidth()const;
	CUInt GetImgHeight()const;
	CUInt GetSlabRow( CUInt slabIndex )const;
	CUInt GetSlabCol( CUInt slabIndex )const;
	const bool PartOfSlab( CUInt slabIndex )const;
	const bool Empty( CUInt rowIndex, CUInt colIndex )const;
	CUInt SlabCount()const;
	const CoordinatestList ActiveBrickCoords()const;
	const bool SlabExist( CUInt rowIndex, CUInt colIndex )const;
	void AddCurrentBrickToGrid();
	const bool PartOfCurrentBrick( CUInt rowIndex, CUInt colIndex )const;
	void MoveActualBrick( const Direction direction );
	const bool CheckIfBlockCanBeMoved( const Direction direction )const;

private:
	CUInt m_RowColToSlabIndex( CUInt rowIndex, CUInt colIndex )const;
	void m_MoveActualBlock( const Direction direction );
	void m_RemoveActualBlockSlabsFromGrid();
	void m_SetToSlab( CUInt slabIndex );
	CBrick* m_activeBrick;
	std::vector<CSlab> m_slab;
	UInt m_columnsCount;
	UInt m_rowsCount;
	CPicture m_slabBackground;
	CPicture m_brickBckd;
};

#endif