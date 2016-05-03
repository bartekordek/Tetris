#include "Slab.h"

namespace Tetris
{

	CSlab::CSlab( const CSlab& slab ):
		mPosition( CTableCoor( slab.Row(), slab.Col() ) ),
		mPartOfSlab( slab.mPartOfSlab ),
		mEmpty( slab.mEmpty )
	{
	}

	CSlab::CSlab( CUInt row, CUInt col, const bool partOfSlab, const bool empty ):
		mPosition( CTableCoor( row, col ) ),
		mPartOfSlab( partOfSlab ),
		mEmpty( empty )
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
			mPartOfSlab = slab.mPartOfSlab;
			mEmpty = slab.mEmpty;
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

	const bool CSlab::PartOfSlab()const
	{
		return mPartOfSlab;
	}

	const bool CSlab::Empty()const
	{
		return mEmpty;
	}

	void CSlab::Empty( const bool empty )
	{
		mEmpty = empty;
	}

	void CSlab::PartOfSlab( const bool partOfSlab )
	{
		mPartOfSlab = partOfSlab;
	}

	void CSlab::SetId( CUInt id )
	{
		mIndex = id;
	}

	CUInt CSlab::GetId()const
	{
		return mIndex;
	}

	MOGE::ObjectNode& CSlab::GetNode()
	{
		return mNode;
	}
}