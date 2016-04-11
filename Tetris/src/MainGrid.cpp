#include "MainGrid.h"
#include "BrickFactory.h"
#include <boost/foreach.hpp>

CMainGrid::CMainGrid():m_activeBrick(NULL)
{
}

CMainGrid::~CMainGrid()
{
	delete m_activeBrick;
}

void CMainGrid::SetSize( CUInt rowsCount, CUInt columnsCount,  CUInt initialX, CUInt initialY )
{
	m_slabs.erase( m_slabs.begin(), m_slabs.end() );
	m_columnsCount = columnsCount;
	m_rowsCount = rowsCount;
	for( UInt row = 0; row < m_rowsCount; ++row )
	{
		for( UInt col = 0; col < m_columnsCount; ++col )
		{
			CSlab slab( row + initialY, col + initialX, false, true );
			slab.SetId( m_RowColToSlabIndex( slab.Row(), slab.Col() ) );
			m_slabs.push_back( slab );
		}
	}
}

void CMainGrid::SetBackgroundPicture( const Path location, CUInt width, CUInt height )
{
	m_slabBackground = CPicture( location, width, height );
}

void CMainGrid::SetSlabPic( const Path picLocation, CUInt width, CUInt height )
{
	m_brickBckd = CPicture( picLocation, width, height );
}

void CMainGrid::ReLeaseBrick()
{
	delete m_activeBrick;
	m_activeBrick = CBrickFactory::GetRandomBrick();
	AddBrick( m_activeBrick );
}

void CMainGrid::AddBrick( const CBrick* brick )
{
	CoordinatestList coords = brick->GetBlockPositions();
	for( auto it = coords.begin(); it != coords.end(); ++it )
	{
		CUInt row = it->Row();
		CUInt col = it->Col();
		m_SetToSlab( m_RowColToSlabIndex( row, col ) );
	}
}

void CMainGrid::m_SetToSlab( CUInt slabIndex )
{
	m_slabs.at( slabIndex ).PartOfSlab( true );
	m_slabs.at( slabIndex ).Empty( false );
}

CUInt CMainGrid::GetRowsCount()const
{
	return m_rowsCount;
}

CUInt CMainGrid::GetColumnsCount()const
{
	return m_columnsCount;
}

const Path CMainGrid::SlabPictureLoc()const
{
	return m_slabBackground.GetImgLoc();
}

const Path CMainGrid::EmptySlabPictureLoc()const
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
	return m_slabs.at( slabIndex ).Row();
}

CUInt CMainGrid::GetSlabCol( CUInt slabIndex )const
{
	return m_slabs.at( slabIndex ).Col();
}

const bool CMainGrid::PartOfSlab( CUInt slabIndex )const
{
	return m_slabs[slabIndex].PartOfSlab();
}

const bool CMainGrid::Empty( CUInt rowIndex, CUInt colIndex )const
{
	return m_slabs.at( m_RowColToSlabIndex( rowIndex, colIndex ) ).Empty();
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
	CInt RowDiff = GetRowOffset(direction);
	CInt ColDiff = GetColOffset(direction);

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

CInt CMainGrid::GetColOffset( const Direction direction )const
{
	if( Direction::U == direction )
	{
		return 0;
	}
	else if( Direction::D == direction )
	{
		return 0;
	}
	else if( Direction::R == direction )
	{
		return 1;
	}
	else if( Direction::L == direction )
	{
		return  -1;
	}
	return -1;
}

CInt CMainGrid::GetRowOffset( const Direction direction )const
{
	if( Direction::U == direction )
	{
		return  0;
	}
	else if( Direction::D == direction )
	{
		return  1;
	}
	else if( Direction::R == direction )
	{
		return  0;
	}
	else if( Direction::L == direction )
	{
		return  0;
	}
	return -1;
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
	if( true == m_CheckIfBlockCanBePlaced( tempBrick ) )
	{
		m_RemoveActualBlockSlabsFromGrid();
		m_activeBrick->Rotate( clockWise );
	}
	delete tempBrick;
}

const bool CMainGrid::m_CheckIfBlockCanBePlaced( const CBrick* brick )
{
	CoordinatestList coords = brick->GetBlockPositions();
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

const bool CMainGrid::SlabExist( CUInt rowIndex, CUInt colIndex )const
{
	if( colIndex >= m_columnsCount || rowIndex >= m_rowsCount )
	{
		return false;
	}

	CSlab slab = m_slabs[m_RowColToSlabIndex( rowIndex, colIndex )];

	if( true == slab.Empty() || true == slab.PartOfSlab() )
	{
		return true;
	}
	return false;
}

void CMainGrid::m_RemoveActualBlockSlabsFromGrid()
{
	CoordinatestList coords = m_activeBrick->GetBlockPositions();
	for( auto it = coords.begin(); it != coords.end(); ++it )
	{
		CUInt row = it->Row();
		CUInt col = it->Col();
		m_slabs.at( m_RowColToSlabIndex( row, col ) ).Empty( true );
		m_slabs.at( m_RowColToSlabIndex( row, col ) ).PartOfSlab( false );
	}
}

void CMainGrid::m_MoveActualBlock( const Direction direction )
{
	m_activeBrick->Move( direction );
	AddBrick( m_activeBrick );
}


CBrick* CMainGrid::GetCurrentBrick()
{
	return m_activeBrick;
}

void CMainGrid::ManageFullLine()
{
	for( UInt i = 0; i < m_rowsCount; ++i )
	{
		if( m_LineIsFull( i ) )
		{
			m_MoveDownAllLines(i);
		}
	}
}

std::vector<CSlab>& CMainGrid::GetSlabs()
{
	return m_slabs;
}

CSlab& CMainGrid::GetSlab( CUInt row, CUInt column )
{
	return m_slabs.at( m_RowColToSlabIndex( row, column ) );
}

const bool CMainGrid::m_LineIsFull( CUInt rowIndex )const
{
	for( UInt i = 0; i < m_columnsCount; ++i )
	{
		if( true == m_slabs.at( m_RowColToSlabIndex( rowIndex, i ) ).Empty() )
		{
			return false;
		}
	}
	return true;
}

void CMainGrid::m_MoveDownAllLines( CUInt toLineIndex )
{
	for( UInt i = toLineIndex; i > 1; --i )
	{
		for( UInt j = 0; j < m_columnsCount; ++j )
		{
			bool emptiness = m_slabs.at( m_RowColToSlabIndex( i - 1, j ) ).Empty();
			bool partOfBlock = m_slabs.at( m_RowColToSlabIndex( i - 1, j ) ).PartOfSlab();
			m_slabs.at( m_RowColToSlabIndex( i, j ) ).Empty( emptiness );
			m_slabs.at( m_RowColToSlabIndex( i, j ) ).PartOfSlab( partOfBlock );
		}
	}
	for( UInt j = 0; j < m_columnsCount; ++j )
	{
		m_slabs.at( m_RowColToSlabIndex( 0, j ) ).Empty( true );
	}
}

CUInt CMainGrid::m_RowColToSlabIndex( CUInt rowIndex, CUInt colIndex )const
{
	return rowIndex*m_columnsCount + colIndex;
}
