#ifndef __ORIENTATION_YY__
#define __ORIENTATION_YY__

#include <bitset>

class COrientation
{
public:
	enum Direction{ L, R, U, D };

	COrientation( const Direction direction = R );

	void Set( const Direction direction );
	const Direction Get()const;

private:
	Direction m_direction;

};
#endif