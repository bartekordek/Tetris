#include "Slab.h"

namespace Tetris
{
	CSlab::CSlab( CUInt row, CUInt col, const bool partOfSlab, const bool empty ):
		mPosition( CTableCoor( row, col ) ),
		mEmpty( empty )
	{
	}

	CSlab::CSlab( const CSlab& slab ):
		mPosition( slab.mPosition ),
		mEmpty( slab.mEmpty )
	{
	}

	CSlab::~CSlab()
	{
	}

	CSlab& CSlab::operator=( const CSlab& slab )
	{
		if( this != &slab )
		{
			mPosition = slab.mPosition;
			mEmpty = slab.mEmpty;
			mNode = slab.mNode;
		}
		return *this;
	}

	CUInt CSlab::Row()const
	{
		return mPosition.Row();
	}

	void CSlab::Row( CUInt row )
	{
		mPosition.Row( row );
	}

	void CSlab::Col( CUInt col )
	{
		mPosition.Col( col );
	}

	CUInt CSlab::Col()const
	{
		return mPosition.Col();
	}

	void CSlab::SetPosition( CUInt row, CUInt col )
	{
		mPosition.ChangePosition( row, col );
	}

	const bool CSlab::Empty()const
	{
		return mEmpty;
	}

	void CSlab::Empty( const bool empty )
	{
		mEmpty = empty;
	}

	void CSlab::SetId( CUInt id )
	{
		mIndex = id;
	}

	CUInt CSlab::GetId()const
	{
		return mIndex;
	}

	void CSlab::SetNode( const Moge::ObjectNode& node )
	{
		this->mNode = node;
	}

	Moge::ObjectNode& CSlab::GetNode()
	{
		return mNode;
	}
}