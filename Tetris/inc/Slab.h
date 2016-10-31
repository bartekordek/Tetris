#pragma once

#include <ObjectNode.h>

#include "TableCoordinates.h"

namespace Tetris
{
	class Slab
	{
	public:
		Slab( const Slab& slab );
		Slab( CUInt row = 0, CUInt col = 0, const bool partOfSlab = false, const bool empty = true );
		virtual ~Slab();
		Slab& operator=( const Slab& slab );
		CUInt Row()const;
		CUInt Col()const;
		void Row( CUInt row );
		void Col( CUInt col );
		void SetPosition( CUInt row, CUInt col );
		const bool Empty()const;
		void Empty( const bool empty );
		void SetId( CUInt id );
		void SetNode( const Moge::ObjectNode& node );
		const Moge::ObjectNode& GetNode()const;

	private:
		CTableCoor position;
		bool empty;
		Moge::ObjectNode node;
	};
}