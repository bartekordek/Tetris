#include "NodeFactory3D.h"
namespace Moge
{
	NodeFactory3D::NodeFactory3D(  ITextureFactory3D* factory3D ): factory3D( factory3D )
	{
	}

	using namespace Math;

	ObjectNode NodeFactory3D::CreateFromImage(
		const Path& filePath, 
		const Math::IPosition<double>& position, 
		const MyString& name )
	{
		ObjectNode result;
		//std::shared_ptr<ITexture>& texture = this->
		return result;
	}

	ObjectNode NodeFactory3D::createFromTexture( const std::shared_ptr<ITexture>& texture, const Math::IPosition<double>& position )
	{
		ObjectNodeContent* objectNodeContent = new ObjectNodeContent();
		objectNodeContent->getPosition().setXyz( position );
		return ObjectNode( objectNodeContent );
	}
	
	void NodeFactory3D::removeNode(const ObjectNode& node)
	{
		this->nodes.erase( node.get() );
	}
	
	const bool NodeFactory3D::exist(const ObjectNode& node)
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
	
	const unsigned int NodeFactory3D::Count()
	{
		return static_cast<unsigned int>( this->nodes.size() );
	}
}