#include "Slab.h"

CSlab::CSlab(const CPicture& picture): 
	m_hasBorder( false ),
	m_picture( picture )
{

}

CSlab::CSlab( const CSlab& slab ): 
	m_hasBorder( slab.m_hasBorder ),
	m_picture( slab.m_picture )
{

}

void CSlab::Draw()
{

}