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

	std::shared_ptr<Node> NodeFactoryRegular::CreateFromImage(
		const Path& filePath, 
		const Math::IPosition<double>& position, 
		const MyString& name )
	{
		std::shared_ptr<Node> result;
		//std::shared_ptr<ITexture>& texture = this->
		return result;
	}

	std::shared_ptr<Node> NodeFactoryRegular::createFromTexture( const std::shared_ptr<ITexture>& texture, const Math::IPosition<double>& position )
	{
		Node* objectNodeContent = new Node();
		objectNodeContent->getPosition().setXyz( position );
		return std::shared_ptr<Node>( objectNodeContent );
	}

	void NodeFactoryRegular::removeNode(const std::shared_ptr<Node>& node)
	{
		this->nodes.erase( node.get() );
	}

	const bool NodeFactoryRegular::exist(const std::shared_ptr<Node>& node)
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
