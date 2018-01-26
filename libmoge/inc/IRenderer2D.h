#pragma once
#include "IRenderer.h"
#include "CUL/Math/Vector3D.hpp"
#include <string>
namespace Moge
{
    class Renderer;
    class MogeLib_API IRenderer2D: public IRenderer
    {
    public:
        IRenderer2D() = default;
        virtual ~IRenderer2D() = default;
        virtual void createWindow( 
            const CUL::Math::Vector3Di& winPos, 
            const CUL::Math::Vector3Du& winSize,
            const std::string& winName = "Unnamed window." ) = 0;
    protected:
    private:
    };
}