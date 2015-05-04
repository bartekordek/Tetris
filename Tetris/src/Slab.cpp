#include "Slab.h"

CSlab::CSlab(const CPicture& picture): 
	m_hasBorder( false ),
	m_picture( picture ),
	m_position( CPosition() )
{

}

CSlab::CSlab( const CSlab& slab ): 
	m_hasBorder( slab.m_hasBorder ),
	m_picture( slab.m_picture ),
	m_position( CPosition() )
{

}

CSlab::CSlab( const unsigned int xPos, const unsigned int yPos ):
	m_hasBorder( false ),
	m_picture( CPicture() ),
	m_position( CPosition( xPos, yPos ) )
{
}



void CSlab::Draw()
{
	//TODO
}