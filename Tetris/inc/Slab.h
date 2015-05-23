#ifndef __CSLAB__
#define __CSLAB__

#include "Position.h"

#include "Utils.h"

class CSlab
{
public:
	CSlab( const CSlab& slab );
	CSlab( const unsigned int row = 0, const unsigned int col = 0 );
	const unsigned int Row()const;
	const unsigned int Col()const;
	void SetRow( const unsigned int row );
	void SetCol( const unsigned int col );

private:
	CTableCoor m_position;
};

#endif