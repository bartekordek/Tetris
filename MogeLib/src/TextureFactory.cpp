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

	std::shared_ptr<ITexture>& TextureFactory::createTexture(const Path& path, const SupportedRenderers renderer)
	{
		static std::shared_ptr<ITexture> txt;
		if( SupportedRenderers::R_SDL == renderer )
		{
			auto surface = getEngine()->getSurfaceFactory()->CreateSurfaceFromImage( path );
		}
		else
		{
			#include <iostream>
			#include <string>
			const std::string error = "Unsupported renderer: " + std::to_string( static_cast<short>(renderer) ) + ".\n";
			std::cerr << error;
		}
		//
		//auto renderer = getEngine()->getScreen()->GetRenderer();
		//auto texture = SDL_CreateTextureFromSurface( renderer, surface->GetSdlSurface() );
		//auto textureSpt = std::shared_ptr<ITexture>( texture );
		//this->textures[const_cast<char*>( path.c_str() )] = textureSpt;
		//return this->textures[const_cast<char*>( path.c_str() )];
		
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