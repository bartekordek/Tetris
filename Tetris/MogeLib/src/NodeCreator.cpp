#include "NodeCreator.h"
#include "NodeImageCreator.h"
#include "GeneralUtilities.h"

#include "ObjectNode.h"
#include "ScreenNode.h"

namespace Moge
{
	std::shared_ptr<ScreenNode> NodeCreator::CreateScreen( const Math::MultiPoint<unsigned int>& size )
	{
		ScreenNode* screenNode = new ScreenNode();
		screenNode->setWidth( size.getValue( Math::Axes::X ) );
		screenNode->setHeight( size.getValue( Math::Axes::Y ) );
		std::shared_ptr<ScreenNode> result( screenNode );
		return result;
	}

	ObjectNode NodeCreator::CreateFromImage( const Path& filePath, const Math::MultiPoint<int>& position, const MyString& name )
	{
		ImageSurface imageSurface = ImageCreator::CreateSurfaceFromImage( filePath );
		return CreateFromImage( imageSurface, position, name );
	}

	ObjectNode NodeCreator::CreateFromImage( const ImageSurface& imageSurface, const Math::MultiPoint<int>& position, const MyString& name )
	{
		ObjectNodeContent* objectNodeContent = new ObjectNodeContent();
		objectNodeContent->setX( position.getValue( Math::Axes::X ) );
		objectNodeContent->setY( position.getValue( Math::Axes::Y ) );
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