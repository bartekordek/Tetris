#include "TextureSDL.h"
#include "Math/SizeInt2D.h"

namespace Moge
{
	TextureSDL::TextureSDL()
	{
		this->size.reset( new Math::SizeInt2D() );
	}

	TextureSDL::TextureSDL(const TextureSDL& orig) 
	{
	}

	TextureSDL::~TextureSDL() 
	{
		SDL_DestroyTexture( this->texture );
		this->texture = nullptr;
	}
	
	void TextureSDL::set(SDL_Texture* texture)
	{
		this->texture = texture;
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

	SDL_Texture* TextureSDL::getTexture() const
	{
		return nullptr;
//		return this->texture.get();
	}

	Math::ISize<int>& TextureSDL::getSize()
	{
		return *this->size.get();
	}

	const Math::ISize<int>& TextureSDL::getSize()const
	{
		return *this->size.get();
	}
}