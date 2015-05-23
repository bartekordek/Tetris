#include "Slab.h"

CSlab::CSlab( const CSlab& slab ): 
	m_position( CTableCoor( slab.Row(), slab.Col() ) )
{

}

CSlab::CSlab( const unsigned int xPos, const unsigned int yPos ):
	m_position( CTableCoor( xPos, yPos ) )
{
}

const unsigned int CSlab::Row()const
{
	return m_position.GetRow();
}

const unsigned int CSlab::Col()const
{
	return m_position.GetCol();
}