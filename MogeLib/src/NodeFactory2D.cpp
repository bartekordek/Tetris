#include "NodeFactory2D.h"
namespace Moge
{
	NodeFactory2D::NodeFactory2D( ITextureFactory2D* factory2D ): factory2D( factory2D )
	{
	}

	using namespace Math;
	ObjectNode NodeFactory2D::CreateFromImage(
		const Path& filePath, 
		const Math::IPosition<double>& position, 
		const MyString& name )
	{
		ObjectNode result;
		const auto& texture = this->factory2D->createTexture( filePath );
		result->setTexture( texture );
		result->SetName( name );
		//TODO: Fixme.
		return result;
	}

	ObjectNode NodeFactory2D::createFromTexture( const std::shared_ptr<ITexture>& texture, const Math::IPosition<double>& position )
	{
		ObjectNodeContent* objectNodeContent = new ObjectNodeContent();
		objectNodeContent->getPosition().setXyz( position );
		return ObjectNode( objectNodeContent );
	}
	
	void NodeFactory2D::removeNode(const ObjectNode& node)
	{
		this->nodes.erase( node.get() );
	}
	
	const bool NodeFactory2D::exist(const ObjectNode& node)
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