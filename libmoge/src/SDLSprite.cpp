#include "SDLSprite.hpp"
#include "SDLTexture.hpp"
#include "CUL/Math/Vector3D.hpp"

using namespace Moge;

SDLSprite::SDLSprite()
{
}

SDLSprite::SDLSprite( const SDLSprite& objectNodeContent ):
    position( objectNodeContent.position ),
    scale( objectNodeContent.scale ),
    absSize( objectNodeContent.absSize ),
    m_sdlSprite( objectNodeContent.m_sdlSprite )
{

}

SDLSprite& SDLSprite::operator=( const SDLSprite& right )
{
    if( &right != this )
    {
        this->position = right.position;
        this->m_sdlSprite = right.m_sdlSprite;
        this->scale = right.scale;
        this->absSize = right.absSize;
    }
    return *this;
}

const bool SDLSprite::operator==( const SDLSprite& right )const
{
    if( this != &right )
    {
        if( this->position == right.position && this->scale == right.scale )
        {
            if( this->m_sdlSprite == right.m_sdlSprite )
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

SDLSprite::~SDLSprite()
{
}

const CUL::Math::Vector3Dd& SDLSprite::getPosition() const
{
    return this->position;
}

void SDLSprite::setX( const double x )
{
    this->position.setX( x );
}

void SDLSprite::setY( const double y )
{
    this->position.setY( y );
}

void SDLSprite::setZ( const double z )
{
    this->position.setZ( z );
}

const CUL::Math::Vector3Dd& SDLSprite::getSize()const
{
    return this->m_sdlSprite->getSize();
}

const CUL::Math::Vector3Dd& SDLSprite::getAbsSize() const
{
    return this->absSize;
}

const CUL::Math::Vector3Dd& SDLSprite::getScale() const
{
    return this->scale;
}

void SDLSprite::setScale( const CUL::Math::Vector3Dd& inputScale )
{
    this->scale = inputScale;
    this->absSize = scale * this->m_sdlSprite->getSize();
}

ITexture* SDLSprite::getTexture()
{
    return this->m_texture;
}

void SDLSprite::setTexture( ITexture* texture )
{
    this->m_texture = texture;
    auto sdlTex = static_cast< SDLTexture* >( texture );
    this->m_sdlSprite->setTexture( sdlTex->getTexture() );
    this->absSize = this->scale * this->m_sdlSprite->getSize();
}

IRenderable* SDLSprite::getRenderable()
{
    return this;
}

void SDLSprite::setPosition( const CUL::Math::Vector3Dd& pos )
{
    this->position = pos;
}

const RenderableType SDLSprite::getRenderableType()const
{
    return RenderableType::TEXTURED;
}