#include "Slab.h"

namespace Tetris
{
Slab::Slab( CUInt row, CUInt col, const bool empty ):
	position( CTableCoor( row, col ) ),
	empty( empty )
{
}

Slab::Slab( const Slab& slab ):
	position( slab.position ),
	empty( slab.empty )
{
}

Slab::~Slab()
{
}

Slab& Slab::operator=( const Slab& slab )
{
	if( this != &slab )
	{
		this->position = slab.position;
		this->empty = slab.empty;
		this->node = slab.node;
	}
	return *this;
}

CUInt Slab::row()const
{
	return position.getRow();
}

void Slab::row( CUInt row )
{
	position.setRow( row );
}

void Slab::col( CUInt col )
{
	position.setCol( col );
}

CUInt Slab::col()const
{
	return position.getCol();
}

const bool Slab::isEmpty()const
{
	return this->empty;
}

void Slab::setEmpty( const bool empty )
{
	this->empty = empty;
}

void Slab::setNode( const Moge::ObjectNode& node )
{
	this->node = node;
}

const Moge::ObjectNode& Slab::getNode()const
{
	return this->node;
}
}