#ifndef __CSLAB__
#define __CSLAB__

#include "Position.h"
#include "Utilities.h"
#include "TableCoordinates.h"
class CSlab
{
public:
	CSlab( const CSlab& slab );
	CSlab( CUInt row = 0, CUInt col = 0,  const bool partOfSlab = false, const bool empty = true );
	virtual ~CSlab();
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

	void SetId( CUInt id );
	CUInt GetId()const;
	
private:
	CTableCoor m_position;
	unsigned int mIndex = 0;
	bool m_partOfSlab = false; // C++ 11 feature.
	bool m_empty;
};

#endif