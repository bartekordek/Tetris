#include "NodeFactory3D.h"
#include "ITextureFactory3D.h"
#include "ListVector.h"
namespace Moge
{
	NodeFactory3D::NodeFactory3D( ITextureFactory3D* factory3D ): 
		factory3D( factory3D ),
		nodes( new ListVector<std::shared_ptr<Node>>() )
	{
	}

	using namespace Math;
	std::shared_ptr<Node> NodeFactory3D::CreateFromImage(
		const Path& filePath, 
		const Math::IPosition<double>& position, 
		const MyString& name )
	{
		std::shared_ptr<Node> result;
		const auto& texture = this->factory3D->createTexture( filePath );
		result->setTexture( texture );
		result->SetName( name );

		return result;
	}

	std::shared_ptr<Node> NodeFactory3D::createFromTexture(const std::shared_ptr<ITexture>& texture, const IPosition<double>& position , const MyString& name)
	{
		Node* node = new Node();
		//node->getPosition().setXyz( position );
		node->setPosition( position );
		node->setTexture( texture );
		return std::shared_ptr<Node>( node );
	}
	
	void NodeFactory3D::remove( const std::shared_ptr<Node>& node )
	{
		const Node* nodePtr = static_cast<const Node*>( node.get() );
		remove( nodePtr );
	}

	void NodeFactory3D::remove( const Node* node )
	{
		auto& it = this->nodes->getRandomIterator();
		while( it.hasNext() )
		{
			if( it.next().get() == node )
			{
				nodes->remove( it );
				break;
			}
		}
	}
	
	const bool NodeFactory3D::exist( const std::shared_ptr<Node>& node )const
	{
		auto& it = this->nodes->getRandomIterator();
		while( it.hasNext() )
		{
			if( it.next().get() == node.get() )
			{
				return true;
			}
		}
		return false;
	}
		
	const unsigned int NodeFactory3D::count()const
	{
		return static_cast<unsigned int>( this->nodes->size() );
	}
	
	IIterator<std::shared_ptr<Node>>& NodeFactory3D::getNodes()
	{
		return this->nodes->getRandomIterator();
	}
	
}
