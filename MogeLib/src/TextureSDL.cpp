#include "TextureSDL.h"
#include <SDL.h>

namespace Moge
{
    TextureSDL::TextureSDL()
    {
    }
#if _MSC_VER
    __pragma( warning( push ) ) \
    __pragma( warning( disable:4100 ) )
#endif
    TextureSDL::TextureSDL(const TextureSDL& orig) 
    {
    }

#if _MSC_VER
    __pragma( warning( pop ) )
#endif
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
    
    void TextureSDL::setPath(const Path& path)
    {
        this->texturePath = path;
    }
    
    const char* TextureSDL::getPath()const
    {
        return this->texturePath.c_str();
    }

    const Math::Vector3D<double>& TextureSDL::getSize()const
    {
        return this->size;
    }
#if _MSC_VER
    __pragma( warning( push ) ) \
    __pragma( warning( disable:4100 ) )
#endif
    void TextureSDL::setSize( const Math::Vector3D< double >& inSize )
    {
        
    }
#if _MSC_VER
    __pragma( warning( pop ) )
#endif
}