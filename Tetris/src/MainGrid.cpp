#include "Game.h"
#include "MainGrid.h"
#include "BrickFactory.h"
#include "NodeCreator.h"
#include "NodeImageCreator.h"
#include "MTime.h"

namespace Tetris
{
	CMainGrid::CMainGrid():m_activeBrick( nullptr )
	{
		std::lock_guard<std::mutex> slabLock( currentBrickMutex );
		Moge::Path blockImagepath = Moge::Path::GetCurrentDirectory() + "\\..\\..\\Media\\Block.bmp";
		mFilledSlabImage = Moge::ImageCreator::CreateSurfaceFromImage( blockImagepath );

		Moge::Path bgBlockImagepath = Moge::Path::GetCurrentDirectory() + "\\..\\..\\Media\\BackGroundBlock.bmp";
		mEmptySlabImage = Moge::ImageCreator::CreateSurfaceFromImage( bgBlockImagepath );
	}

	CMainGrid::~CMainGrid()
	{
		mSlabsRows.erase( mSlabsRows.begin(), mSlabsRows.end() );
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
		mSlabsRows.erase( mSlabsRows.begin(), mSlabsRows.end() );
		for( UInt row = 0; row < rowsCount; ++row )
		{
			SlabRow rows;
			for( UInt col = 0; col < columnsCount; ++col )
			{
				CSlab slab( row + initialY, col + initialX, false, true );
				rows.push_back( slab );
			}
			mSlabsRows.push_back( rows );
		}

		for( auto& slabRow : mSlabsRows )
		{
			for( auto& slab : slabRow )
			{
				std::shared_ptr<Moge::ObjectNodeContent> slabNode = Moge::NodeCreator::CreateFromImage( mEmptySlabImage );
				Moge::Math::IPositionAdapter<int> position( slab.Col() * slabNode->getWidth(), slab.Row() * slabNode->getHeight(), 0 );
				slabNode->setXyz( position.getX(), position.getY(), 0 );
				slab.SetNode( slabNode );

				slabNode->SetVisible();
				Moge::Engine::Instance().AddObject( slabNode );//TODO: redundant add, should be moved to NodeMgr
			}
		}
	}

	void CMainGrid::ReLeaseBrick()
	{
		delete m_activeBrick;
		m_activeBrick = CBrickFactory::GetRandomBrick();
		AddBrick( m_activeBrick );
	}

	void CMainGrid::AddBrick( const Brick* brick )
	{
		CoordinatestList coords = brick->getBlockPositions();
		for( auto it = coords.begin(); it != coords.end(); ++it )
		{
			CUInt row = it->Row();
			CUInt col = it->Col();
			MarkSlabAsPartOfMovingBlock( row, col );
		}
	}

	void CMainGrid::MarkSlabAsPartOfMovingBlock( CUInt row, CUInt col )
	{
		if( row >= mSlabsRows.size() || ( mSlabsRows.size() > 0 && col > mSlabsRows.at( 0 ).size() ) )
		{
			return;
		}

		CSlab& slab = mSlabsRows.at( row ).at( col );
		slab.Empty( false );
		auto slabNode = slab.GetNode();
		slabNode->SetSurface( mFilledSlabImage );
	}

