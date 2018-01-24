#include "NodeFactory3D.h"
#include "ITextureFactory3D.h"
#include "CUL/ListVector.hpp"
namespace Moge
{
    NodeFactory3D::NodeFactory3D( ITextureFactory3D* factory3D ): 
        factory3D( factory3D ),
        nodes( new CUL::ListVector<std::shared_ptr<Node>>() )
    {
    }

    std::shared_ptr<Node> NodeFactory3D::CreateFromImage(
        const CUL::FS::Path& filePath, 
        const CUL::MyString& name )
    {
        std::shared_ptr<Node> result;
        const auto& texture = this->factory3D->createTexture( filePath );
        result->setTexture( texture );
        result->setName( name );

        return result;
    }

    std::shared_ptr<Node> NodeFactory3D::createFromTexture( 
        const std::shared_ptr<ITexture>& texture,
        const CUL::MyString& name )
    {
        Node* node = new Node();
        node->setName( name );
        //node->getPosition().setXyz( position );
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
    
    CUL::IIterator<std::shared_ptr<Node>>& NodeFactory3D::getNodes()
    {
        return this->nodes->getRandomIterator();
    }
    
}
