#pragma once

#include "Utilities.h"
#include "GeneralUtilities.h"

class CPosition
{
public:
	CPosition( CUInt x = 0, CUInt y = 0 );
	CPosition( const CPosition& position );

	CUInt GetX()const;
	CUInt GetY()const;

	CPosition& operator=( const CPosition& position );

private:
	UInt m_x;
	UInt m_y;
};