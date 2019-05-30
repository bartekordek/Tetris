#pragma once

#include "MogeLib.h"
#include "RenderableTypes.h"
#include "CUL/Math/Vector3D.hpp"

#include <memory>

namespace Moge
{
    class MogeLib_API IRenderable
    {
    public:
        IRenderable();
        virtual ~IRenderable();
        
        virtual const RenderableType getRenderableType()const = 0;
    protected:
    private:
    };
}
