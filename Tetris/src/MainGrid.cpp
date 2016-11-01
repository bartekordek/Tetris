#include "Game.h"
#include "MainGrid.h"
#include "BrickFactory.h"
#include "NodeCreator.h"
#include "NodeImageCreator.h"
#include "MTime.h"

namespace Tetris
{
CMainGrid::CMainGrid():activeBrick( nullptr )
{
	std::lock_guard<std::mutex> slabLock( currentBrickMutex );
	Moge::Path blockImagepath = Moge::Path::GetCurrentDirectory() + "\\..\\..\\Media\\Block.bmp";
	filledSlabImage = Moge::ImageCreator::CreateSurfaceFromImage( blockImagepath );

	Moge::Path bgBlockImagepath = Moge::Path::GetCurrentDirectory() + "\\..\\..\\Media\\BackGroundBlock.bmp";
	emptySlabImage = Moge::ImageCreator::CreateSurfaceFromImage( bgBlockImagepath );
}

CMainGrid::~CMainGrid()
{
	slabsRows.erase( slabsRows.begin(), slabsRows.end() );
}

void CMainGrid::updateGrid()
{
	if( false == checkIfBlockCanBeMoved( Moge::Math::Directions::D ) )
	{
		addCurrentBrickToGrid();
		ManageFullLine();
		ReLeaseBrick();
	}
	Moge::CTimeMod::SleepMiliSeconds( 500 );
	MoveActualBrick( Moge::Math::Directions::D );
}

void CMainGrid::SetSize( CUInt rowsCount, CUInt columnsCount, CUInt initialX, CUInt initialY )
{
	slabsRows.erase( slabsRows.begin(), slabsRows.end() );
	for( UInt row = 0; row < rowsCount; ++row )
	{
		SlabRow rows;
		for( UInt col = 0; col < columnsCount; ++col )
		{
			Slab slab( row + initialY, col + initialX, true );
			rows.push_back( slab );
		}
		slabsRows.push_back( rows );
	}

	for( auto& slabRow : slabsRows )
	{
		for( auto& slab : slabRow )
		{
			std::shared_ptr<Moge::ObjectNodeContent> slabNode = Moge::NodeCreator::CreateFromImage( emptySlabImage );
			Moge::Math::IPositionAdapter<int> position( slab.col() * slabNode->getWidth(), slab.row() * slabNode->getHeight(), 0 );
			slabNode->setXyz( position.getX(), position.getY(), 0 );
			slab.SetNode( slabNode );

			slabNode->SetVisible();
			Moge::Engine::Instance().AddObject( slabNode );//TODO: redundant add, should be moved to NodeMgr
		}
	}
}

void CMainGrid::ReLeaseBrick()
{
	delete activeBrick;
	activeBrick = CBrickFactory::GetRandomBrick();
	AddBrick( activeBrick );
}

void CMainGrid::AddBrick( const Brick* brick )
{
	const CoordinatestList coords = brick->getBlockPositions();
	for( auto it = coords.begin(); it != coords.end(); ++it )
	{
		MarkSlabAsPartOfMovingBlock( it->getRow(), it->getCol() );
	}
}

void CMainGrid::MarkSlabAsPartOfMovingBlock( CUInt row, CUInt col )
{
	if( row >= slabsRows.size() || ( slabsRows.size() > 0 && col > slabsRows.at( 0 ).size() ) )
	{
		return;
	}

	Slab& slab = slabsRows.at( row ).at( col );
	slab.Empty( false );
	auto slabNode = slab.GetNode();
	slabNode->SetSurface( filledSlabImage );
}

const bool CMainGrid::PartOfCurrentBrick( CUInt rowIndex, CUInt colIndex )const
{
	CoordinatestList coords = activeBrick->getBlockPositions();
	for( auto it = coords.begin(); it != coords.end(); ++it )
	{
		if( it->getRow() == rowIndex && it->getCol() == colIndex )
		{
			return true;
		}
	}
	return false;
}

void CMainGrid::MoveActualBrick( const Moge::Math::Directions direction )
{
	if( true == checkIfBlockCanBeMoved( direction ) )
	{
		m_RemoveActualBlockSlabsFromGrid();
		moveCurrentBrick( direction );
	}
}

const bool CMainGrid::checkIfBlockCanBeMoved( const Moge::Math::Directions direction )
{
	for( auto& coord : activeBrick->getBlockPositions() )
	{
		CUInt newRow = coord.getRow() + GetRowOffset( direction );
		CUInt newCol = coord.getCol() + GetColOffset( direction );

		if( newRow >= slabsRows.size() )
		{
			return false;
		}

		if( false == SlabExist( newRow, newCol) ) 
		{
			return false;
		}

		if( true == PartOfCurrentBrick( newRow, newCol ) )
		{
			continue;
		}

		if( false == slabsRows.at( newRow ).at( newCol ).Empty() )
		{
			return false;
		}
	}
	return true;
}

CInt CMainGrid::GetColOffset( const Moge::Math::Directions direction )const
{
	if( Moge::Math::Directions::U == direction || Moge::Math::Directions::D == direction )
	{
		return 0;
	}

	if( Moge::Math::Directions::R == direction )
	{
		return 1;
	}
	if( Moge::Math::Directions::L == direction )
	{
		return  -1;
	}
	return -1;
}

CInt CMainGrid::GetRowOffset( const Moge::Math::Directions direction )const
{
	if( Moge::Math::Directions::U == direction )
	{
		return  0;
	}
	else if( Moge::Math::Directions::D == direction )
	{
		return  1;
	}
	else if( Moge::Math::Directions::R == direction )
	{
		return  0;
	}
	else if( Moge::Math::Directions::L == direction )
	{
		return  0;
	}
	return -1;
}

void CMainGrid::RotateActualBrick( const bool clockWise )
{
	Brick* tempBrick = new Brick( *activeBrick );
	tempBrick->rotate( clockWise );
	if( true == m_CheckIfBlockCanBePlaced( tempBrick ) )
	{
		m_RemoveActualBlockSlabsFromGrid();
		activeBrick->rotate( clockWise );
	}
	delete tempBrick;
}

void CMainGrid::addCurrentBrickToGrid()
{
	if( activeBrick )
	{
		for( auto& coord : activeBrick->getBlockPositions() )
		{
			Slab& slab = slabsRows.at( coord.getRow() ).at( coord.getCol() );
			slab.Empty( false );
			slab.GetNode().get()->SetSurface( filledSlabImage );
		}
	}
}

const bool CMainGrid::m_CheckIfBlockCanBePlaced( const Brick* brick )
{
	CoordinatestList coords = brick->getBlockPositions();
	for( auto it = coords.begin(); it != coords.end(); ++it )
	{

		if( it->getRow() >= slabsRows.size() )
		{
			return false;
		}
		if( false == SlabExist( it->getRow(), it->getCol() ) )
		{
			return false;
		}

		if( true == PartOfCurrentBrick( it->getRow(), it->getCol() ) )
		{
			continue;
		}

		if( false == slabsRows.at( it->getRow() ).at( it->getCol() ).Empty() )
		{
			return false;
		}
	}
	return true;
}

const bool CMainGrid::SlabExist( CUInt rowIndex, CUInt colIndex )const
{
	if( colIndex >= slabsRows.at( 0 ).size() || rowIndex >= slabsRows.size() )
	{
		return false;
	}
	return true;
}

void CMainGrid::m_RemoveActualBlockSlabsFromGrid()
{
	for( auto& coord : activeBrick->getBlockPositions() )
	{
		auto& slab = slabsRows.at( coord.getRow() ).at( coord.getCol() );
		slab.Empty( true );
		auto slabnode = slab.GetNode();
		slabnode->SetSurface( emptySlabImage );
	}
}

void CMainGrid::moveCurrentBrick( const Moge::Math::Directions direction )
{
	activeBrick->move( direction );
	AddBrick( activeBrick );
}

void CMainGrid::ManageFullLine()
{
	for( std::vector<SlabRow>::iterator rowsIterator = slabsRows.begin(); rowsIterator != slabsRows.end(); ++rowsIterator )
	{
		SlabRow& slabRow = *rowsIterator;
		if( RowIsConnected( slabRow ) )
		{
			MoveAllLinesOneLineDown( rowsIterator );
		}
	}
}

const bool CMainGrid::RowIsConnected( const SlabRow& slabRow )const
{
	for( auto& slab : slabRow )
	{
		if( slab.Empty() )
		{
			return false;
		}
	}
	return true;
}

void CMainGrid::MoveAllLinesOneLineDown( std::vector<SlabRow>::iterator rowIterator )
{
	for( ; rowIterator != slabsRows.begin() + 1; --rowIterator )
	{
		auto& currentRow = *rowIterator;
		auto& oneRowHigher = *(rowIterator - 1);

		for( unsigned columnIterator = 0; columnIterator < currentRow.size(); ++columnIterator )
		{
			Slab& slabHigher = oneRowHigher.at( columnIterator );
			Slab& slabLower = currentRow.at( columnIterator );
			bool emptiness = slabHigher.Empty();
			slabLower.Empty( emptiness );
			SetSlabImagSurface( slabLower );
		}
	}

	for( UInt j = 0; j < rowIterator->size(); ++j )
	{
		Slab& slab = slabsRows.at( 0 ).at( j );
		slab.Empty( true );
		SetSlabImagSurface( slab );
	}
}

void CMainGrid::SetSlabImagSurface( Slab& slab )
{
	auto& slabNode = slab.GetNode();
	if( slab.Empty() )
	{
		slabNode->SetSurface( emptySlabImage );
	}
	else
	{
		slabNode->SetSurface( filledSlabImage );
	}
}
}