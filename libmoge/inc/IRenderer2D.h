#pragma once
#include "IWindow.hpp"
#include "IRenderer.h"
#include "CUL/Math/Vector3D.hpp"
#include <string>
namespace Moge
{
    using Vector3Du = CUL::Math::Vector3Du;
    using Vector3Di = CUL::Math::Vector3Di;
    class MogeLib_API IRenderer2D: public IRenderer
    {
    public:
        IRenderer2D() = default;
        virtual ~IRenderer2D() = default;
        virtual IWindow* createWindow(
            const Vector3Du& size,
            const Vector3Di& position,
            const std::string& winName = "Unnamed window." ) = 0;
        virtual void renderAllWindows() = 0;
    protected:
    private:
    };
}