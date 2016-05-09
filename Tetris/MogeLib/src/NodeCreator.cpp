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
		sObjectNodes.insert( objectNode );
		std::shared_ptr<ObjectNode> result( objectNode );
		return result;
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

	std::set< ObjectNode* > NodeCreator::sObjectNodes;
}