#ifndef __POSITION_Y__
#define __POSITION_Y__

class CPosition
{
public:
	CPosition( const unsigned int x = 0, const unsigned int y = 0 );
	CPosition( const CPosition& position );

	const unsigned int GetX()const;
	const unsigned int GetY()const;

	CPosition& operator=( const CPosition& position );

private:
	unsigned int m_x;
	unsigned int m_y;
};

#endif