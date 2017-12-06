#pragma once
#include "IRenderer.h"
#include "Math/IPosition.h"
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
            const Math::IPosition<int>& winPos, 
            const Math::ISize<unsigned int>& winSize, 
            const std::string& winName = "Unnamed window." ) = 0;
    protected:
    private:
    };
}