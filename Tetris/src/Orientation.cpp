#include "Orientation.h"

COrientation::COrientation( const COrientation::Direction direction )
{
	Set( direction );
}

void COrientation::Set( const COrientation::Direction direction )
{
	m_direction = direction;
}

const COrientation::Direction COrientation::Get()const
{
	return m_direction;
}