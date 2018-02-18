#include "SDLSprite.hpp"
#include "SDLTexture.hpp"
#include "CUL/Math/Vector3D.hpp"

using namespace Moge;

SDLSprite::SDLSprite()
{
}

SDLSprite::SDLSprite( const SDLSprite& objectNodeContent ):
    m_pos( objectNodeContent.m_pos ),
    scale( objectNodeContent.scale ),
    absSize( objectNodeContent.absSize ),
    m_sdlSprite( objectNodeContent.m_sdlSprite )
{

}

SDLSprite& SDLSprite::operator=( const SDLSprite& right )
{
    if( &right != this )
    {
        this->m_pos = right.m_pos;
        this->m_sdlSprite = right.m_sdlSprite;
        this->scale = right.scale;
        this->absSize = right.absSize;
    }
    return *this;
}

const bool SDLSprite::operator==( const SDLSprite& right )const
{
    if( &right == this )
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
    return this->m_sdlSprite->getPosition();
}

void SDLSprite::setX( const double x )
{
    this->m_pos.setX( x );
    this->m_sdlSprite->setPosition( this->m_pos );
}

void SDLSprite::setY( const double y )
{
    this->m_pos.setY( y );
    this->m_sdlSprite->setPosition( this->m_pos );
}

void SDLSprite::setZ( const double z )
{
    this->m_pos.setZ( z );
    this->m_sdlSprite->setPosition( this->m_pos );
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

void SDLSprite::setSprite( SDL2W::ISprite* sprite )
{
    this->m_sdlSprite = sprite;
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
    this->m_pos = pos;
    this->m_sdlSprite->setPosition( pos );
}

const RenderableType SDLSprite::getRenderableType()const
{
    return RenderableType::TEXTURED;
}