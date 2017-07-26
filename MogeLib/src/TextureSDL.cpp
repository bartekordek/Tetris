#include "TextureSDL.h"
#include <SDL.h>

namespace Moge
{
	TextureSDL::TextureSDL()
	{
	}

	TextureSDL::TextureSDL( const TextureSDL& right ):
		texture( right.texture ),
		texturePath( right.texturePath ),
		size( right.size )
	{
	}

	TextureSDL::~TextureSDL() 
	{
		SDL_DestroyTexture( this->texture );
		this->texture = nullptr;
	}

	TextureSDL& TextureSDL::operator=( const TextureSDL& right )
	{
		if( this != & right )
		{
			this->texture = right.texture;
			this->texturePath = right.texturePath;
			this->size = right.size;
		}
		return *this;
	}

	void TextureSDL::set( SDL_Texture* texture )
	{
		this->texture = texture;
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

	void TextureSDL::setSize( const Math::Vector3D< double >& size )
	{
		
	}
}