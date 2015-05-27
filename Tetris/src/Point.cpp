#include "Point.h"

CPoint::CPoint( const int x, const int y ): m_x( x ), m_y( y )
{

}

CPoint::~CPoint()
{

}

const int CPoint::GetX()const
{
	return m_x;
}

const int CPoint::GetY()const
{
	return m_y;
}