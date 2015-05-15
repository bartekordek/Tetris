#include "Point.h"

CPoint::CPoint( const unsigned int x, const unsigned int y ): m_x( x ), m_y( y )
{

}

CPoint::~CPoint()
{

}

const unsigned int CPoint::GetX()const
{
	return m_x;
}

const unsigned int CPoint::GetY()const
{
	return m_y;
}