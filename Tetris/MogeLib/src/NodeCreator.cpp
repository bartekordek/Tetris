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
		return screenNode;
	}

	std::shared_ptr<ObjectNode> NodeCreator::CreateFromImage( const Path& filePath, const Position& position, const String& name )
	{
		std::shared_ptr<SurfaceWrapper> imageSurface = MOGE::ImageCreator::CreateSurfaceFromImage( filePath );
		ObjectNode* objectNode = new ObjectNode();
		objectNode->SetXY( position.GetX(), position.GetY() );
		objectNode->SetName(name);
		objectNode->SetSurface( imageSurface );
		sObjectNodes.insert( objectNode );
		return std::shared_ptr<ObjectNode>( objectNode );;
	}

	std::shared_ptr<ObjectNode> NodeCreator::GetObjectNode( const Path& path )
	{
		for( auto& node: sObjectNodes )
		{
			if( node->GetPath() == path )
			{
				return std::shared_ptr<ObjectNode>(node);
			}
		}
		return std::shared_ptr<ObjectNode>( nullptr );
	}

	void NodeCreator::RemoveNode( std::shared_ptr<ObjectNode>& node )
	{
		sObjectNodes.erase( node.get() );
		node.reset();
	}

	const bool NodeCreator::Exist( std::shared_ptr<ObjectNode>& node )
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

	const unsigned int NodeCreator::NodesCount()
	{
		return sObjectNodes.size();
	}

	std::set< ObjectNode* > NodeCreator::sObjectNodes;
}