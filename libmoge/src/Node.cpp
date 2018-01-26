#include "Node.h"
#include "CUL/Math/Vector3D.hpp"

namespace Moge
{
    Node::Node()
    {
    }

    Node::Node( const Node& objectNodeContent ):
        position( objectNodeContent.position ),
        scale( objectNodeContent.scale ),
        texture( objectNodeContent.texture )
    {
        this->absSize = this->scale * this->texture->getSize();
    }

    Node& Node::operator=( const Node& right )
    {
        if( &right != this )
        {
            this->position = right.position;
            this->texture = right.texture;
            this->scale = right.scale;
            this->absSize = this->scale * this->texture->getSize();
        }
        return *this;
    }

    const bool Node::operator==( const Node& right )const
    {
        if( this != &right )
        {
            if( this->position == right.position && this->scale == right.scale )
            {
                if( this->texture.get() == right.texture.get() )
                {
                    return true;
                }
            }
        }
        else
        {
            return true;
        }
        return false;
    }

    Node::~Node()
    {
    }

    const CUL::Math::Vector3Dd& Node::getPosition() const
    {
        return this->position;
    }

    void Node::setX( const double x )
    {
        this->position.setX( x );
    }

    void Node::setY( const double y )
    {
        this->position.setY( y );
    }

    void Node::setZ( const double z )
    {
        this->position.setZ( z );
    }

    const CUL::Math::Vector3Dd& Node::getSize()const
    {
        return this->texture->getSize();
    }

    const CUL::Math::Vector3Dd& Node::getAbsSize() const
    {
        return this->absSize;
    }

    const CUL::Math::Vector3Dd& Node::getScale() const
    {
        return this->scale;
    }

    void Node::setScale( const CUL::Math::Vector3Dd& inputScale )
    {
        this->scale = inputScale;
        this->absSize = scale * this->texture->getSize();
    }

    void Node::setTexture( const std::shared_ptr<ITexture>& inputTexture )
    {
        this->texture = inputTexture;
        this->absSize = this->scale * this->texture->getSize();
    }

    const std::shared_ptr< ITexture >& Node::getTexture()const
    {
        return this->texture;
    }

    void Node::setPosition( const CUL::Math::Vector3Dd& pos )
    {
        this->position = pos;
    }

    const RenderableType Node::getRenderableType() const
    {
        return RenderableType::TEXTURED;
    }
}