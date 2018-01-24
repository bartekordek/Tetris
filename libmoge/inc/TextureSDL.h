#pragma once

#include "CUL/Path.hpp"
#include "ITexture.h"

struct SDL_Texture;
namespace Moge
{
    class TextureSDL: public ITexture
    {
    public:
        TextureSDL();
        virtual ~TextureSDL();
        
        void set( SDL_Texture* texture );
        SDL_Texture* get()const;
        void setPath( const CUL::FS::Path& path );
        const char* getPath()const override;

        const CUL::Math::Vector3Dd& getSize()const override;
        void setSize( const CUL::Math::Vector3Dd& size ) override;
        
    private:
        SDL_Texture* texture = nullptr;
        CUL::FS::Path texturePath;
        CUL::Math::Vector3Dd size;
    };
}