#pragma once

class COrientation
{
public:
	enum Direction{ L, R, U, D };

	explicit COrientation( const Direction direction = Direction::R );
	virtual ~COrientation();
	void Set( const Direction direction );
	const Direction Get()const;

private:
	Direction m_direction;

};