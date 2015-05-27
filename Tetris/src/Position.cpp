#include "Position.h"

CPosition::CPosition( CUInt x, CUInt y )
{
	m_x = x;
	m_y = y;
}

CPosition::CPosition( const CPosition& position )
{
	m_x = position.m_x;
	m_y = position.m_y;
}

CUInt CPosition::GetX()const
{
	return m_x;
}

CUInt CPosition::GetY()const
{
	return m_y;
}