#pragma once

#include "ScreenNode.h"
#include "ObjectNode.h"

#include <set>

namespace MOGE
{
	template class MOGE_API std::set< ObjectNode* >;

	class MOGE_API NodeCreator
	{
	public:
		static ScreenNode CreateScreen( const Size& size );
		static std::shared_ptr<ObjectNode> CreateFromImage( const Path& filePath, const Position& position = Position(), const String& name = "" );
		static std::shared_ptr<ObjectNode> GetObjectNode( const Path& path );
		static void RemoveNode( std::shared_ptr<ObjectNode> node);
		static const bool Exist( std::shared_ptr<ObjectNode> node );
	protected:
	private:
		static std::set< ObjectNode* > sObjectNodes;
	};
} 