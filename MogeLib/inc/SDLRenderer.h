#pragma once

#include "IRenderer2D.h"
#include "ITextureFactory2D.h"
#include <map>

struct SDL_Renderer;
struct SDL_Window;
struct SDL_Surface;
namespace Moge
{
	class SDLRenderer: public IRenderer2D, public ITextureFactory2D
	{
	public:
		SDLRenderer();
		virtual ~SDLRenderer();
		void createWindow( 
			const Math::IPosition<int>& winPos, 
			const Math::ISize<unsigned int>& winSize, 
			const std::string& winName = "Unnamed window." ) override;
		void setBackgroundColor( const ColorE color );
		void setBackgroundColor( const ColorS& color );
		void forceDestroy();
		
		void render( IRenderable* renderable );
		std::shared_ptr<ITexture>& createTexture( const Path& path ) override;
		std::shared_ptr<ITexture>& findTexture( const Path& path ) override;
		void removeTexture( const std::shared_ptr<ITexture>& texture ) override;
		

	protected:
	private:
		SDL_Surface* CreateSurfaceFromImage( const Path& imagePath );
		
		SDL_Renderer* renderer = nullptr;
		SDL_Window* window = nullptr;
		bool rendererWasDestroyed = false;
		std::map<char*,std::shared_ptr<ITexture>> textures;
	};
}