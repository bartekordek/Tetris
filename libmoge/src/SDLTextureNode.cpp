#include "SDLTextureNode.hpp"
#include "CUL/Math/Vector3D.hpp"

using namespace Moge;

SDLTextureNode::SDLTextureNode()
{
}

SDLTextureNode::SDLTextureNode( const SDLTextureNode& objectNodeContent ):
    position( objectNodeContent.position ),
    scale( objectNodeContent.scale ),
    texture( objectNodeContent.texture )
{
    this->absSize = this->scale * this->texture->getSize();
}

SDLTextureNode& SDLTextureNode::operator=( const SDLTextureNode& right )
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

const bool SDLTextureNode::operator==( const SDLTextureNode& right )const
{
    if( this != &right )
    {
        if( this->position == right.position && this->scale == right.scale )
        {
            if( this->texture == right.texture )
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

SDLTextureNode::~SDLTextureNode()
{
}

const CUL::Math::Vector3Dd& SDLTextureNode::getPosition() const
{
    return this->position;
}

void SDLTextureNode::setX( const double x )
{
    this->position.setX( x );
}

void SDLTextureNode::setY( const double y )
{
    this->position.setY( y );
}

void SDLTextureNode::setZ( const double z )
{
    this->position.setZ( z );
}

const CUL::Math::Vector3Dd& SDLTextureNode::getSize()const
{
    auto& size = this->texture->getSize();
    return size;
}

const CUL::Math::Vector3Dd& SDLTextureNode::getAbsSize() const
{
    return this->absSize;
}

const CUL::Math::Vector3Dd& SDLTextureNode::getScale() const
{
    return this->scale;
}

void SDLTextureNode::setScale( const CUL::Math::Vector3Dd& inputScale )
{
    this->scale = inputScale;
    this->absSize = scale * this->texture->getSize();
}

void SDLTextureNode::setTexture( const IObject* inputTexture )
{
    this->texture = const_cast<IObject*>( inputTexture );
    this->absSize = this->scale * this->texture->getSize();
}

IRenderable* SDLTextureNode::getRenderable()
{
    return this;
}

void SDLTextureNode::setPosition( const CUL::Math::Vector3Dd& pos )
{
    this->position = pos;
}

const RenderableType SDLTextureNode::getRenderableType()const
{
    return RenderableType::TEXTURED;
}