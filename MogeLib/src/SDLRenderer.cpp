#include "SDLRenderer.hpp"
#include "TextureSDL.h"
#include "IRenderable.h"
#include "KeySDL.h"

#include <SDL.h>
#include <boost/assert.hpp>
#include <map>
#include <iostream>
#include <sstream>

namespace Moge
{
	SDLRenderer::SDLRenderer():
		eventLoopActive( true ),
		sdlKey( SDL_GetKeyboardState( nullptr ) )
	{
		auto sdlInitSuccess = SDL_Init( SDL_INIT_EVERYTHING );
		BOOST_ASSERT_MSG( 0 == sdlInitSuccess, "Cannot initialize SDL subsystem" );
		this->keys = this->createKeys();
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
		SDL_SetRenderDrawColor( 
			this->renderer, 
			color.r, 
			color.g, 
			color.b, 
			color.alpha );
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

	void SDLRenderer::render( const IRenderable& renderable )
	{
		const auto& position = renderable.getPosition();
		switch( renderable.getRenderableType() )
		{
			case RenderableType::TEXTURED:
			{
				render( *renderable.getTexture().get(), position, renderable.getAbsSize() );
				break;
			}
			case RenderableType::PRIMITIVE:
			{
				BOOST_ASSERT_MSG( false, "NOT IMPLEMENTED YET!" );
				//TODO
				break;
			}
			default:
			{
				BOOST_ASSERT_MSG( false, "NOT IMPLEMENTED YET!" );
				//TODO
				break;
			}
		}
	}

	void SDLRenderer::render( const ITexture& texture, const Math::IPosition<double>& position, const Math::Vector3D<double>& targetSize )
	{
		auto sdlTexture = static_cast<const TextureSDL*>( &texture );
		SDL_Rect renderQuad;
		renderQuad.x = static_cast<int>( position.getX() );
		renderQuad.y = static_cast<int>( position.getY() );
		renderQuad.w = static_cast<int>( targetSize.getX() );
		renderQuad.h = static_cast<int>( targetSize.getY() );
		std::unique_ptr<SDL_Rect> srcRect;
		SDL_RenderCopy( this->renderer, sdlTexture->get(), srcRect.get(), &renderQuad );
	}

	void SDLRenderer::render( const IPrimitive& primitive, const Math::IPosition<double>& position, const Math::Vector3D<double>& targetSize )
	{
#if _MSC_VER
		__pragma( warning( push ) ) \
		__pragma( warning( disable:4189 ) )

		auto dupa1 = &primitive;
		auto dupa2 = &position;
		auto dupa3 = &targetSize; 
		__pragma( warning( pop ) )
#endif
	}

	void SDLRenderer::updateScreen()
	{
		SDL_RenderPresent( this->renderer );
	}

	void SDLRenderer::clear()
	{
		SDL_RenderClear( this->renderer );
	}


	std::shared_ptr<ITexture>& SDLRenderer::createTexture( const Path& path )
	{
		SDL_Surface* surface = CreateSurfaceFromImage( path );
		SDL_Texture* newTexture = SDL_CreateTextureFromSurface( this->renderer, surface );
		TextureSDL* texture = new TextureSDL();
		texture->set( newTexture );
		texture->setPath( path );

		SDL_FreeSurface( surface );
		surface = nullptr;

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
			const void * address = static_cast<const void*>(texture.get());
			std::stringstream ss;
			ss << address;  
			std::string addressS = ss.str(); 
			const std::string message = "Texture: " + std::string( texture->getPath()) + ", address: " + addressS
				+ " has not been found!\n";
			BOOST_ASSERT_MSG( false, message.c_str() );
		}
	}

	void SDLRenderer::runMainLoop()
	{
		SDL_Event event;
		while( true == this->eventLoopActive )
		{
			if( SDL_WaitEvent( &event ) > 0 )
			{
				if( ( event.type == SDL_KEYDOWN || event.type == SDL_KEYUP ) )
				{
					auto scancode = SDL_GetScancodeFromKey( event.key.keysym.sym );
					if( SDL_SCANCODE_UNKNOWN != scancode )
					{
						const bool keyIsDown = ( SDL_KEYDOWN == event.type ) ? true : false;
						const auto keyIndex = static_cast<unsigned int>( scancode );
						auto key = this->keys->at( keyIndex );
						key->setKeyIsDown( keyIsDown );
						this->notifyKeyboardObservers( key.get() );
					}
				} 
			}
		}
	}

	void SDLRenderer::stopMainLoop()
	{
		this->eventLoopActive = false;
	}

	const std::shared_ptr<std::map<unsigned int, std::shared_ptr<IKey>>> SDLRenderer::createKeys() const
	{
		std::shared_ptr<std::map<unsigned int, std::shared_ptr<IKey>>> resultPtr( new std::map<unsigned int, std::shared_ptr<IKey>>() );
		for(
			unsigned int i = static_cast<unsigned int>( SDL_SCANCODE_A );
			i < static_cast<unsigned int>( SDL_NUM_SCANCODES );
			++i )
		{
			const auto key = createKey( i );
			resultPtr->insert( std::pair<unsigned int, std::shared_ptr<IKey>>( i, std::unique_ptr<IKey>( key ) ) );
		}
		return resultPtr;
	}

	IKey* SDLRenderer::createKey( const int keySignature ) const
	{
		IKey* result = new KeySDL();
		SDL_Scancode scanCode = static_cast<SDL_Scancode>( keySignature );
		result->setKeyName( SDL_GetScancodeName( scanCode ) );
		result->setKeyIsDown( ( 0 == this->sdlKey[ scanCode ] ) ? false : true );
		return result;
	}
}