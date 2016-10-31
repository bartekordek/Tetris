#pragma once

#include <vector>

#include "Aliases.h"

class CTableCoor
{
public:
	CTableCoor( const CTableCoor& tableCoord );
	CTableCoor( CUInt row, CUInt column );
	virtual ~CTableCoor();
	CUInt Row()const;
	CUInt Col()const;
	void Row( CUInt row );
	void Col( CUInt col );
	void ChangePosition( CUInt row, CUInt col );
	CTableCoor& operator=( const CTableCoor& coor );

private:
	unsigned row;
	unsigned column;
};

typedef std::vector<CTableCoor> CoordinatestList;