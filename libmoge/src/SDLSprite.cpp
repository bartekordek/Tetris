#include "SDLSprite.hpp"
#include "SDLTexture.hpp"
#include "CUL/Math/Vector3D.hpp"

using namespace Moge;

SDLSprite::SDLSprite()
{
}

SDLSprite::SDLSprite( const SDLSprite& r ):
    m_sdlSprite( r.m_sdlSprite ),
    m_texture( r.m_texture )
{

}

SDLSprite& SDLSprite::operator=( const SDLSprite& r )
{
    if( &r != this )
    {
        m_sdlSprite = r.m_sdlSprite;
        m_texture = r.m_texture;
    }
    return *this;
}

const bool SDLSprite::operator==( const SDLSprite& r )const
{
    if( &r == this )
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
    this->m_sdlSprite->setX( x );
}

void SDLSprite::setY( const double y )
{
    this->m_sdlSprite->setY( y );
}

void SDLSprite::setZ( const double z )
{
    this->m_sdlSprite->setZ( z );
}

const Vector3Dd& SDLSprite::getSizeReal()const
{
    return this->m_sdlSprite->getSizeReal();
}

const Vector3Dd& SDLSprite::getSizeAbs() const
{
    return this->m_sdlSprite->getSizeAbs();
}

const Vector3Dd& SDLSprite::getScale() const
{
    return this->m_sdlSprite->getScale();
}

void SDLSprite::setScale( const Vector3Dd& inputScale )
{
    this->m_sdlSprite->setScale( inputScale );
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
}

IRenderable* SDLSprite::getRenderable()
{
    return this;
}

void SDLSprite::setPosition( const CUL::Math::Vector3Dd& pos )
{
    this->m_sdlSprite->setPosition( pos );
}

const RenderableType SDLSprite::getRenderableType()const
{
    return RenderableType::TEXTURED;
}