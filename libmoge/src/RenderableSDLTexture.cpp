#include "RenderableSDLTexture.h"

namespace Moge
{
    RenderableSDLTexture::RenderableSDLTexture()
    {
    }

    const CUL::Math::Vector3Dd& RenderableSDLTexture::getPosition()const
    {
        return this->position;
    }

    void RenderableSDLTexture::setPosition( const CUL::Math::Vector3Dd& pos )
    {
        this->position = pos;
    }

    const CUL::Math::Vector3Dd& RenderableSDLTexture::getSize()const
    {
        return this->size;
    }

    const CUL::Math::Vector3Dd& RenderableSDLTexture::getScale() const
    {
        return this->scale;
    }

#if _MSC_VER
    __pragma( warning( push ) ) \
    __pragma( warning( disable:4100 ) )
#endif

    void RenderableSDLTexture::setScale( const CUL::Math::Vector3Dd& newScale )
    {
        //todo
    }

#if _MSC_VER
    __pragma( warning( pop ) )
#endif
    const  std::shared_ptr<ITexture>& RenderableSDLTexture::getTexture() const
    {
        return this->texture;
    }

    void RenderableSDLTexture::setTexture( const std::shared_ptr< ITexture >& tex )
    {
        this->texture = tex;
    }

    const RenderableType RenderableSDLTexture::getRenderableType() const
    {
        return RenderableType::TEXTURED;
    }
}