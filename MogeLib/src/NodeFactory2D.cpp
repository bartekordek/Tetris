#include "NodeFactory2D.h"
#include "ITextureFactory2D.h"
#include "ListVector.h"
namespace Moge
{
	NodeFactory2D::NodeFactory2D( ITextureFactory2D* factory2D ): 
		factory2D( factory2D ),
		nodes( new ListVector<Node>() )
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

		return result;
	}

	std::shared_ptr<Node> NodeFactory2D::createFromTexture(const std::shared_ptr<ITexture>& texture, const IPosition<double>& position , const MyString& name)
	{
		Node* node = new Node();
		node->getPosition().setXyz( position );
		node->setTexture( texture );
		return std::shared_ptr<Node>( node );
	}
	
	void NodeFactory2D::remove( const std::shared_ptr<Node>& node )
	{
		remove( node.get() );
	}

	void NodeFactory2D::remove( const Node* node )
	{
		this->nodes->remove( *node );
	}
	
	const bool NodeFactory2D::exist( const std::shared_ptr<Node>& node )const
	{
		const std::shared_ptr<IIterator<Node>> ret = this->nodes->find( *node.get() );
		const IIterator<Node>& it1 = *ret.get();
		const IIterator<Node>& it2 = this->nodes->end();
		return !(it1 == it2);
	}
		
	const unsigned int NodeFactory2D::count()const
	{
		return static_cast<unsigned int>( this->nodes->size() );
	}
	
	 IIterator<Node>& NodeFactory2D::getNodes()
	 {
		 return this->nodes->getRandomIterator();
	 }
	
}
