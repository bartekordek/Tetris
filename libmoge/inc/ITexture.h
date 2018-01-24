#pragma once

#include "MogeLib.h"
#include "CUL/Math/Vector3D.hpp"

struct SDL_Renderer;
namespace Moge
{
    class MogeLib_API ITexture
    {
    public:
        ITexture();
        virtual ~ITexture();
        virtual const char* getPath()const = 0;

        virtual const CUL::Math::Vector3Dd& getSize()const = 0;
        virtual void setSize( const CUL::Math::Vector3Dd& size ) = 0;
    protected:
    private:
    };
}