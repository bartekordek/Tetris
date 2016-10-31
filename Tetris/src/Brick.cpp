#include "Brick.h"

using namespace Moge;
using namespace Math;
namespace Tetris
{
	Brick::Brick( const BrickTypes typeofBrick, const Directions direction ): 
		m_direction( direction ), 
		brickType( typeofBrick )
	{
	}

	Brick::Brick( const std::vector<Slab>& blocks, const Directions direction ):
					m_blocks( blocks ), m_direction( direction )
	{
	}

	BrickTypes Brick::getBlockType()const
	{
		return brickType;
	}

	Brick& Brick::operator=( const Brick& right )
	{
		if( &right != this )
		{
			this->m_blocks = right.m_blocks;
			this->m_direction = right.m_direction;
			this->blockMatrix = right.blockMatrix;
		}
		return *this;
	}

	SquareMatrix2D<myBool> Brick::slab2Matrix( const std::vector<Slab>& slabs )
	{
		SquareMatrix2D<myBool> result( 4 );
		for( const auto& slab: slabs )
		{
			const unsigned int row = slab.row();
			const unsigned int col = slab.col();
			result( row, col ) = true;
		}
		return result;
	}

	Brick::Brick( const Brick& brick ):
		m_blocks( brick.m_blocks ),
		m_direction( brick.m_direction ),
		blockMatrix( brick.blockMatrix )
	{
	}

	void Brick::rotate( const bool clockWise )
	{
		if( true == clockWise )
		{
			rotateClockWise();
		}
	}

	CoordinatestList Brick::getBlockPositions()const
	{
		CoordinatestList positions;
		for( std::vector<Slab>::const_iterator it = m_blocks.begin(); it != m_blocks.end(); ++it )
		{
			positions.push_back( CTableCoor( it->row(), it->col() ) );
		}
		return positions;
	}

	Brick::~Brick()
	{
	}

	void Brick::move( const Directions direction )
	{
		int rowDiff = 0;
		int colDiff = 0;
		if( Directions::D == direction )
		{
			rowDiff = 1;
		}
		else if( Directions::L == direction )
		{
			colDiff = -1;
		}
		else if( Directions::R == direction )
		{
			colDiff = 1;
		}
		else if( Directions::U == direction )
		{
			rowDiff = -1;
		}

		for( auto& slab: m_blocks )
		{
			slab.col( slab.col() + colDiff );
			slab.row( slab.row() + rowDiff );
		}
	}

	CLBrick::CLBrick( const Directions direction ):Brick( BrickTypes::L, direction )
	{
		m_blocks.push_back( Slab( 0, 0 ) );
		m_blocks.push_back( Slab( 0, 1 ) );
		m_blocks.push_back( Slab( 0, 2 ) );
		m_blocks.push_back( Slab( 1, 0 ) );
		blockMatrix = slab2Matrix( m_blocks );
	}

	void CLBrick::rotateClockWise()
	{
		if( m_direction == Directions::U )
		{
			m_blocks[0].SetPosition( m_blocks[0].row() - 2, m_blocks[0].col() + 0 );
			m_blocks[1].SetPosition( m_blocks[1].row() - 1, m_blocks[1].col() + 1 );
			m_blocks[2].SetPosition( m_blocks[2].row(), m_blocks[2].col() + 2 );
			m_blocks[3].SetPosition( m_blocks[3].row() - 1, m_blocks[3].col() - 1 );
			m_direction = Directions::R;
		}
		else if( m_direction == Directions::R )
		{
			m_blocks[0].SetPosition( m_blocks[0].row(), m_blocks[0].col() + 1 );
			m_blocks[1].SetPosition( m_blocks[1].row() + 1, m_blocks[1].col() + 0 );
			m_blocks[2].SetPosition( m_blocks[2].row() + 2, m_blocks[2].col() - 1 );
			m_blocks[3].SetPosition( m_blocks[3].row() - 1, m_blocks[3].col() + 0 );
			m_direction = Directions::D;
		}
		else if( m_direction == Directions::D )
		{
			m_blocks[0].SetPosition( m_blocks[0].row() + 1, m_blocks[0].col() + 1 );

			m_blocks[2].SetPosition( m_blocks[2].row() - 1, m_blocks[2].col() - 1 );
			m_blocks[3].SetPosition( m_blocks[3].row(), m_blocks[3].col() + 2 );
			m_direction = Directions::L;
		}
		else
		{
			m_blocks[0].SetPosition( m_blocks[0].row() + 1, m_blocks[0].col() - 2 );
			m_blocks[1].SetPosition( m_blocks[1].row(), m_blocks[1].col() - 1 );
			m_blocks[2].SetPosition( m_blocks[2].row() - 1, m_blocks[2].col() );
			m_blocks[3].SetPosition( m_blocks[3].row() + 2, m_blocks[3].col() - 1 );
			m_direction = Directions::U;
		}
		blockMatrix.print();
		blockMatrix.rotate();
		blockMatrix.moveElementsUntillNoEmptyLine( Directions::U );
		blockMatrix.moveElementsUntillNoEmptyLine( Directions::L );
		blockMatrix.print();
	}

