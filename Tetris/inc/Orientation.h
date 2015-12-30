#pragma once
#include <bitset>

/*
 * @brief Class to handle orientation. 
 */
class COrientation
{
public:
	enum Direction{ L, R, U, D };

	COrientation( const Direction direction = R );
	~COrientation();
	void Set( const Direction direction );
	const Direction Get()const;

private:
	Direction m_direction;

};