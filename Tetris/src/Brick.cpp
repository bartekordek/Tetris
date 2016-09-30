#include "Brick.h"

namespace Tetris
{
	CBrick::CBrick( BrickTypes typeofBrick, const Directions direction ): 
		m_direction( direction ), 
		m_brickType( typeofBrick )
	{
	}

	CBrick::CBrick( const std::vector<CSlab>& blocks,
					const Directions direction ):
					m_blocks( blocks ), m_direction( direction )
	{
	}

	BrickTypes CBrick::GetBlockType()const
	{
		return m_brickType;
	}

	CBrick::CBrick( const CBrick& brick ):
		m_blocks( brick.m_blocks ),
		m_direction( brick.m_direction )
	{
	}

	void CBrick::Rotate( const bool clockWise )
	{
		if( true == clockWise )
		{
			m_RotateClockWise();
		}
	}

	CoordinatestList CBrick::GetBlockPositions()const
	{
		CoordinatestList positions;
		for( std::vector<CSlab>::const_iterator it = m_blocks.begin(); it != m_blocks.end(); ++it )
		{
			positions.push_back( CTableCoor( it->Row(), it->Col() ) );
		}
		return positions;
	}

	CBrick::~CBrick()
	{

	}

	void CBrick::Move( const Directions direction )
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

		for( std::vector<CSlab>::iterator it = m_blocks.begin(); it != m_blocks.end(); ++it )
		{
			it->Col( it->Col() + colDiff );
			it->Row( it->Row() + rowDiff );
		}
	}

	CLBrick::CLBrick( const Directions direction ):CBrick( BrickTypes::L, direction )
	{
		m_blocks.push_back( CSlab( 0, 0 ) );
		m_blocks.push_back( CSlab( 0, 1 ) );
		m_blocks.push_back( CSlab( 0, 2 ) );
		m_blocks.push_back( CSlab( 1, 0 ) );
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
	}

	CIBrick::CIBrick( const Directions direction ):CBrick( BrickTypes::I, direction )
	{
		m_blocks.push_back( CSlab( 0, 0 ) );
		m_blocks.push_back( CSlab( 0, 1 ) );
		m_blocks.push_back( CSlab( 0, 2 ) );
		m_blocks.push_back( CSlab( 0, 3 ) );
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
	}

	COBrick::COBrick( const Directions direction ):CBrick( BrickTypes::O, direction )
	{
		m_blocks.push_back( CSlab( 0, 0 ) );
		m_blocks.push_back( CSlab( 0, 1 ) );
		m_blocks.push_back( CSlab( 1, 0 ) );
		m_blocks.push_back( CSlab( 1, 1 ) );
	}

	void COBrick::m_RotateClockWise()
	{
	}

	CSBrick::CSBrick( const Directions direction ):CBrick( BrickTypes::S, direction )
	{
		m_blocks.push_back( CSlab( 0, 0 ) );
		m_blocks.push_back( CSlab( 0, 1 ) );
		m_blocks.push_back( CSlab( 1, 1 ) );
		m_blocks.push_back( CSlab( 1, 2 ) );
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
	}

	CTBrick::CTBrick( const Directions direction ):CBrick( BrickTypes::T, direction )
	{
		m_blocks.push_back( CSlab( 0, 0 ) );
		m_blocks.push_back( CSlab( 1, 0 ) );
		m_blocks.push_back( CSlab( 2, 0 ) );
		m_blocks.push_back( CSlab( 1, 1 ) );
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
	}
}