	CIBrick::CIBrick( const Directions direction ):Brick( BrickTypes::I, direction )
	{
		m_blocks.push_back( Slab( 0, 0 ) );
		m_blocks.push_back( Slab( 0, 1 ) );
		m_blocks.push_back( Slab( 0, 2 ) );
		m_blocks.push_back( Slab( 0, 3 ) );
		blockMatrix = slab2Matrix( m_blocks );
	}

	void CIBrick::rotateClockWise()
	{
		if( m_direction == Directions::U )
		{
			m_blocks[1].SetPosition( m_blocks[1].row() - 1, m_blocks[1].col() + 1 );
			m_blocks[2].SetPosition( m_blocks[2].row() - 2, m_blocks[2].col() + 2 );
			m_blocks[3].SetPosition( m_blocks[3].row() - 3, m_blocks[3].col() + 3 );
			m_direction = Directions::R;
		}
		else if( m_direction == Directions::R )
		{
			m_blocks[1].SetPosition( m_blocks[1].row() + 1, m_blocks[1].col() - 1 );
			m_blocks[2].SetPosition( m_blocks[2].row() + 2, m_blocks[2].col() - 2 );
			m_blocks[3].SetPosition( m_blocks[3].row() + 3, m_blocks[3].col() - 3 );
			m_direction = Directions::D;
		}
		else if( m_direction == Directions::D )
		{
			m_blocks[1].SetPosition( m_blocks[1].row() - 1, m_blocks[1].col() + 1 );
			m_blocks[2].SetPosition( m_blocks[2].row() - 2, m_blocks[2].col() + 2 );
			m_blocks[3].SetPosition( m_blocks[3].row() - 3, m_blocks[3].col() + 3 );
			m_direction = Directions::L;
		}
		else
		{
			m_blocks[1].SetPosition( m_blocks[1].row() + 1, m_blocks[1].col() - 1 );
			m_blocks[2].SetPosition( m_blocks[2].row() + 2, m_blocks[2].col() - 2 );
			m_blocks[3].SetPosition( m_blocks[3].row() + 3, m_blocks[3].col() - 3 );
			m_direction = Directions::U;
		}
		blockMatrix.rotate();
	}

	COBrick::COBrick( const Directions direction ):Brick( BrickTypes::O, direction )
	{
		m_blocks.push_back( Slab( 0, 0 ) );
		m_blocks.push_back( Slab( 0, 1 ) );
		m_blocks.push_back( Slab( 1, 0 ) );
		m_blocks.push_back( Slab( 1, 1 ) );
		blockMatrix = slab2Matrix( m_blocks );
	}

	void COBrick::rotateClockWise()
	{
	}

	CSBrick::CSBrick( const Directions direction ):Brick( BrickTypes::S, direction )
	{
		m_blocks.push_back( Slab( 0, 0 ) );
		m_blocks.push_back( Slab( 0, 1 ) );
		m_blocks.push_back( Slab( 1, 1 ) );
		m_blocks.push_back( Slab( 1, 2 ) );
		blockMatrix = slab2Matrix( m_blocks );
	}

