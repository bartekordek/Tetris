#pragma once

#include <vector>

#include "Aliases.h"

class CTableCoor
{
public:
	CTableCoor( const CTableCoor& tableCoord );
	CTableCoor( CUInt row, CUInt column );
	virtual ~CTableCoor();
	CUInt getRow()const;
	CUInt getCol()const;
	void getRow( CUInt row );
	void getCol( CUInt col );
	void changePosition( CUInt row, CUInt col );
	CTableCoor& operator=( const CTableCoor& coor );

private:
	unsigned row = 0;
	unsigned column = 0;
};

typedef std::vector<CTableCoor> CoordinatestList;