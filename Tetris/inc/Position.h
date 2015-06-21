#ifndef __POSITION_Y__
#define __POSITION_Y__

#include "Utils.h"

/*
 * @brief This class contains position represented by positive carthezian coordinates.
 * @details 
 */
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

#endif