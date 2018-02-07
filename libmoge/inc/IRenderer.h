#pragma once
#include "MogeLib.h"
#include <cstdint>

namespace Moge
{
    class IRenderable;
    class IPrimitive;
    class MogeLib_API IRenderer
    {
    public:
        IRenderer() = default;
        virtual ~IRenderer() = default;
        virtual void forceDestroy() = 0;
        virtual void updateScreen() = 0;
        virtual void clear() = 0;

    protected:
    private:
    };
}
