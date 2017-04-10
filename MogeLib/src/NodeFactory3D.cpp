#include "NodeFactory3D.h"
namespace Moge
{
	NodeFactory3D::NodeFactory3D(  ITextureFactory3D* factory3D ): factory3D( factory3D )
	{
	}

	using namespace Math;

	std::shared_ptr<Node> NodeFactory3D::CreateFromImage(
		const Path& filePath, 
		const Math::IPosition<double>& position, 
		const MyString& name )
	{
		std::shared_ptr<Node> result;
		//std::shared_ptr<ITexture>& texture = this->
		return result;
	}

	std::shared_ptr<Node> NodeFactory3D::createFromTexture(
		const std::shared_ptr<ITexture>& texture, 
		const Math::IPosition<double>& position , 
		const MyString& name )
	{
		Node* objectNodeContent = new Node();
		objectNodeContent->getPosition().setXyz( position );
		return std::shared_ptr<Node>( objectNodeContent );
	}
	
	void NodeFactory3D::remove(const std::shared_ptr<Node>& node)
	{
		this->nodes.erase( node.get() );
	}
	
	const bool NodeFactory3D::exist(const std::shared_ptr<Node>& node)const
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
	
	const unsigned int NodeFactory3D::count()const
	{
		return static_cast<unsigned int>( this->nodes.size() );
	}
}