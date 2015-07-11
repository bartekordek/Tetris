#ifndef _COORDS_
#define _COORDS_

#include "Utils.h"

/*
* @brief This class handles coordinates in table.
* @details
*/
class CTableCoor
{
public:
	CTableCoor( CUInt row, CUInt column );
	virtual ~CTableCoor();
	CUInt Row()const;
	CUInt Col()const;
	void Row( CUInt row );
	void Col( CUInt col );
	/*
	 * @brief Sets postion to row and col.
	 * @param[in] const unsigned int - row number.
	 * @param[in] const unsigned int - column number.
	 */
	void ChangePosition( CUInt row, CUInt col );
	CTableCoor& operator=( const CTableCoor& coor );

private:
	unsigned m_row;
	unsigned m_column;
};

typedef std::vector<CTableCoor> CoordinatestList;

#endif