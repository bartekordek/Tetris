#pragma once
#include "IRenderable.h"
#include "ITexture.h"
#include <memory>

namespace Moge
{
    class RenderableSDLTexture: public IRenderable
    {
    public:
        RenderableSDLTexture();
        virtual ~RenderableSDLTexture() = default;

        const CUL::Math::Vector3Dd& getPosition()const override;
        void setPosition( const CUL::Math::Vector3Dd& pos ) override;
        const CUL::Math::Vector3Dd& getSize()const override;
        const CUL::Math::Vector3Dd& getScale()const override;
        void setScale( const CUL::Math::Vector3Dd& scale )override;
        const RenderableType getRenderableType()const override;

        const std::shared_ptr<ITexture>& getTexture()const override;
        void setTexture( const std::shared_ptr<ITexture>& texture );
    protected:
    private:
        std::shared_ptr<ITexture> texture;
        CUL::Math::Vector3Dd position;
        CUL::Math::Vector3Dd size;
        CUL::Math::Vector3Dd scale;
    };
}
