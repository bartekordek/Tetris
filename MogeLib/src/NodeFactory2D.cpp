#include "NodeFactory2D.h"
#include "ITextureFactory2D.h"
#include "CUL/ListVector.hpp"
#include "Node.h"
namespace Moge
{
    NodeFactory2D::NodeFactory2D( ITextureFactory2D* factory2D ): 
        factory2D( factory2D ),
        nodes( new CUL::ListVector<std::shared_ptr<Node>>() )
    {
    }

    NodeFactory2D::~NodeFactory2D()
    {
        this->nodes.reset();
    }

    using namespace Math;
    std::shared_ptr<Node> NodeFactory2D::CreateFromImage(
        const Path& filePath, 
        const MyString& name )
    {
        std::shared_ptr<Node> result = std::make_shared<Node>();
        const auto& texture = this->factory2D->createTexture( filePath );
        result->setTexture( texture );
        result->SetName( name );
        nodes->pushBack( result );
        return result;
    }

    std::shared_ptr<Node> NodeFactory2D::createFromTexture(
        const std::shared_ptr<ITexture>& texture, 
        const MyString& name)
    {
        std::shared_ptr<Node> result = std::make_shared<Node>();
        result->setTexture( texture );
        result->SetName( name );
        nodes->pushBack( result );
        return result;
    }

    void NodeFactory2D::remove( const std::shared_ptr<Node>& node )
    {
        remove( node.get() );
    }

    void NodeFactory2D::remove( const Node* node )
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
    
    const bool NodeFactory2D::exist( const std::shared_ptr<Node>& node )const
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
        
    const unsigned int NodeFactory2D::count()const
    {
        return static_cast<unsigned int>( this->nodes->size() );
    }
    
    CUL::IIterator<std::shared_ptr<Node>>& NodeFactory2D::getNodes()
    {
        return this->nodes->getRandomIterator();
    }
}