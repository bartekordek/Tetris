#ifndef __CSLAB__
#define __CSLAB__

#include "Position.h"

#include "Utils.h"

class CSlab
{
public:
	CSlab( const CSlab& slab );
	CSlab( CUInt row = 0, CUInt col = 0,
		   const bool partOfSlab = false, const bool empty = true );
	CSlab& operator=( const CSlab& slab );
	CUInt Row()const;
	CUInt Col()const;
	void Row( CUInt row );
	void Col( CUInt col );
	void SetPosition( CUInt row, CUInt col );
	const bool PartOfSlab()const;
	void PartOfSlab( const bool partOfSlab );
	const bool Empty()const;
	void Empty( const bool empty );
	
private:
	CTableCoor m_position;
	bool m_partOfSlab = false; // 11
	bool m_empty;
};

#endif