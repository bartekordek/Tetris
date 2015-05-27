#ifndef __POINT__
#define __POINT__
class CPoint
{
public:
	CPoint( const int x = 0, const int y = 0 );
	virtual ~CPoint();

	const int GetX()const;
	const int GetY()const;

private:
	int m_x;
	int m_y;
};
#endif