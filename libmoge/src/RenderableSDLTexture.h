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

        const Math::IPosition<double>& getPosition()const override;
        void setPosition( const Math::IPosition<double>& pos ) override;
        const Math::Vector3D<double>& getSize()const override;
        const Math::Vector3D<double>& getScale()const override;
        void setScale( const Math::Vector3D<double>& scale )override;
        const RenderableType getRenderableType()const override;

        const std::shared_ptr<ITexture>& getTexture()const override;
        void setTexture( const std::shared_ptr<ITexture>& texture );
    protected:
    private:
        std::shared_ptr<ITexture> texture;
        std::unique_ptr<Math::IPosition<double>> position;
        std::unique_ptr<Math::Vector3D<double>> size;
        std::unique_ptr<Math::Vector3D<double>> scale;
    };
}
