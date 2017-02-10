#pragma once

#include <ObjectNode.h>
#include "TableCoordinates.h"

namespace Tetris
{
class Slab
{
public:
	Slab( const Slab& slab );
	Slab( const unsigned int row = 0, const unsigned int col = 0, const bool empty = true );
	virtual ~Slab();
	Slab& operator=( const Slab& slab );
	const unsigned int row()const;
	const unsigned int col()const;
	void row( const unsigned int row );
	void col( const unsigned int col );
	const bool isEmpty()const;
	void setEmpty( const bool empty );
	void setNode( const Moge::ObjectNode& node );
	const Moge::ObjectNode& getNode()const;

private:
	MatrixPos position;
	bool empty = true;
	Moge::ObjectNode node;
};
}