#pragma once

#include <ObjectNode.h>

#include "Position.h"
#include "Utilities.h"
#include "TableCoordinates.h"

namespace Tetris
{
	class CSlab
	{
	public:
		CSlab( const CSlab& slab );
		CSlab( CUInt row = 0, CUInt col = 0, const bool partOfSlab = false, const bool empty = true );
		virtual ~CSlab();
		CSlab& operator=( const CSlab& slab );
		CUInt Row()const;
		CUInt Col()const;
		void Row( CUInt row );
		void Col( CUInt col );
		void SetPosition( CUInt row, CUInt col );
		const bool Empty()const;
		void Empty( const bool empty );

		void SetId( CUInt id );
		CUInt GetId()const;

		void SetNode( const Moge::ObjectNode& node );
		Moge::ObjectNode& GetNode();

	private:
		CTableCoor mPosition;
		unsigned int mIndex = 0;
		bool mEmpty;
		Moge::ObjectNode mNode;
	};
}