#pragma once

#include <ObjectNode.h>
#include "TableCoordinates.h"

namespace Tetris
{
class Slab
{
public:
	Slab( const Slab& slab );
	Slab( CUInt row = 0, CUInt col = 0, const bool empty = true );
	virtual ~Slab();
	Slab& operator=( const Slab& slab );
	CUInt row()const;
	CUInt col()const;
	void row( CUInt row );
	void col( CUInt col );
	const bool isEmpty()const;
	void setEmpty( const bool empty );
	void SetNode( const Moge::ObjectNode& node );
	const Moge::ObjectNode& GetNode()const;

private:
	CTableCoor position;
	bool empty = true;
	Moge::ObjectNode node;
};
}