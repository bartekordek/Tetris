#pragma once

#include "Aliases.h"

class CPoint
{
public:
	CPoint( CInt x = 0, CInt y = 0 );
	virtual ~CPoint();

	CInt GetX()const;
	CInt GetY()const;

private:
	int m_x;
	int m_y;
};