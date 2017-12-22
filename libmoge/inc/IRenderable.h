#pragma once

#include "MogeLib.h"
#include "RenderableTypes.h"
#include "ITexture.h"
#include "Math/IPosition.h"

#include <memory>

namespace Moge
{
    class MogeLib_API IRenderable
    {
    public:
        IRenderable();
        virtual ~IRenderable();
        
        virtual const Math::IPosition<double>& getPosition()const = 0;
        virtual void setX( const double x ) = 0;
        virtual void setY( const double y ) = 0;
        virtual void setZ( const double z ) = 0;
        virtual void setPosition( const Math::IPosition<double>& pos ) = 0;
        virtual const Math::Vector3D<double>& getSize()const = 0;
        virtual const Math::Vector3D<double>& getAbsSize()const = 0;
        virtual const Math::Vector3D<double>& getScale()const = 0;
        virtual void setScale( const Math::Vector3D<double>& scale ) = 0;
        virtual const RenderableType getRenderableType()const = 0;
        virtual const std::shared_ptr<ITexture>& getTexture()const  = 0;
    protected:
    private:
    };
}
