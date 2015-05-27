#ifndef __RECT__
#define __RECT__

#include "Utils.h"
#include "Point.h"


class CRectangle: public CPoint
{
public:
	CRectangle( CIntg xPos = 0, CIntg yPos = 0, CUInt width = 0, CUInt height = 0 );
	virtual ~CRectangle();

	CUInt Width()const;
	CUInt Height()const;

private:
	UInt m_width;
	UInt m_height;
};

#endif