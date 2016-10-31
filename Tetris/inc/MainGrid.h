#pragma once 

#include <vector>
#include <mutex>

#include "Slab.h"
#include "Brick.h"
#include "Picture.h"

namespace Tetris
{
using SlabRow = std::vector<Slab>;
class CMainGrid
{
public:
	CMainGrid();
	virtual ~CMainGrid();
	void updateGrid();
	void SetSize( CUInt rowsCount, CUInt columnsCount, CUInt initialX = 0, CUInt initialY = 0 );
		
	void ReLeaseBrick();
	void MoveActualBrick( const Moge::Math::Directions direction );
	void RotateActualBrick( const bool clockWise = true );

private:
	void AddBrick( const Brick* brick );
	const bool SlabExist( CUInt rowIndex, CUInt colIndex )const;
	const bool PartOfCurrentBrick( CUInt rowIndex, CUInt colIndex )const;
	const bool checkIfBlockCanBeMoved( const Moge::Math::Directions direction );
	const bool checkIfBlockCanBeRotated( const bool clockWise = true );
	void addCurrentBrickToGrid();
	void ManageFullLine();
	CInt GetColOffset( const Moge::Math::Directions direction )const;
	CInt GetRowOffset( const Moge::Math::Directions direction )const;
	void moveCurrentBrick( const Moge::Math::Directions direction );
	void m_RemoveActualBlockSlabsFromGrid();
	void MarkSlabAsPartOfMovingBlock( CUInt row, CUInt col );
	const bool RowIsConnected( const SlabRow& slabRow )const;
	const bool m_CheckIfBlockCanBePlaced( const Brick* brick );
	void MoveAllLinesOneLineDown( std::vector<SlabRow>::iterator rowIterator );
	void SetSlabImagSurface( Slab& slab );

	Brick* activeBrick;
	std::vector<SlabRow> slabsRows;
	CPicture slabBackground;
	CPicture brickBckd;
	std::mutex slabsMutex;
	std::mutex currentBrickMutex;
	Moge::ImageSurface emptySlabImage;
	Moge::ImageSurface filledSlabImage;
};
}