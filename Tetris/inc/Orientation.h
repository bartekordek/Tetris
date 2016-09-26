#pragma once

class COrientation
{
public:
	enum class Direction: char
	{ 
		L,
		R, 
		U, 
		D 
	};

	explicit COrientation( const COrientation::Direction direction = Direction::R );
	virtual ~COrientation();
	void Set( const COrientation::Direction direction );
	const COrientation::Direction Get()const;

private:
	Direction m_direction;

};