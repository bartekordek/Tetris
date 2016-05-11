#pragma once

#include "ScreenNode.h"
#include "ObjectNode.h"

#include <set>

namespace MOGE
{
	template class MOGE_API std::set< ObjectNodeContent* >;

	class MOGE_API NodeCreator
	{
	public:
		static ScreenNode CreateScreen( const Size& size );
		static ObjectNode CreateFromImage( const Path& filePath, const Position& position = Position(), const String& name = "" );
		static ObjectNode CreateFromImage( const ImageSurface& imageSurface, const Position& position = Position(), const String& name = "" );
		static ObjectNode GetObjectNode( const Path& path );
		static void RemoveNode( std::shared_ptr<ObjectNodeContent>& node);
		static const bool Exist( std::shared_ptr<ObjectNodeContent>& node );
		static const unsigned int Count();
	protected:
	private:
		static std::set< ObjectNodeContent* > sObjectNodes;
	};
} 