	void CSBrick::rotateClockWise()
	{
		if( m_direction == Directions::U )
		{
			m_blocks[0].SetPosition( m_blocks[0].row(), m_blocks[0].col() - 1 );
			m_blocks[1].SetPosition( m_blocks[1].row() - 1, m_blocks[1].col() );
			m_blocks[2].SetPosition( m_blocks[2].row(), m_blocks[2].col() + 1 );
			m_blocks[3].SetPosition( m_blocks[3].row() - 1, m_blocks[3].col() + 2 );
			m_direction = Directions::R;
		}
		else if( m_direction == Directions::R )
		{
			m_blocks[0].SetPosition( m_blocks[0].row(), m_blocks[0].col() + 1 );
			m_blocks[1].SetPosition( m_blocks[1].row() + 1, m_blocks[1].col() );
			m_blocks[2].SetPosition( m_blocks[2].row(), m_blocks[2].col() - 1 );
			m_blocks[3].SetPosition( m_blocks[3].row() + 1, m_blocks[3].col() - 2 );
			m_direction = Directions::D;
		}
		else if( m_direction == Directions::D )
		{
			m_blocks[0].SetPosition( m_blocks[0].row(), m_blocks[0].col() - 1 );
			m_blocks[1].SetPosition( m_blocks[1].row() - 1, m_blocks[1].col() );
			m_blocks[2].SetPosition( m_blocks[2].row(), m_blocks[2].col() + 1 );
			m_blocks[3].SetPosition( m_blocks[3].row() - 1, m_blocks[3].col() + 2 );
			m_direction = Directions::L;
		}
		else
		{
			m_blocks[0].SetPosition( m_blocks[0].row(), m_blocks[0].col() + 1 );
			m_blocks[1].SetPosition( m_blocks[1].row() + 1, m_blocks[1].col() );
			m_blocks[2].SetPosition( m_blocks[2].row(), m_blocks[2].col() - 1 );
			m_blocks[3].SetPosition( m_blocks[3].row() + 1, m_blocks[3].col() - 2 );
			m_direction = Directions::U;
		}
		blockMatrix.rotate();
	}

	CTBrick::CTBrick( const Directions direction ):Brick( BrickTypes::T, direction )
	{
		m_blocks.push_back( Slab( 0, 0 ) );
		m_blocks.push_back( Slab( 1, 0 ) );
		m_blocks.push_back( Slab( 2, 0 ) );
		m_blocks.push_back( Slab( 1, 1 ) );
		blockMatrix = slab2Matrix( m_blocks );
	}

	void CTBrick::rotateClockWise()
	{
		if( m_direction == Directions::U )
		{
			m_blocks[0].SetPosition( m_blocks[0].row() - 1, m_blocks[0].col() );
			m_blocks[1].SetPosition( m_blocks[1].row(), m_blocks[1].col() - 1 );
			m_blocks[2].SetPosition( m_blocks[2].row() + 1, m_blocks[2].col() - 2 );
			m_blocks[3].SetPosition( m_blocks[3].row() + 1, m_blocks[3].col() );
			m_direction = Directions::R;
		}
		else if( m_direction == Directions::R )
		{
			m_blocks[1].SetPosition( m_blocks[1].row() - 1, m_blocks[1].col() + 1 );
			m_blocks[2].SetPosition( m_blocks[2].row() - 2, m_blocks[2].col() + 2 );
			m_blocks[3].SetPosition( m_blocks[3].row(), m_blocks[3].col() );
			m_direction = Directions::D;
		}
		else if( m_direction == Directions::D )
		{
			m_blocks[0].SetPosition( m_blocks[0].row(), m_blocks[0].col() + 1 );
			m_blocks[1].SetPosition( m_blocks[1].row() + 1, m_blocks[1].col() );
			m_blocks[2].SetPosition( m_blocks[2].row() + 2, m_blocks[2].col() - 1 );
			m_blocks[3].SetPosition( m_blocks[3].row(), m_blocks[3].col() - 1 );
			m_direction = Directions::L;
		}
		else
		{
			m_blocks[0].SetPosition( m_blocks[0].row() + 1, m_blocks[0].col() - 1 );
			m_blocks[2].SetPosition( m_blocks[2].row() - 1, m_blocks[2].col() + 1 );
			m_blocks[3].SetPosition( m_blocks[3].row() - 1, m_blocks[3].col() + 1 );
			m_direction = Directions::U;
		}
		blockMatrix.rotate();
	}
}