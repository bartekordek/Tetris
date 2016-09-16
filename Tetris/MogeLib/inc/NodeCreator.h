#pragma once

#include "ScreenNode.h"
#include "ObjectNode.h"
#include "Position3d.h"

namespace MogeLib
{
	class MOGE_API NodeCreator
	{
	public:
		static ScreenNode CreateScreen( const Size& size );
		static ObjectNode CreateFromImage( const Path& filePath, const Position3d& position = Position3d(), const String& name = "" );
		static ObjectNode CreateFromImage( const ImageSurface& imageSurface, const Position3d& position = Position3d(), const String& name = "" );
		static ObjectNode GetObjectNode( const Path& path );
		static void RemoveNode( ObjectNode& node);
		static const bool Exist( ObjectNode& node );
		static const unsigned int Count();
	protected:
	private:
		static std::set< ObjectNodeContent* > sObjectNodes;
	};
} 