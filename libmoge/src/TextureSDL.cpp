#include "TextureSDL.h"
#include <SDL.h>

namespace Moge
{
    TextureSDL::TextureSDL()
    {
    }

    TextureSDL::~TextureSDL() 
    {
        SDL_DestroyTexture( this->texture );
        this->texture = nullptr;
    }
    
    void TextureSDL::set( SDL_Texture* tex )
    {
        this->texture = tex;
        int w, h;
        SDL_QueryTexture( this->texture, nullptr, nullptr, &w, &h );
        this->size.setXYZ( w, h, 0 );
    }
    
    SDL_Texture* TextureSDL::get() const
    {
        return this->texture;
    }
    
    void TextureSDL::setPath(const CUL::FS::Path& path)
    {
        this->texturePath = path;
    }
    
    const char* TextureSDL::getPath()const
    {
        return this->texturePath.getPath().c_str();
    }

    const CUL::Math::Vector3Dd& TextureSDL::getSize()const
    {
        return this->size;
    }
#if _MSC_VER
    __pragma( warning( push ) ) \
    __pragma( warning( disable:4100 ) )
#endif
    void TextureSDL::setSize( const CUL::Math::Vector3Dd& inSize )
    {
        
    }
#if _MSC_VER
    __pragma( warning( pop ) )
#endif
}