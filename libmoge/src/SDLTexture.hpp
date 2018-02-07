#pragma once
#include "IRenderable.h"
#include "SDL2Wrapper/IObject.hpp"
namespace Moge
{
    class SDLTexture:
        public IRenderable
    {
    public:
        SDLTexture();
        SDLTexture( const SDLTexture& orig );
        virtual ~SDLTexture();

        const RenderableType getRenderableType()const override;
        SDL2W::IObject* m_texture = nullptr;

    private:
    };
}