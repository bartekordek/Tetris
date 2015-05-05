#include "Brick.h"
#include <boost/foreach.hpp>

CBrick::CBrick( const COrientation::Direction direction ): m_direction( direction )
{

}

CBrick::CBrick( 
	const std::vector<CSlab>& blocks, 
	const COrientation::Direction direction ):m_direction( COrientation::R )
{
	
}

CBrick::~CBrick()
{

}

void CBrick::Draw()
{
	BOOST_FOREACH( CSlab slab, m_blocks )
	{
//		slab.Draw();
	}
}

CLBrick::CLBrick(
	const COrientation::Direction direction ):
	CBrick( direction )
{
	m_blocks.push_back( CSlab( 0, 0 ) );
	m_blocks.push_back( CSlab( 1, 0 ) );
	m_blocks.push_back( CSlab( 0, 1 ) );
	m_blocks.push_back( CSlab( 0, 2 ) );
}

CIBrick::CIBrick(
	const COrientation::Direction direction ):
	CBrick( direction )
{
	m_blocks.push_back( CSlab( 0, 0 ) );
	m_blocks.push_back( CSlab( 0, 1 ) );
	m_blocks.push_back( CSlab( 0, 2 ) );
	m_blocks.push_back( CSlab( 0, 3 ) );
}

COBrick::COBrick(
	const COrientation::Direction direction ):
	CBrick( direction )
{
	m_blocks.push_back( CSlab( 0, 0 ) );
	m_blocks.push_back( CSlab( 0, 1 ) );
	m_blocks.push_back( CSlab( 0, 2 ) );
	m_blocks.push_back( CSlab( 0, 3 ) );
}


CSBrick::CSBrick(
	const COrientation::Direction direction ):
	CBrick( direction )
{
	m_blocks.push_back( CSlab( 0, 0 ) );
	m_blocks.push_back( CSlab( 0, 1 ) );
	m_blocks.push_back( CSlab( 0, 2 ) );
	m_blocks.push_back( CSlab( 0, 3 ) );
}

CTBrick::CTBrick(
	const COrientation::Direction direction ):
	CBrick( direction )
{
	m_blocks.push_back( CSlab( 0, 0 ) );
	m_blocks.push_back( CSlab( 1, 0 ) );
	m_blocks.push_back( CSlab( 2, 0 ) );
	m_blocks.push_back( CSlab( 1, 1 ) );
}
