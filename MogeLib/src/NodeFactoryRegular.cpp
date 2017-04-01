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

	std::shared_ptr<ObjectNodeContent> NodeFactoryRegular::CreateFromImage(
		const Path& filePath, 
		const Math::IPosition<double>& position, 
		const MyString& name )
	{
		std::shared_ptr<ObjectNodeContent> result;
		//std::shared_ptr<ITexture>& texture = this->
		return result;
	}

	std::shared_ptr<ObjectNodeContent> NodeFactoryRegular::createFromTexture( const std::shared_ptr<ITexture>& texture, const Math::IPosition<double>& position )
	{
		ObjectNodeContent* objectNodeContent = new ObjectNodeContent();
		objectNodeContent->getPosition().setXyz( position );
		return std::shared_ptr<ObjectNodeContent>( objectNodeContent );
	}

	void NodeFactoryRegular::removeNode(const std::shared_ptr<ObjectNodeContent>& node)
	{
		this->nodes.erase( node.get() );
	}

	const bool NodeFactoryRegular::exist(const std::shared_ptr<ObjectNodeContent>& node)
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
