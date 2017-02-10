#pragma once

#include <vector>

class CTableCoor
{
public:
	CTableCoor() = default;
	CTableCoor( const CTableCoor& tableCoord );
	CTableCoor( const unsigned int row, const unsigned int column );
	virtual ~CTableCoor() = default;

	CTableCoor& operator=( const CTableCoor& right );
	CTableCoor operator+( const CTableCoor& right )const;
	CTableCoor operator-( const CTableCoor& right )const;

    const unsigned int getRow()const;
    const unsigned int getCol()const;
	void setRow( const unsigned int row );
	void setCol( const unsigned int col );
	void changePosition( const unsigned int row, const unsigned int col );

private:
	unsigned row = 0;
	unsigned column = 0;
};

typedef std::vector<CTableCoor> CoordinatestList;