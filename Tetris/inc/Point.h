#ifndef __POINT__
#define __POINT__
class CPoint
{
public:
	CPoint( const unsigned x = 0, const unsigned y = 0 );
	virtual ~CPoint();

	const unsigned int GetX()const;
	const unsigned int GetY()const;

private:
	unsigned int m_x;
	unsigned int m_y;
};
#endif