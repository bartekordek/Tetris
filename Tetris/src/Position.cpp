#include "Position.h"

CPosition::CPosition( const unsigned int x, const unsigned int y )
{
	m_x = x;
	m_y = y;
}

CPosition::CPosition( const CPosition& position )
{
	m_x = position.m_x;
	m_y = position.m_y;
}

const unsigned int CPosition::GetX()const
{
	return m_x;
}

const unsigned int CPosition::GetY()const
{
	return m_y;
}