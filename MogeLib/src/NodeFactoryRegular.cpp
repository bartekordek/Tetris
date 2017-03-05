#include "NodeFactoryRegular.h"
#include "SurfaceFactory.h"
#include "Math/IPositionAdapter.h"
#include "ObjectNode.h"

namespace Moge
{
	NodeFactoryRegular::NodeFactoryRegular( SurfaceFactory* surfaceFactory ):INodeFactory( surfaceFactory )
	{
	}

	using namespace Math;

	ObjectNode NodeFactoryRegular::CreateFromImage( 
		const Path& filePath, const IPosition<int>& position, const MyString& name )
	{
		ImageSurface imageSurface = getSurfacefactory()->CreateSurfaceFromImage( filePath );
		return CreateFromImage( imageSurface, position, name );
	}

	ObjectNode NodeFactoryRegular::CreateFromImage( const ImageSurface& imageSurface, const IPosition<int>& position, const MyString& name )
	{
		ObjectNodeContent* objectNodeContent = new ObjectNodeContent();
		objectNodeContent =  position ;
		objectNodeContent->SetName( name );
		objectNodeContent->SetSurface( imageSurface );
		this->nodes.insert( objectNodeContent );
		return ObjectNode( objectNodeContent );
	}

	void NodeFactoryRegular::removeNode( ObjectNode& node )
	{
		this->nodes.erase( node.get() );
		node.reset();
	}

	const bool NodeFactoryRegular::exist( ObjectNode& node )
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