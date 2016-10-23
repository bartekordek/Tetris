#include "Brick.h"

using namespace Moge;
using namespace Math;
namespace Tetris
{
	Brick::Brick( const BrickTypes typeofBrick, const Directions direction ): 
		m_direction( direction ), 
		m_brickType( typeofBrick )
	{
	}

	Brick::Brick( const std::vector<CSlab>& blocks, const Directions direction ):
					m_blocks( blocks ), m_direction( direction )
	{
	}

	BrickTypes Brick::getBlockType()const
	{
		return m_brickType;
	}

	SquareMatrix2D<bool> Brick::slab2Matrix( const std::vector<CSlab>& slabs )
	{
		SquareMatrix2D<bool> result( slabs.size() / 2 );
		for( const auto& slab: slabs )
		{
			result( slab.Row(), slab.Col() ) = true;
		}
		return result;
	}

	Brick::Brick( const Brick& brick ):
		m_blocks( brick.m_blocks ),
		m_direction( brick.m_direction )
	{
	}

	void Brick::rotate( const bool clockWise )
	{
		if( true == clockWise )
		{
			m_RotateClockWise();
		}
	}

	CoordinatestList Brick::getBlockPositions()const
	{
		CoordinatestList positions;
		for( std::vector<CSlab>::const_iterator it = m_blocks.begin(); it != m_blocks.end(); ++it )
		{
			positions.push_back( CTableCoor( it->Row(), it->Col() ) );
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
			slab.Col( slab.Col() + colDiff );
			slab.Row( slab.Row() + rowDiff );
		}
	}

	CLBrick::CLBrick( const Directions direction ):Brick( BrickTypes::L, direction )
	{
		m_blocks.push_back( CSlab( 0, 0 ) );
		m_blocks.push_back( CSlab( 0, 1 ) );
		m_blocks.push_back( CSlab( 0, 2 ) );
		m_blocks.push_back( CSlab( 1, 0 ) );
		blockMatrix = slab2Matrix( m_blocks );
	}

	void CLBrick::m_RotateClockWise()
	{
		if( m_direction == Directions::U )
		{
			m_blocks[0].SetPosition( m_blocks[0].Row() - 2, m_blocks[0].Col() + 0 );
			m_blocks[1].SetPosition( m_blocks[1].Row() - 1, m_blocks[1].Col() + 1 );
			m_blocks[2].SetPosition( m_blocks[2].Row(), m_blocks[2].Col() + 2 );
			m_blocks[3].SetPosition( m_blocks[3].Row() - 1, m_blocks[3].Col() - 1 );
			m_direction = Directions::R;
		}
		else if( m_direction == Directions::R )
		{
			m_blocks[0].SetPosition( m_blocks[0].Row(), m_blocks[0].Col() + 1 );
			m_blocks[1].SetPosition( m_blocks[1].Row() + 1, m_blocks[1].Col() + 0 );
			m_blocks[2].SetPosition( m_blocks[2].Row() + 2, m_blocks[2].Col() - 1 );
			m_blocks[3].SetPosition( m_blocks[3].Row() - 1, m_blocks[3].Col() + 0 );
			m_direction = Directions::D;
		}
		else if( m_direction == Directions::D )
		{
			m_blocks[0].SetPosition( m_blocks[0].Row() + 1, m_blocks[0].Col() + 1 );

			m_blocks[2].SetPosition( m_blocks[2].Row() - 1, m_blocks[2].Col() - 1 );
			m_blocks[3].SetPosition( m_blocks[3].Row(), m_blocks[3].Col() + 2 );
			m_direction = Directions::L;
		}
		else
		{
			m_blocks[0].SetPosition( m_blocks[0].Row() + 1, m_blocks[0].Col() - 2 );
			m_blocks[1].SetPosition( m_blocks[1].Row(), m_blocks[1].Col() - 1 );
			m_blocks[2].SetPosition( m_blocks[2].Row() - 1, m_blocks[2].Col() );
			m_blocks[3].SetPosition( m_blocks[3].Row() + 2, m_blocks[3].Col() - 1 );
			m_direction = Directions::U;
		}
		blockMatrix.rotate();
	}

