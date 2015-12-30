#ifndef _COORDS_
#define _COORDS_

#include "Utilities.h"
#include "GeneralUtilities.h"

class CTableCoor
{
public:
	CTableCoor( CUInt row, CUInt column );
	virtual ~CTableCoor();
	CUInt Row()const;
	CUInt Col()const;
	void Row( CUInt row );
	void Col( CUInt col );
	void ChangePosition( CUInt row, CUInt col );
	CTableCoor& operator=( const CTableCoor& coor );

private:
	unsigned m_row;
	unsigned m_column;
};

typedef std::vector<CTableCoor> CoordinatestList;

#endif