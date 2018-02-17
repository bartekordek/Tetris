#pragma once
#include "MogeLib.h"
#include "CUL/Math/Vector3D.hpp"
#include "CUL/Path.hpp"
namespace Moge
{
    using Vector3Dd = CUL::Math::Vector3Dd;
    using Path = CUL::FS::Path;
    class MogeLib_API ITexture
    {
    public:
        ITexture();
        virtual ~ITexture();
        virtual const Vector3Dd& getSize()const = 0;
        virtual const Path& getPath()const = 0;
    private:
    protected:
    };
}