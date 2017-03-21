#include "TextureSDL.h"
#include "SDL_render.h"
namespace Moge
{
	TextureSDL::TextureSDL() 
	{
	}

	TextureSDL::TextureSDL(const TextureSDL& orig) 
	{
		
	}

	TextureSDL::~TextureSDL() 
	{
		SDL_DestroyTexture( this->texture );
		this->texture = nullptr;
	}
	
	const Supported2DRenderers TextureSDL::getRendererId()const
	{
		return Supported2DRenderers::R_SDL;
	}
	
	void TextureSDL::set(SDL_Texture* texture)
	{
		this->texture = texture;
	}
	
	SDL_Texture* TextureSDL::get() const
	{
		return this->texture;
	}
	
	void TextureSDL::setPath(const std::string& path)
	{
		this->texturePath = path;
	}
	
	const char* TextureSDL::getPath()const
	{
		return this->texturePath.c_str();
	}
}