	CIBrick::CIBrick( const Directions direction ):Brick( BrickTypes::I, direction )
	{
		m_blocks.push_back( CSlab( 0, 0 ) );
		m_blocks.push_back( CSlab( 0, 1 ) );
		m_blocks.push_back( CSlab( 0, 2 ) );
		m_blocks.push_back( CSlab( 0, 3 ) );
		blockMatrix = slab2Matrix( m_blocks );
	}

	void CIBrick::m_RotateClockWise()
	{
		if( m_direction == Directions::U )
		{
			m_blocks[1].SetPosition( m_blocks[1].Row() - 1, m_blocks[1].Col() + 1 );
			m_blocks[2].SetPosition( m_blocks[2].Row() - 2, m_blocks[2].Col() + 2 );
			m_blocks[3].SetPosition( m_blocks[3].Row() - 3, m_blocks[3].Col() + 3 );
			m_direction = Directions::R;
		}
		else if( m_direction == Directions::R )
		{
			m_blocks[1].SetPosition( m_blocks[1].Row() + 1, m_blocks[1].Col() - 1 );
			m_blocks[2].SetPosition( m_blocks[2].Row() + 2, m_blocks[2].Col() - 2 );
			m_blocks[3].SetPosition( m_blocks[3].Row() + 3, m_blocks[3].Col() - 3 );
			m_direction = Directions::D;
		}
		else if( m_direction == Directions::D )
		{
			m_blocks[1].SetPosition( m_blocks[1].Row() - 1, m_blocks[1].Col() + 1 );
			m_blocks[2].SetPosition( m_blocks[2].Row() - 2, m_blocks[2].Col() + 2 );
			m_blocks[3].SetPosition( m_blocks[3].Row() - 3, m_blocks[3].Col() + 3 );
			m_direction = Directions::L;
		}
		else
		{
			m_blocks[1].SetPosition( m_blocks[1].Row() + 1, m_blocks[1].Col() - 1 );
			m_blocks[2].SetPosition( m_blocks[2].Row() + 2, m_blocks[2].Col() - 2 );
			m_blocks[3].SetPosition( m_blocks[3].Row() + 3, m_blocks[3].Col() - 3 );
			m_direction = Directions::U;
		}
		blockMatrix.rotate();
	}

	COBrick::COBrick( const Directions direction ):Brick( BrickTypes::O, direction )
	{
		m_blocks.push_back( CSlab( 0, 0 ) );
		m_blocks.push_back( CSlab( 0, 1 ) );
		m_blocks.push_back( CSlab( 1, 0 ) );
		m_blocks.push_back( CSlab( 1, 1 ) );
		blockMatrix = slab2Matrix( m_blocks );
	}

	void COBrick::m_RotateClockWise()
	{
	}

	CSBrick::CSBrick( const Directions direction ):Brick( BrickTypes::S, direction )
	{
		m_blocks.push_back( CSlab( 0, 0 ) );
		m_blocks.push_back( CSlab( 0, 1 ) );
		m_blocks.push_back( CSlab( 1, 1 ) );
		m_blocks.push_back( CSlab( 1, 2 ) );
		blockMatrix = slab2Matrix( m_blocks );
	}

