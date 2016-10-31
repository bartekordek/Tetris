#include "Slab.h"

namespace Tetris
{
	Slab::Slab( CUInt row, CUInt col, const bool partOfSlab, const bool empty ):
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

	CUInt Slab::Row()const
	{
		return position.Row();
	}

	void Slab::Row( CUInt row )
	{
		position.Row( row );
	}

	void Slab::Col( CUInt col )
	{
		position.Col( col );
	}

	CUInt Slab::Col()const
	{
		return position.Col();
	}

	void Slab::SetPosition( CUInt row, CUInt col )
	{
		this->position.ChangePosition( row, col );
	}

	const bool Slab::Empty()const
	{
		return this->empty;
	}

	void Slab::Empty( const bool empty )
	{
		this->empty = empty;
	}

	void Slab::SetId( CUInt id )
	{
		this->index = id;
	}

	void Slab::SetNode( const Moge::ObjectNode& node )
	{
		this->node = node;
	}

	const Moge::ObjectNode& Slab::GetNode()const
	{
		return this->node;
	}
}