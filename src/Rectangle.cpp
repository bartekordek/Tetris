#include "Rectangle.h"

CRectangle::CRectangle( CIntg xPos, CIntg yPos, CUInt width, CUInt height ): 
CPoint( xPos, yPos ),
m_width(width),
m_height(height)
{
}

CRectangle::~CRectangle()
{
}

CUInt CRectangle::Width()const
{
	return m_width;
}

CUInt CRectangle::Height()const
{
	return m_height;
}