#include "NodeFactoryRegular.h"
#include "Math/IPositionAdapter.h"
#include "ObjectNode.h"

namespace Moge
{
	NodeFactoryRegular::NodeFactoryRegular( ITextureFactory2D* factory2D, ITextureFactory3D* factory3D ):
		factory2D( factory2D ),
		factory3D( factory3D )
	{
	}

	using namespace Math;

	ObjectNode NodeFactoryRegular::CreateFromImage(
		const Path& filePath, 
		const Math::IPosition<double>& position, 
		const MyString& name )
	{
		ObjectNode result;
		return result;
	}

	ObjectNode NodeFactoryRegular::createFromTexture( const std::shared_ptr<ITexture>& texture, const Math::IPosition<double>& position )
	{
		ObjectNodeContent* objectNodeContent = new ObjectNodeContent();
		objectNodeContent->getPosition().setXyz( position );
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
