#include "SDLRenderer.h"
#include "TextureSDL.h"
#include <SDL.h>
#include <boost/assert.hpp>
#include <map>
#include <iostream>

namespace Moge
{
	SDLRenderer::SDLRenderer()
	{
		SDL_Init( SDL_INIT_EVERYTHING );
	}

	SDLRenderer::~SDLRenderer()
	{
		if( false == this->rendererWasDestroyed )
		{
			forceDestroy();
		}
	}
	
	void SDLRenderer::createWindow( 
		const Math::IPosition<int>& winPos, 
		const Math::ISize<unsigned int>& winSize, 
		const std::string& winName )
	{
		this->window = SDL_CreateWindow( 
				winName.c_str(), 
				static_cast<int>( winPos.getX() ), 
				static_cast<int>( winPos.getY() ), 
				static_cast<int>( winSize.getWidth() ), 
				static_cast<int>( winSize.getHeight() ), 
				SDL_WINDOW_SHOWN );
		this->renderer = SDL_CreateRenderer( this->window, -1, SDL_RENDERER_ACCELERATED );
	}

	void SDLRenderer::setBackgroundColor( const ColorE color )
	{
		setBackgroundColor( convertE2S( color ) );
	}
	
	void SDLRenderer::setBackgroundColor( const ColorS& color )
	{
		SDL_SetRenderDrawColor( this->renderer, color.r, color.g, color.b, color.alpha );
	}
	
	void SDLRenderer::forceDestroy()
	{
		SDL_DestroyRenderer( this->renderer );
		this->renderer = nullptr;
		SDL_DestroyWindow( this->window );
		this->window = nullptr;
		SDL_Quit();
		rendererWasDestroyed = true;
	}
	
	void SDLRenderer::render( IRenderable* renderable )
	{
	}
	
	std::shared_ptr<ITexture>& SDLRenderer::createTexture( const Path& path )
	{
		SDL_Surface* surface = CreateSurfaceFromImage( path );
		SDL_Texture* newTexture = SDL_CreateTextureFromSurface( this->renderer, surface );
		TextureSDL* texture = new TextureSDL();
		texture->set( newTexture );
		texture->setPath( path );
		char* key = const_cast<char*>( path.c_str() );
		this->textures[  key ] = std::shared_ptr<ITexture>( texture );
		return this->textures.at( key );
	}
	
	SDL_Surface* SDLRenderer::CreateSurfaceFromImage( const Path& imagePath )
	{
		SDL_Surface* result = nullptr;
		if( ".bmp" == imagePath.Extension().ToLower() )
		{
			result = SDL_LoadBMP( imagePath.c_str() );
			BOOST_ASSERT( result != nullptr  );
		}
		return result;
	}

	std::shared_ptr<ITexture>& SDLRenderer::findTexture( const Path& path )
	{
		char* pathStr = const_cast<char*>( path.c_str() );
		auto it = this->textures.find( pathStr );
		if( textures.end() == it )
		{
			static std::shared_ptr<ITexture> nullResult;
			return nullResult;
		}
		return it->second;
	}

	void SDLRenderer::removeTexture( const std::shared_ptr< ITexture >& texture )
	{
		char* pathStr = const_cast<char*>( texture->getPath() );
		auto it = this->textures.find( pathStr );
		if( textures.end() != it )
		{
			this->textures.erase( it );
		}
		else
		{
			ITexture* txtPtr = texture.get();
			const std::string message = "Texture: " + std::string( texture->getPath()) + ", address: " + std::to_string( reinterpret_cast<int>( txtPtr ) )
				+ " has not been found!\n";
			BOOST_ASSERT_MSG( false, message.c_str() );
		}
	}

}