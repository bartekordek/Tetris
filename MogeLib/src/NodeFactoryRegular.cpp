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
		const Path& filePath, 
        const Math::IPosition<double>& position, 
        const MyString& name )
	{
		ImageSurface imageSurface = getSurfacefactory()->CreateSurfaceFromImage( filePath );
		return CreateFromImage( imageSurface, position, name );
	}

	ObjectNode NodeFactoryRegular::CreateFromImage( 
		const ImageSurface& imageSurface, 
		const Math::IPosition<double>& position, 
		const MyString& name )
	{
		ObjectNodeContent* objectNodeContent = new ObjectNodeContent();
        objectNodeContent->getPosition().setXyz( position );
		objectNodeContent->SetName( name );
        //objectNodeContent->SetSurface( imageSurface ); TODO insert texture here.
		this->nodes.insert( objectNodeContent );
		return ObjectNode( objectNodeContent );
	}

    ObjectNode createFromTexture( const std::shared_ptr<ITexture>& texture, const Math::IPosition<double>& position )
    {
        ObjectNodeContent* objectNodeContent = new ObjectNodeContent();
        objectNodeContent->getPosition().setXyz( position );
        objectNodeContent->SetName( name );
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
