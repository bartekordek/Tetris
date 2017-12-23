#include "RenderableSDLTexture.h"
#include "Math/PositionDouble2D.h"
#include "Math/Vector3D.h"

namespace Moge
{
    RenderableSDLTexture::RenderableSDLTexture()
    {
        this->position.reset( new Math::PositionDouble2D() );
        this->size.reset( new Math::Vector3D<double>() );
        this->scale.reset( new Math::Vector3D<double>() );
    }

    const Math::IPosition<double>& RenderableSDLTexture::getPosition()const
    {
        return *this->position.get();
    }

    void RenderableSDLTexture::setPosition( const Math::IPosition< double >& pos )
    {
        *this->position = pos;
    }

    const Math::Vector3D<double>& RenderableSDLTexture::getSize()const
    {
        return *this->size.get();
    }

    const Math::Vector3D< double >& RenderableSDLTexture::getScale() const
    {
        return *this->scale;
    }

#if _MSC_VER
    __pragma( warning( push ) ) \
    __pragma( warning( disable:4100 ) )
#endif

    void RenderableSDLTexture::setScale( const Math::Vector3D< double >& newScale )
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