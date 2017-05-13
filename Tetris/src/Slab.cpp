#include "Slab.h"

using namespace Tetris;
Slab::Slab( const unsigned int row, const unsigned int col, const bool empty ):
	position( MatrixPos( row, col ) ),
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

const unsigned int Slab::row()const
{
	return position.getRow();
}

void Slab::row( const unsigned int row )
{
	position.setRow( row );
}

void Slab::col( const unsigned int col )
{
	position.setCol( col );
}

const unsigned int Slab::col()const
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

void Slab::setNode( const std::shared_ptr<Moge::Node>& node )
{
	this->node = node;
}

const std::shared_ptr<Moge::Node>& Slab::getNode()const
{
	return this->node;
}