	void CSBrick::m_RotateClockWise()
	{
		if( m_direction == Directions::U )
		{
			m_blocks[0].SetPosition( m_blocks[0].Row(), m_blocks[0].Col() - 1 );
			m_blocks[1].SetPosition( m_blocks[1].Row() - 1, m_blocks[1].Col() );
			m_blocks[2].SetPosition( m_blocks[2].Row(), m_blocks[2].Col() + 1 );
			m_blocks[3].SetPosition( m_blocks[3].Row() - 1, m_blocks[3].Col() + 2 );
			m_direction = Directions::R;
		}
		else if( m_direction == Directions::R )
		{
			m_blocks[0].SetPosition( m_blocks[0].Row(), m_blocks[0].Col() + 1 );
			m_blocks[1].SetPosition( m_blocks[1].Row() + 1, m_blocks[1].Col() );
			m_blocks[2].SetPosition( m_blocks[2].Row(), m_blocks[2].Col() - 1 );
			m_blocks[3].SetPosition( m_blocks[3].Row() + 1, m_blocks[3].Col() - 2 );
			m_direction = Directions::D;
		}
		else if( m_direction == Directions::D )
		{
			m_blocks[0].SetPosition( m_blocks[0].Row(), m_blocks[0].Col() - 1 );
			m_blocks[1].SetPosition( m_blocks[1].Row() - 1, m_blocks[1].Col() );
			m_blocks[2].SetPosition( m_blocks[2].Row(), m_blocks[2].Col() + 1 );
			m_blocks[3].SetPosition( m_blocks[3].Row() - 1, m_blocks[3].Col() + 2 );
			m_direction = Directions::L;
		}
		else
		{
			m_blocks[0].SetPosition( m_blocks[0].Row(), m_blocks[0].Col() + 1 );
			m_blocks[1].SetPosition( m_blocks[1].Row() + 1, m_blocks[1].Col() );
			m_blocks[2].SetPosition( m_blocks[2].Row(), m_blocks[2].Col() - 1 );
			m_blocks[3].SetPosition( m_blocks[3].Row() + 1, m_blocks[3].Col() - 2 );
			m_direction = Directions::U;
		}
		blockMatrix.rotate();
	}

	CTBrick::CTBrick( const Directions direction ):Brick( BrickTypes::T, direction )
	{
		m_blocks.push_back( CSlab( 0, 0 ) );
		m_blocks.push_back( CSlab( 1, 0 ) );
		m_blocks.push_back( CSlab( 2, 0 ) );
		m_blocks.push_back( CSlab( 1, 1 ) );
		blockMatrix = slab2Matrix( m_blocks );
	}

	void CTBrick::m_RotateClockWise()
	{
		if( m_direction == Directions::U )
		{
			m_blocks[0].SetPosition( m_blocks[0].Row() - 1, m_blocks[0].Col() );
			m_blocks[1].SetPosition( m_blocks[1].Row(), m_blocks[1].Col() - 1 );
			m_blocks[2].SetPosition( m_blocks[2].Row() + 1, m_blocks[2].Col() - 2 );
			m_blocks[3].SetPosition( m_blocks[3].Row() + 1, m_blocks[3].Col() );
			m_direction = Directions::R;
		}
		else if( m_direction == Directions::R )
		{
			m_blocks[1].SetPosition( m_blocks[1].Row() - 1, m_blocks[1].Col() + 1 );
			m_blocks[2].SetPosition( m_blocks[2].Row() - 2, m_blocks[2].Col() + 2 );
			m_blocks[3].SetPosition( m_blocks[3].Row(), m_blocks[3].Col() );
			m_direction = Directions::D;
		}
		else if( m_direction == Directions::D )
		{
			m_blocks[0].SetPosition( m_blocks[0].Row(), m_blocks[0].Col() + 1 );
			m_blocks[1].SetPosition( m_blocks[1].Row() + 1, m_blocks[1].Col() );
			m_blocks[2].SetPosition( m_blocks[2].Row() + 2, m_blocks[2].Col() - 1 );
			m_blocks[3].SetPosition( m_blocks[3].Row(), m_blocks[3].Col() - 1 );
			m_direction = Directions::L;
		}
		else
		{
			m_blocks[0].SetPosition( m_blocks[0].Row() + 1, m_blocks[0].Col() - 1 );
			m_blocks[2].SetPosition( m_blocks[2].Row() - 1, m_blocks[2].Col() + 1 );
			m_blocks[3].SetPosition( m_blocks[3].Row() - 1, m_blocks[3].Col() + 1 );
			m_direction = Directions::U;
		}
		blockMatrix.rotate();
	}
}