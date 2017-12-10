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

        const Math::Vector3D<double>& getSize()const override;
        void setSize( const Math::Vector3D<double>& size ) override;
        
    private:
        SDL_Texture* texture = nullptr;
        CUL::FS::Path texturePath;
        Math::Vector3D<double> size;
    };
}