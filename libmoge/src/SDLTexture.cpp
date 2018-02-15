#include "SDLTexture.hpp"

using namespace Moge;

SDLTexture::SDLTexture()
{

}

SDLTexture::~SDLTexture()
{
    this->m_texture = nullptr;
}

ContainingTexture* SDLTexture::getTexture()const
{
    return this->m_texture;
}

void SDLTexture::setTexture( ContainingTexture* texture )
{
    this->m_texture = texture;
}

const Vector3Du& SDLTexture::getSize()const
{
    return this->m_texture->getSize();
}

const Path& SDLTexture::getPath()const
{
    return this->m_texture->getPath();
}