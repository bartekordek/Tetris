#pragma once

#include "MogeLib.h"
#include "RenderableTypes.h"
#include "ITexture.h"
#include "CUL/Math/Vector3D.hpp"

#include <memory>

namespace Moge
{
    class MogeLib_API IRenderable
    {
    public:
        IRenderable();
        virtual ~IRenderable();
        
        virtual const CUL::Math::Vector3Dd& getPosition()const = 0;
        virtual void setX( const double x ) = 0;
        virtual void setY( const double y ) = 0;
        virtual void setZ( const double z ) = 0;
        virtual void setPosition( const CUL::Math::Vector3Dd& pos ) = 0;
        virtual const CUL::Math::Vector3Dd& getSize()const = 0;
        virtual const CUL::Math::Vector3Dd& getAbsSize()const = 0;
        virtual const CUL::Math::Vector3Dd& getScale()const = 0;
        virtual void setScale( const CUL::Math::Vector3Dd& scale ) = 0;
        virtual const RenderableType getRenderableType()const = 0;
        virtual const std::shared_ptr<ITexture>& getTexture()const  = 0;
    protected:
    private:
    };
}
