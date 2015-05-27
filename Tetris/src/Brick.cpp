#include "Brick.h"
#include <boost/foreach.hpp>

CBrick::CBrick( const Direction direction ): m_direction( direction )
{

}

CBrick::CBrick( const std::vector<CSlab>& blocks, 
				const Direction direction ):m_direction( COrientation::R )
{
	
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

void CBrick::Move( const Direction direction )
{
	if( direction == Direction::D )
	{
		for( std::vector<CSlab>::iterator it = m_blocks.begin(); it != m_blocks.end(); ++it )
		{
		//	it->
		}
	}
}

void CBrick::SetBackgroundImage( const Path& path )
{
	m_backgroundImage = path;
}

const String CBrick::GetImage()
{
	return m_backgroundImage.string();
}

void CBrick::Draw()
{
	BOOST_FOREACH( CSlab slab, m_blocks )
	{
//		slab.Draw();
	}
}

CLBrick::CLBrick(
	const Direction direction ):
	CBrick( direction )
{
	m_blocks.push_back( CSlab( 0, 0 ) );
	m_blocks.push_back( CSlab( 1, 0 ) );
	m_blocks.push_back( CSlab( 0, 1 ) );
	m_blocks.push_back( CSlab( 0, 2 ) );
}

CIBrick::CIBrick(
	const Direction direction ):
	CBrick( direction )
{
	m_blocks.push_back( CSlab( 0, 0 ) );
	m_blocks.push_back( CSlab( 0, 1 ) );
	m_blocks.push_back( CSlab( 0, 2 ) );
	m_blocks.push_back( CSlab( 0, 3 ) );
}

COBrick::COBrick(
	const Direction direction ):
	CBrick( direction )
{
	m_blocks.push_back( CSlab( 0, 0 ) );
	m_blocks.push_back( CSlab( 0, 1 ) );
	m_blocks.push_back( CSlab( 0, 2 ) );
	m_blocks.push_back( CSlab( 0, 3 ) );
}


CSBrick::CSBrick(
	const Direction direction ):
	CBrick( direction )
{
	m_blocks.push_back( CSlab( 0, 0 ) );
	m_blocks.push_back( CSlab( 0, 1 ) );
	m_blocks.push_back( CSlab( 0, 2 ) );
	m_blocks.push_back( CSlab( 0, 3 ) );
}

CTBrick::CTBrick(
	const Direction direction ):
	CBrick( direction )
{
	m_blocks.push_back( CSlab( 0, 0 ) );
	m_blocks.push_back( CSlab( 1, 0 ) );
	m_blocks.push_back( CSlab( 2, 0 ) );
	m_blocks.push_back( CSlab( 1, 1 ) );
}


Path CBrick::m_backgroundImage = "";
