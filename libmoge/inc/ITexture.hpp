#pragma once
#include "MogeLib.h"
#include "CUL/Math/Vector3D.hpp"
#include "CUL/Path.hpp"
namespace Moge
{
    using Vector3Du = CUL::Math::Vector3Du;
    using Path = CUL::FS::Path;
    class MogeLib_API ITexture
    {
    public:
        ITexture();
        virtual ~ITexture();
        virtual const Vector3Du& getSize()const = 0;
        virtual const Path& getPath()const = 0;
    private:
    protected:
    };
}