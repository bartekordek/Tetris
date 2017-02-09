#include "NodeFactoryRegular.h"
#include "NodeImageCreator.h"
#include "IPositionAdapter.h"
#include "ObjectNode.h"
#include "ScreenNode.h"

namespace Moge
{
	using namespace Math;
	std::shared_ptr<ScreenNode> NodeFactoryRegular::CreateScreen( const MultiPoint<unsigned int>& size )
	{
		ScreenNode* screenNode = new ScreenNode();
		screenNode->setWidth( size.getValue( Axes::X ) );
		screenNode->setHeight( size.getValue( Axes::Y ) );
		std::shared_ptr<ScreenNode> result( screenNode );
		return result;
	}

	ObjectNode NodeFactoryRegular::CreateFromImage( const Path& filePath, const IPosition<int>& position, const MyString& name )
	{
		ImageSurface imageSurface = ImageCreator::CreateSurfaceFromImage( filePath );
		return CreateFromImage( imageSurface, position, name );
	}

	ObjectNode NodeFactoryRegular::CreateFromImage( const ImageSurface& imageSurface, const IPosition<int>& position, const MyString& name )
	{
		ObjectNodeContent* objectNodeContent = new ObjectNodeContent();
		objectNodeContent->setXyz( position );
		objectNodeContent->SetName( name );
		objectNodeContent->SetSurface( imageSurface );
		this->nodes.insert( objectNodeContent );
		return ObjectNode( objectNodeContent );
	}

	void NodeFactoryRegular::RemoveNode( ObjectNode& node )
	{
        this->nodes.erase( node.get() );
		node.reset();
	}

	const bool NodeFactoryRegular::Exist( ObjectNode& node )
	{
		for( auto& currentNode : this->nodes )
		{
			if( currentNode == node.get() )
			{
				return true;
			}
		}
		return false;
	}

	const unsigned int NodeFactoryRegular::Count()
	{
		return static_cast<unsigned int>( this->nodes.size() );
	}
}