#pragma once

#include <vector>

#include "Aliases.h"

class CTableCoor
{
public:
	CTableCoor();
	CTableCoor( const CTableCoor& tableCoord );
	CTableCoor( CUInt row, CUInt column );
	virtual ~CTableCoor();

	CTableCoor& operator=( const CTableCoor& right );
	CTableCoor operator+( const CTableCoor& right )const;
	CTableCoor operator-( const CTableCoor& right )const;

	CUInt getRow()const;
	CUInt getCol()const;
	void setRow( CUInt row );
	void setCol( CUInt col );
	void changePosition( CUInt row, CUInt col );

private:
	unsigned row = 0;
	unsigned column = 0;
};

typedef std::vector<CTableCoor> CoordinatestList;