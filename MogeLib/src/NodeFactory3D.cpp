#include "NodeFactory3D.h"
namespace Moge
{
	NodeFactory3D::NodeFactory3D(  ITextureFactory3D* factory3D ): factory3D( factory3D )
	{
	}

	using namespace Math;

	std::shared_ptr<ObjectNodeContent> NodeFactory3D::CreateFromImage(
		const Path& filePath, 
		const Math::IPosition<double>& position, 
		const MyString& name )
	{
		std::shared_ptr<ObjectNodeContent> result;
		//std::shared_ptr<ITexture>& texture = this->
		return result;
	}

	std::shared_ptr<ObjectNodeContent> NodeFactory3D::createFromTexture( const std::shared_ptr<ITexture>& texture, const Math::IPosition<double>& position )
	{
		ObjectNodeContent* objectNodeContent = new ObjectNodeContent();
		objectNodeContent->getPosition().setXyz( position );
		return std::shared_ptr<ObjectNodeContent>( objectNodeContent );
	}
	
	void NodeFactory3D::removeNode(const std::shared_ptr<ObjectNodeContent>& node)
	{
		this->nodes.erase( node.get() );
	}
	
	const bool NodeFactory3D::exist(const std::shared_ptr<ObjectNodeContent>& node)
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