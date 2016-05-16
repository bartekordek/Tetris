#include "NodeCreator.h"
#include "NodeImageCreator.h"
#include "GeneralUtilities.h"

#include "ObjectNode.h"
#include "ScreenNode.h"

namespace MOGE
{
	ScreenNode NodeCreator::CreateScreen( const Size& size )
	{
		ScreenNode screenNode;
		screenNode.SetWH( size );
		return screenNode;
	}

	ObjectNode NodeCreator::CreateFromImage( const Path& filePath, const Position3d& position, const String& name )
	{
		ImageSurface imageSurface = MOGE::ImageCreator::CreateSurfaceFromImage( filePath );
		return CreateFromImage( imageSurface, position, name );
	}

	ObjectNode NodeCreator::CreateFromImage( const ImageSurface& imageSurface, const Position3d& position, const String& name )
	{
		ObjectNodeContent* objectNodeContent = new ObjectNodeContent();
		objectNodeContent->SetXY( position.GetX(), position.GetY() );
		objectNodeContent->SetName( name );
		objectNodeContent->SetSurface( imageSurface );
		sObjectNodes.insert( objectNodeContent );
		return ObjectNode( objectNodeContent );;
	}

	ObjectNode NodeCreator::GetObjectNode( const Path& path )
	{
		for( auto& node: sObjectNodes )
		{
			if( node->GetPath() == path )
			{
				return ObjectNode( node );
			}
		}
		return ObjectNode( nullptr );
	}

	void NodeCreator::RemoveNode( ObjectNode& node )
	{
		sObjectNodes.erase( node.get() );
		node.reset();
	}

	const bool NodeCreator::Exist( ObjectNode& node )
	{
		for( auto& currentNode : sObjectNodes )
		{
			if( currentNode == node.get() )
			{
				return true;
			}
		}
		return false;
	}

	const unsigned int NodeCreator::Count()
	{
		return sObjectNodes.size();
	}

	std::set< ObjectNodeContent* > NodeCreator::sObjectNodes;
}