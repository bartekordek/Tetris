#pragma once 

#include <vector>
#include <mutex>

#include "Utilities.h"
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
		void SetSize( CUInt rowsCount, CUInt columnsCount, CUInt initialX = 0, CUInt initialY = 0 );
		void SetBackgroundPicture( const Path picLocation, CUInt width, CUInt height );
		void SetSlabPic( const Path picLocation, CUInt width, CUInt height );
		void AddBrick( const CBrick* brick );
		void ReLeaseBrick();
		CUInt GetRowsCount()const;
		CUInt GetColumnsCount()const;
		const Path SlabPictureLoc()const;
		const Path EmptySlabPictureLoc()const;
		const bool PartOfSlab( CUInt rowIndex, CUInt colIndex )const;
		const bool Empty( CUInt rowIndex, CUInt colIndex )const;
		CUInt SlabCount()const;
		const bool SlabExist( CUInt rowIndex, CUInt colIndex )const;
		CBrick* GetCurrentBrick();
		const bool PartOfCurrentBrick( CUInt rowIndex, CUInt colIndex )const;
		void MoveActualBrick( const Direction direction );
		const bool CheckIfBlockCanBeMoved( const Direction direction )const;
		void RotateActualBrick( const bool clockWise = true );
		void ManageFullLine();
		void SetGamePtr( CGame* game );
		std::vector<SlabRow>& GetSlabs();

		CSlab& GetSlab( CUInt row, CUInt column );

	private:
		CInt GetColOffset( const Direction direction )const;
		CInt GetRowOffset( const Direction direction )const;
		CUInt m_RowColToSlabIndex( CUInt rowIndex, CUInt colIndex )const;
		void m_MoveActualBlock( const Direction direction );
		void m_RemoveActualBlockSlabsFromGrid();
		void MarkSlabAsPartOfMovingBlock( CUInt row, CUInt col );
		const bool m_LineIsFull( CUInt rowIndex )const;
		const bool m_CheckIfBlockCanBePlaced( const CBrick* brick );
		void m_MoveDownAllLines( CUInt toLineIndex );

		CGame* mGamePtr = nullptr;

		CBrick* m_activeBrick;
		std::vector<SlabRow> mSlabsRows;
		UInt m_columnsCount;
		UInt m_rowsCount;
		CPicture m_slabBackground;
		CPicture m_brickBckd;
		std::mutex slabsMutex;
	};
}