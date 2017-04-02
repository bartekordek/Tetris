#include "NodeFactory2D.h"
#include "ITextureFactory2D.h"
namespace Moge
{
	NodeFactory2D::NodeFactory2D( ITextureFactory2D* factory2D ): factory2D( factory2D )
	{
	}

	using namespace Math;
	std::shared_ptr<Node> NodeFactory2D::CreateFromImage(
		const Path& filePath, 
		const Math::IPosition<double>& position, 
		const MyString& name )
	{
		std::shared_ptr<Node> result;
		const auto& texture = this->factory2D->createTexture( filePath );
		result->setTexture( texture );
		result->SetName( name );
		//TODO: Fixme.
		return result;
	}

	std::shared_ptr<Node> NodeFactory2D::createFromTexture( const std::shared_ptr<ITexture>& texture, const IPosition<double>& position )
	{
		Node* node = new Node();
		node->getPosition().setXyz( position );
		node->setTexture( texture );
		return std::shared_ptr<Node>( node );
	}
	
	void NodeFactory2D::removeNode(const std::shared_ptr<Node>& node)
	{
		this->nodes.erase( node.get() );
	}
	
	const bool NodeFactory2D::exist(const std::shared_ptr<Node>& node)
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
		
	const unsigned int NodeFactory2D::Count()
	{
		return static_cast<unsigned int>( this->nodes.size() );
	}
}