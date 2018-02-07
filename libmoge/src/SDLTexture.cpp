#include "SDLTexture.hpp"

using namespace Moge;

SDLTexture::SDLTexture()
{
}

SDLTexture::SDLTexture( const SDLTexture& orig ):
    m_texture( orig.m_texture )
{
}

SDLTexture::~SDLTexture()
{
}

const RenderableType SDLTexture::getRenderableType()const
{
    return RenderableType::TEXTURED;
}
