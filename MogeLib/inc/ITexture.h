#pragma once

#include "MogeLib.h"
#include "Math/Vector3D.h"

struct SDL_Renderer;
namespace Moge
{
    class MogeLib_API ITexture
    {
    public:
        ITexture();
        virtual ~ITexture();
        virtual const char* getPath()const = 0;

        virtual const Math::Vector3D<double>& getSize()const = 0;
        virtual void setSize( const Math::Vector3D<double>& size ) = 0;
    protected:
    private:
    };
}