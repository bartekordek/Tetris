#include "Game.h"
#include "MainGrid.h"
#include "BrickFactory.h"
#include "MTime.h"
#include "MogeLibMain.h"

namespace Tetris
{
	using namespace Moge;
	CMainGrid::CMainGrid()
	{
		this->tF = EngineManager::getEngine()->get2DTextureFactory();
		std::lock_guard<std::mutex> slabLock( currentBrickMutex );

		Path blockImagepath = Path::GetCurrentDirectory() + "\\..\\..\\Media\\Block.bmp";
		this->filledSlabTex = tF->createTexture( blockImagepath );

		Path bgBlockImagepath = Path::GetCurrentDirectory() + "\\..\\..\\Media\\BackGroundBlock.bmp";
		this->emptySlabTex = tF->createTexture( bgBlockImagepath );
	}

	CMainGrid::~CMainGrid()
	{
	}

	void CMainGrid::updateGrid()
	{
		if( false == checkIfBlockCanBeMoved( Math::Directions::D ) )
		{
			addCurrentBrickToGrid();
			ManageFullLine();
			ReLeaseBrick();
		}
		CTimeMod::SleepMiliSeconds( 500 );
		MoveActualBrick( Math::Directions::D );
	}

	void CMainGrid::SetSize( const unsigned int rowsCount, const unsigned int columnsCount, const unsigned int initialX, const unsigned int initialY )
	{
		clearSlabs();
		for( auto row = 0; row < rowsCount; ++row )
		{
			SlabRow rows;
			for( auto col = 0; col < columnsCount; ++col )
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
				auto slabNode = EngineManager::getEngine()->getNodeFactory()->createFromTexture( this->emptySlabTex );
				auto& slabSize = slabNode->getSize();
				auto& slabPos = slabNode->getPosition();
				slabPos.setX( slab.col() * slabSize.getWidth() );
				slabPos.setY( slab.row() * slabSize.getHeight() );

				slab.setNode( slabNode );
				slabNode->SetVisible( true );
			}
		}
		//slabNode->setScale( 2.0 ); // TODO: uncomment this line after implementing correct scale system - textues.
	}

	void CMainGrid::clearSlabs()
	{
		this->slabsRows.erase( this->slabsRows.begin(), this->slabsRows.end() );
	}

	void CMainGrid::ReLeaseBrick()
	{
		//delete activeBrick;
		//activeBrick = CBrickFactory::GetRandomBrick();
		//AddBrick( activeBrick );
	}

	void CMainGrid::AddBrick( const Brick* brick )
	{
		const CoordinatestList coords = brick->getBlockPositions();
		for( auto it = coords.begin(); it != coords.end(); ++it )
		{
			MarkSlabAsPartOfMovingBlock( it->getRow(), it->getCol() );
		}
	}

	void CMainGrid::MarkSlabAsPartOfMovingBlock( const unsigned int row, const unsigned int col )
	{
		//if( row >= slabsRows.size() || ( slabsRows.size() > 0 && col > slabsRows.at( 0 ).size() ) )
		//{
		//	return;
		//}

		//Slab& slab = slabsRows.at( row ).at( col );
		//slab.setEmpty( false );
		//auto slabNode = slab.getNode();
		//slabNode->SetSurface( filledSlabImage );
	}

	const bool CMainGrid::PartOfCurrentBrick( const unsigned int rowIndex, const unsigned int colIndex )const
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

	void CMainGrid::MoveActualBrick( const Math::Directions direction )
	{
		if( true == checkIfBlockCanBeMoved( direction ) )
		{
			m_RemoveActualBlockSlabsFromGrid();
			moveCurrentBrick( direction );
		}
	}

	const bool CMainGrid::checkIfBlockCanBeMoved( const Math::Directions direction )
	{
		for( auto& coord : activeBrick->getBlockPositions() )
		{
			const unsigned int newRow = coord.getRow() + GetRowOffset( direction );
			const unsigned int newCol = coord.getCol() + GetColOffset( direction );

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

			if( false == slabsRows.at( newRow ).at( newCol ).isEmpty() )
			{
				return false;
			}
		}
		return true;
	}

	const int CMainGrid::GetColOffset( const Math::Directions direction )const
	{
		if( Math::Directions::U == direction || Math::Directions::D == direction )
		{
			return 0;
		}

		if( Math::Directions::R == direction )
		{
			return 1;
		}
		if( Math::Directions::L == direction )
		{
			return  -1;
		}
		return -1;
	}

	const int CMainGrid::GetRowOffset( const Math::Directions direction )const
	{
		using namespace Math;
		if( Directions::U == direction )
		{
			return  0;
		}
		else if( Directions::D == direction )
		{
			return  1;
		}
		else if( Directions::R == direction )
		{
			return  0;
		}
		else if( Directions::L == direction )
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
		//if( activeBrick )
		//{
		//	for( auto& coord : activeBrick->getBlockPositions() )
		//	{
		//		Slab& slab = slabsRows.at( coord.getRow() ).at( coord.getCol() );
		//		slab.setEmpty( false );
		//		slab.getNode().get()->SetSurface( filledSlabImage );
		//	}
		//}
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

			if( false == slabsRows.at( it->getRow() ).at( it->getCol() ).isEmpty() )
			{
				return false;
			}
		}
		return true;
	}

	const bool CMainGrid::SlabExist( const unsigned int rowIndex, const unsigned int colIndex )const
	{
		if( colIndex >= slabsRows.at( 0 ).size() || rowIndex >= slabsRows.size() )
		{
			return false;
		}
		return true;
	}

	void CMainGrid::m_RemoveActualBlockSlabsFromGrid()
	{
		//for( auto& coord : activeBrick->getBlockPositions() )
		//{
		//	auto& slab = slabsRows.at( coord.getRow() ).at( coord.getCol() );
		//	slab.setEmpty( true );
		//	auto slabnode = slab.getNode();
		//	slabnode->SetSurface( emptySlabImage );
		//}
	}

	void CMainGrid::moveCurrentBrick( const Math::Directions direction )
	{
		//activeBrick->move( direction );
		//AddBrick( activeBrick );
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
			if( slab.isEmpty() )
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
				bool emptiness = slabHigher.isEmpty();
				slabLower.setEmpty( emptiness );
				SetSlabImagSurface( slabLower );
			}
		}

		for( unsigned int j = 0; j < rowIterator->size(); ++j )
		{
			Slab& slab = slabsRows.at( 0 ).at( j );
			slab.setEmpty( true );
			SetSlabImagSurface( slab );
		}
	}

	void CMainGrid::SetSlabImagSurface( Slab& slab )
	{
		//auto& slabNode = slab.getNode();
		//if( slab.isEmpty() )
		//{
		//	slabNode->SetSurface( this->emptySlabImage );
		//}
		//else
		//{
		//	slabNode->SetSurface( this->filledSlabImage );
		//}
	}
}