	const bool CMainGrid::PartOfCurrentBrick( CUInt rowIndex, CUInt colIndex )const
	{
		CoordinatestList coords = m_activeBrick->getBlockPositions();
		for( auto it = coords.begin(); it != coords.end(); ++it )
		{
			if( it->Row() == rowIndex && it->Col() == colIndex )
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
		for( auto& coord : m_activeBrick->getBlockPositions() )
		{
			CUInt newRow = coord.Row() + GetRowOffset( direction );
			CUInt newCol = coord.Col() + GetColOffset( direction );

			if( newRow >= mSlabsRows.size() )
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

			if( false == mSlabsRows.at( newRow ).at( newCol ).Empty() )
			{
				return false;
			}
		}
		return true;
	}

	const bool CMainGrid::checkIfBlockCanBeRotated( const bool clockWise )
	{

		return false;
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
		Brick* tempBrick;
		if( m_activeBrick->getBlockType() == BrickTypes::L )
		{
			tempBrick = new CLBrick( *dynamic_cast<CLBrick*>( m_activeBrick ) );
		}
		else if( m_activeBrick->getBlockType() == BrickTypes::I )
		{
			tempBrick = new CIBrick( *dynamic_cast<CIBrick*>( m_activeBrick ) );
		}
		else if( m_activeBrick->getBlockType() == BrickTypes::O )
		{
			tempBrick = new COBrick( *dynamic_cast<COBrick*>( m_activeBrick ) );
		}
		else if( m_activeBrick->getBlockType() == BrickTypes::S )
		{
			tempBrick = new CSBrick( *dynamic_cast<CSBrick*>( m_activeBrick ) );
		}
		else
		{
			tempBrick = new CTBrick( *dynamic_cast<CTBrick*>( m_activeBrick ) );
		}

		tempBrick->rotate( clockWise );
		if( true == m_CheckIfBlockCanBePlaced( tempBrick ) )
		{
			m_RemoveActualBlockSlabsFromGrid();
			m_activeBrick->rotate( clockWise );
		}
		delete tempBrick;
	}

	void CMainGrid::addCurrentBrickToGrid()
	{
		if( m_activeBrick )
		{
			for( auto& coord : m_activeBrick->getBlockPositions() )
			{
				CSlab& slab = mSlabsRows.at( coord.Row() ).at( coord.Col() );
				slab.Empty( false );
				slab.GetNode().get()->SetSurface( mFilledSlabImage );
			}
		}
	}

	const bool CMainGrid::m_CheckIfBlockCanBePlaced( const Brick* brick )
	{
		CoordinatestList coords = brick->getBlockPositions();
		for( auto it = coords.begin(); it != coords.end(); ++it )
		{

			if( it->Row() >= mSlabsRows.size() )
			{
				return false;
			}
			if( false == SlabExist( it->Row(), it->Col() ) )
			{
				return false;
			}

			if( true == PartOfCurrentBrick( it->Row(), it->Col() ) )
			{
				continue;
			}

			if( false == mSlabsRows.at( it->Row() ).at( it->Col() ).Empty() )
			{
				return false;
			}
		}
		return true;
	}

	const bool CMainGrid::SlabExist( CUInt rowIndex, CUInt colIndex )const
	{
		if( colIndex >= mSlabsRows.at( 0 ).size() || rowIndex >= mSlabsRows.size() )
		{
			return false;
		}
		return true;
	}

	void CMainGrid::m_RemoveActualBlockSlabsFromGrid()
	{
		for( auto& coord : m_activeBrick->getBlockPositions() )
		{
			auto& slab = mSlabsRows.at( coord.Row() ).at( coord.Col() );
			slab.Empty( true );
			auto slabnode = slab.GetNode();
			slabnode->SetSurface( mEmptySlabImage );
		}
	}

	void CMainGrid::moveCurrentBrick( const Moge::Math::Directions direction )
	{
		m_activeBrick->move( direction );
		AddBrick( m_activeBrick );
	}

	void CMainGrid::ManageFullLine()
	{
		for( std::vector<SlabRow>::iterator rowsIterator = mSlabsRows.begin(); rowsIterator != mSlabsRows.end(); ++rowsIterator )
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
		for( ; rowIterator != mSlabsRows.begin() + 1; --rowIterator )
		{
			auto& currentRow = *rowIterator;
			auto& oneRowHigher = *(rowIterator - 1);

			for( unsigned columnIterator = 0; columnIterator < currentRow.size(); ++columnIterator )
			{
				CSlab& slabHigher = oneRowHigher.at( columnIterator );
				CSlab& slabLower = currentRow.at( columnIterator );
				bool emptiness = slabHigher.Empty();
				slabLower.Empty( emptiness );
				SetSlabImagSurface( slabLower );
			}
		}

		for( UInt j = 0; j < rowIterator->size(); ++j )
		{
			CSlab& slab = mSlabsRows.at( 0 ).at( j );
			slab.Empty( true );
			SetSlabImagSurface( slab );
		}
	}

	void CMainGrid::SetSlabImagSurface( CSlab& slab )
	{
		auto& slabNode = slab.GetNode();
		if( slab.Empty() )
		{
			slabNode->SetSurface( mEmptySlabImage );
		}
		else
		{
			slabNode->SetSurface( mFilledSlabImage );
		}
	}
}