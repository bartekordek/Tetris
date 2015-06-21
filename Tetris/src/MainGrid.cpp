#include "MainGrid.h"
#include "BrickFactory.h"
#include <boost/foreach.hpp>

CMainGrid::CMainGrid( CUInt rowsCount, CUInt columnsCount, CUInt initialX, CUInt initialY )
{
	//SetSize( rowsCount, columnsCount, initialX, initialY );
}

CMainGrid::~CMainGrid()
{
}

void CMainGrid::SetSize( CUInt rowsCount, CUInt columnsCount,  CUInt initialX, CUInt initialY )
{
	m_slab.erase( m_slab.begin(), m_slab.end() );
	m_columnsCount = columnsCount;
	m_rowsCount = rowsCount;
	for( UInt row = 0; row < m_rowsCount; ++row )
	{
		for( UInt col = 0; col < m_columnsCount; ++col )
		{
			CSlab slab( row + initialY, col + initialX, false, true );
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
		CUInt row = it->Row();
		CUInt col = it->Col();
		m_SetToSlab( m_RowColToSlabIndex( row, col ) );
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

const bool CMainGrid::PartOfCurrentBrick( CUInt rowIndex, CUInt colIndex )const
{
	CoordinatestList coords = m_activeBrick->GetBlockPositions();
	for( auto it = coords.begin(); it != coords.end(); ++it )
	{
		if( it->Row() == rowIndex && it->Col() == colIndex )
		{
			return true;
		}
	}
	return false;
}

void CMainGrid::MoveActualBrick( const Direction direction )
{
	if( true == CheckIfBlockCanBeMoved( direction ) )
	{
		m_RemoveActualBlockSlabsFromGrid();
		m_MoveActualBlock( direction );
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
		CUInt actRow = it->Row();
		CUInt actCol = it->Col();
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

void CMainGrid::RotateActualBrick( const bool clockWise )
{
	CBrick* tempBrick;
	if( m_activeBrick->GetBlockType() == BrickTypes::L )
	{
		tempBrick = new CLBrick( *dynamic_cast< CLBrick* >(m_activeBrick ) );
	}
	else if( m_activeBrick->GetBlockType() == BrickTypes::I )
	{
		tempBrick = new CIBrick( *dynamic_cast< CIBrick* >( m_activeBrick ) );
	}
	else if( m_activeBrick->GetBlockType() == BrickTypes::O )
	{
		tempBrick = new COBrick( *dynamic_cast< COBrick* >( m_activeBrick ) );
	}
	else if( m_activeBrick->GetBlockType() == BrickTypes::S )
	{
		tempBrick = new CSBrick( *dynamic_cast< CSBrick* >( m_activeBrick ) );
	}
	else
	{
		tempBrick = new CTBrick( *dynamic_cast< CTBrick* >( m_activeBrick ) );
	}

 	tempBrick->Rotate( clockWise );
	if( true == m_CheckIfBlockCanBePlaced( *tempBrick ) )
	{
		m_RemoveActualBlockSlabsFromGrid();
		m_activeBrick->Rotate( clockWise );
	}
	delete tempBrick;
}

const bool CMainGrid::m_CheckIfBlockCanBePlaced( const CBrick& brick )
{
	CoordinatestList coords = brick.GetBlockPositions();
	for( auto it = coords.begin(); it != coords.end(); ++it )
	{
		if( false == SlabExist( it->Row(), it->Col() ) )
		{
			return false;
		}

		if( true == PartOfCurrentBrick( it->Row(), it->Col() ) )
		{
			continue;
		}

		if( false == Empty( it->Row(), it->Col() ) )
		{
			return false;
		}
	}
	return true;
}

void CMainGrid::m_RemoveActualBlockSlabsFromGrid()
{
	CoordinatestList coords = m_activeBrick->GetBlockPositions();
	for( auto it = coords.begin(); it != coords.end(); ++it )
	{
		CUInt row = it->Row();
		CUInt col = it->Col();
		m_slab.at( m_RowColToSlabIndex( row, col ) ).Empty( true );
		m_slab.at( m_RowColToSlabIndex( row, col ) ).PartOfSlab( false );
	}
}

void CMainGrid::m_MoveActualBlock( const Direction direction )
{
	m_activeBrick->Move( direction );
	AddBrick( *m_activeBrick );
}


void CMainGrid::AddCurrentBrickToGrid()
{
	if( NULL != m_activeBrick )
	{
		CoordinatestList coords = m_activeBrick->GetBlockPositions();
		for( auto it = coords.begin(); it != coords.end(); ++it )
		{
			m_slab.at( m_RowColToSlabIndex( it->Row(), it->Col() ) ).Empty( false );
		}
		delete m_activeBrick;
	}
}

CUInt CMainGrid::m_RowColToSlabIndex( CUInt rowIndex, CUInt colIndex )const
{
	return rowIndex*m_columnsCount + colIndex;
}