#pragma once
#include "ITexture.hpp"
#include "SDL2Wrapper/ITexture.hpp"
namespace Moge
{
    using ContainingTexture = SDL2W::ITexture;
    class SDLTexture:
        public ITexture
    {
    public:
        SDLTexture();
        virtual ~SDLTexture();

        ContainingTexture* getTexture()const;
        void setTexture( ContainingTexture* texture );
        const Vector3Du& getSize()const override;
        const Path& getPath()const override;

    protected:

    private:
        ContainingTexture * m_texture = nullptr;
    };
}