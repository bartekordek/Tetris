#include "SDLRenderer.h"
#include <SDL.h>

namespace Moge
{
	SDLRenderer::SDLRenderer( Engine* engine ): 
		IRenderer2D(),
		ITextureFactory( engine )
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
}