#include "TextureFactory.h"
#include "Engine.h"
#include "SurfaceFactory.h"

#include <SDL.h>

namespace Moge
{
	TextureFactory::TextureFactory( Engine* engine ): ITextureFactory( engine )
	{
	}

	TextureFactory::~TextureFactory()
	{
	}

	std::shared_ptr<ITexture>& TextureFactory::createTexture( const Path& path )
	{
		
		//auto surface = getEngine()->getSurfaceFactory()->CreateSurfaceFromImage( path );
		//auto renderer = getEngine()->getScreen()->GetRenderer();
		//auto texture = SDL_CreateTextureFromSurface( renderer, surface->GetSdlSurface() );
		//auto textureSpt = std::shared_ptr<ITexture>( texture );
		//this->textures[const_cast<char*>( path.c_str() )] = textureSpt;
		//return this->textures[const_cast<char*>( path.c_str() )];
		static std::shared_ptr<ITexture> txt;
		return txt;
	}

	std::shared_ptr<ITexture>& TextureFactory::findTexture( const Path& path )
	{
		return this->textures[const_cast<char*>( path.c_str() )];
	}

	void TextureFactory::removeTexture( const std::shared_ptr<ITexture>& texture )
	{
		this->textures.erase( const_cast<char*>( texture->getPath() ) );
	}
}