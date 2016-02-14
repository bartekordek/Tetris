#pragma once

#include "Node.h"

namespace MOGE
{
	class NodeFactory
	{
	public:

		static NodePtr CreateScreen( const Size& size );
		static NodePtr CreateFromImage( Path filePath, Position position = Position() );
	};
}