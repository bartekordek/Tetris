#include "MainGrid.h"
#include "BrickFactory.h"
#include <boost/foreach.hpp>

CMainGrid::CMainGrid( CUInt rowsCount, 
					  CUInt columnsCount, 
					  CUInt initialX, 
					  CUInt initialY )
{
	//SetSize( rowsCount, columnsCount, initialX, initialY );
}

CMainGrid::~CMainGrid()
{
}

void CMainGrid::SetSize( CUInt rowsCount,
						 CUInt columnsCount, 
						 CUInt initialX, 
						 CUInt initialY )
{
	m_slab.erase( m_slab.begin(), m_slab.end() );
	m_columnsCount = columnsCount;
	m_rowsCount = rowsCount;
	for( UInt i = 0; i < m_rowsCount; ++i )
	{
		for( UInt j = 0; j < m_columnsCount; ++j )
		{
			CSlab slab( j + initialX, i + initialY, false, true );
			m_slab.push_back( slab );
		}
	}
}

void CMainGrid::SetBackgroundPicture( const Path& picLocation, CUInt width, CUInt height )
{
	m_slabBackground = CPicture( picLocation, width, height );
}

void CMainGrid::SetSlabPic( const Path& picLocation, CUInt width, CUInt height )
{
	m_brickBckd = CPicture( picLocation, width, height );
}

void CMainGrid::ReLeaseBrick()
{
	m_activeBrick = CBrickFactory::GetRandomBrick();
	AddBrick( *m_activeBrick );
}

void CMainGrid::AddBrick( const CBrick& brick )
{
	CoordinatestList& coords = brick.GetBlockPositions();
	for( auto it = coords.begin(); it != coords.end(); ++it )
	{
		m_SetToSlab( m_RowColToSlabIndex( it->GetRow(), it->GetCol() ) );
	}
}

void CMainGrid::AddCurrentBrickToGrid()
{
	if( NULL != m_activeBrick )
	{
		CoordinatestList coords = m_activeBrick->GetBlockPositions();
		for( auto it = coords.begin(); it != coords.end(); ++it )
		{
			m_slab.at( m_RowColToSlabIndex( it->GetRow(), it->GetCol() ) ).Empty(false);
		}
		delete m_activeBrick;
	}
}

void CMainGrid::m_SetToSlab( CUInt slabIndex )
{
	m_slab.at( slabIndex ).PartOfSlab( true );
	m_slab.at( slabIndex ).Empty( false );
}

CUInt CMainGrid::GetRowsCount()const
{
	return m_rowsCount;
}

CUInt CMainGrid::GetColumnsCount()const
{
	return m_columnsCount;
}

const String CMainGrid::SlabPictureLoc()const
{
	return m_slabBackground.GetImgLoc();
}

const String CMainGrid::EmptySlabPictureLoc()const
{
	return m_brickBckd.GetImgLoc();
}

CUInt CMainGrid::GetImgWidth()const
{
	return 10;
}

CUInt CMainGrid::GetImgHeight()const
{
	return 10;
}

CUInt CMainGrid::GetSlabRow( CUInt slabIndex )const
{
	return m_slab.at( slabIndex ).Row();
}

CUInt CMainGrid::GetSlabCol( CUInt slabIndex )const
{
	return m_slab.at( slabIndex ).Col();
}

const bool CMainGrid::PartOfSlab( CUInt slabIndex )const
{
	return m_slab[slabIndex].PartOfSlab();
}

const bool CMainGrid::Empty( CUInt rowIndex, CUInt colIndex )const
{
	return m_slab.at( m_RowColToSlabIndex( rowIndex, colIndex ) ).Empty();
}

CUInt CMainGrid::SlabCount()const
{
	return GetRowsCount()*GetColumnsCount();
}

const CoordinatestList CMainGrid::ActiveBrickCoords()const
{
	CoordinatestList coords = m_activeBrick->GetBlockPositions();
	return coords;
}

const bool CMainGrid::SlabExist( CUInt rowIndex, CUInt colIndex )const
{
	if( colIndex >= m_columnsCount || rowIndex >= m_rowsCount )
	{
		return false;
	}
	if( m_RowColToSlabIndex(rowIndex, colIndex ) < m_slab.size() )
	{
		return true;
	}
	return false;
}

CUInt CMainGrid::m_RowColToSlabIndex( CUInt rowIndex, CUInt colIndex )const
{
	return rowIndex*m_columnsCount + colIndex;
}

const bool CMainGrid::PartOfCurrentBrick( CUInt rowIndex, CUInt colIndex )const
{
	CoordinatestList coords = m_activeBrick->GetBlockPositions();
	for( auto it = coords.begin(); it != coords.end(); ++it )
	{
		if( it->GetRow() == rowIndex && it->GetCol() == colIndex )
		{
			return true;
		}
	}
	return false;
}

void CMainGrid::MoveActualBrick( const Direction direction )
{
	if( Direction::U == direction )
	{

	}
	else if( Direction::D == direction )
	{

	}
	else if( Direction::R == direction )
	{

	}
	else if( Direction::L == direction )
	{

	}
}

const bool CMainGrid::CheckIfBlockCanBeMoved( const Direction direction )const
{
	CoordinatestList blockCoords = ActiveBrickCoords();
	int RowDiff;
	int ColDiff;
	if( Direction::U == direction )
	{
		ColDiff = 0;
		RowDiff = -1;
	}
	else if( Direction::D == direction )
	{
		ColDiff = 0;
		RowDiff = 1;
	}
	else if( Direction::R == direction )
	{
		ColDiff = 1;
		RowDiff = 0;
	}
	else if( Direction::L == direction )
	{
		ColDiff = -1;
		RowDiff = 0;
	}

	for( auto it = blockCoords.begin(); it != blockCoords.end(); ++it )
	{
		CUInt actRow = it->GetRow();
		CUInt actCol = it->GetCol();
		if( false == SlabExist( actRow + RowDiff, actCol + ColDiff ) ) // Check if you are not in the bottom
		{
			return false;
		}

		if( true == PartOfCurrentBrick( actRow + RowDiff, actCol + ColDiff ) )
		{
			continue;
		}

		if( false == Empty( actRow + RowDiff, actCol + ColDiff ) )
		{
			return false;
		}
	}
	return true;
}