#pragma once

#include <memory>

#include "ScreenNode.h"
#include "ObjectNode.h"
#include "MultiPoint.h"

namespace Moge
{
	class MogeLib_API NodeCreator
	{
	public:
		static std::shared_ptr<ScreenNode> CreateScreen( const Math::MultiPoint<unsigned int>& size );
		static ObjectNode CreateFromImage( const Path& filePath, const Math::MultiPoint<int>& position, const MyString& name = "" );
		static ObjectNode CreateFromImage( const ImageSurface& imageSurface, const Math::MultiPoint<int>& position, const MyString& name = "" );
		static ObjectNode GetObjectNode( const Path& path );
		static void RemoveNode( ObjectNode& node);
		static const bool Exist( ObjectNode& node );
		static const unsigned int Count();
	protected:
	private:
		static std::set< ObjectNodeContent* > sObjectNodes;
	};
} 