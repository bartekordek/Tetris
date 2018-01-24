#pragma once
#include "IRenderer.h"
#include "Math/ISize.h"
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
            const Math::ISize<unsigned int>& winSize, 
            const std::string& winName = "Unnamed window." ) = 0;
    protected:
    private:
    };
}