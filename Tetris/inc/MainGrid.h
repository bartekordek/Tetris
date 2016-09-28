#pragma once 

#include <vector>
#include <mutex>

#include "Slab.h"
#include "Brick.h"
#include "Picture.h"

namespace Tetris
{
	class CGame;
	using SlabRow = std::vector<CSlab>;
	class CMainGrid
	{
	public:
		CMainGrid();
		virtual ~CMainGrid();
		void updateGrid();
		void SetSize( CUInt rowsCount, CUInt columnsCount, CUInt initialX = 0, CUInt initialY = 0 );
		
		void ReLeaseBrick();
		void MoveActualBrick( const Direction direction );
		void RotateActualBrick( const bool clockWise = true );

	private:
		void AddBrick( const CBrick* brick );
		const bool SlabExist( CUInt rowIndex, CUInt colIndex )const;
		const bool PartOfCurrentBrick( CUInt rowIndex, CUInt colIndex )const;
		const bool CheckIfBlockCanBeMoved( const Direction direction );
		void addCurrentBrickToGrid();
		void ManageFullLine();
		CInt GetColOffset( const Direction direction )const;
		CInt GetRowOffset( const Direction direction )const;
		CUInt m_RowColToSlabIndex( CUInt rowIndex, CUInt colIndex )const;
		void moveCurrentBrick( const Direction direction );
		void m_RemoveActualBlockSlabsFromGrid();
		void MarkSlabAsPartOfMovingBlock( CUInt row, CUInt col );
		const bool RowIsConnected( const SlabRow& slabRow )const;
		const bool m_CheckIfBlockCanBePlaced( const CBrick* brick );
		void MoveAllLinesOneLineDown( std::vector<SlabRow>::iterator rowIterator );
		void SetSlabImagSurface( CSlab& slab );

		CGame* mGamePtr = nullptr;

		CBrick* m_activeBrick;
		std::vector<SlabRow> mSlabsRows;
		UInt m_columnsCount;
		UInt m_rowsCount;
		CPicture m_slabBackground;
		CPicture m_brickBckd;
		std::mutex slabsMutex;
		std::mutex currentBrickMutex;
		Moge::ImageSurface mEmptySlabImage;
		Moge::ImageSurface mFilledSlabImage;
	};
}