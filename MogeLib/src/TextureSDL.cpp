#include "TextureSDL.h"
#include "Vector3DSimple.h"
#include <SDL.h>

namespace Moge
{
	TextureSDL::TextureSDL()
	{
		this->size.reset( new Math::Vector3DSimple<double>() );
		this->realSize.reset( new Math::Vector3DSimple<double>() );
		this->scale.reset( new Math::Vector3DSimple<double>( 1.0, 1.0, 1.0 ) );
	}

	TextureSDL::TextureSDL(const TextureSDL& orig) 
	{
	}

	TextureSDL::~TextureSDL() 
	{
		SDL_DestroyTexture( this->texture );
		this->texture = nullptr;
	}
	
	void TextureSDL::set( SDL_Texture* texture )
	{
		this->texture = texture;
		int w, h;
		SDL_QueryTexture( this->texture, nullptr, nullptr, &w, &h );
		this->size->setXYZ( w, h, 0 );
		*this->realSize = *this->size * *( this->scale );
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

	const Math::IVector3D<double>& TextureSDL::getSize()const
	{
		return *this->realSize;
	}

	void TextureSDL::setSize( const Math::IVector3D< double >& size )
	{
		
	}

	const Math::IVector3D< double >& TextureSDL::getScale() const
	{
		return *this->scale.get();
	}

	void TextureSDL::setScale( const Math::IVector3D< double >& scale )
	{
		*this->scale = scale;
		*this->realSize = *this->size * *( this->scale );
	}
}