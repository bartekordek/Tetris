#include "TextureFactory.h"
#include "Engine.h"
#include "SurfaceFactory.h"
#include "TextureSDL.h"

#include <SDL.h>

namespace Moge
{
	TextureFactory::TextureFactory( Engine* engine ): ITextureFactory( engine )
	{
	}

	std::shared_ptr<ITexture>& TextureFactory::createTexture( const Path& path, const SupportedRenderers renderer )
	{
		static std::shared_ptr<ITexture> txt( new TextureSDL() );
		if( SupportedRenderers::R_SDL == renderer )
		{
			auto surface = getEngine()->getSurfaceFactory()->CreateSurfaceFromImage( path );
			auto newTexture = SDL_CreateTextureFromSurface( getEngine()->getRenderer(), surface );
			static_cast<TextureSDL*> ( txt->get() )->set( newTexture );
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
	
	std::shared_ptr<ITexture>& createTexture( const ImageSurface& is )
	{
		
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