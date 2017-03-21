#pragma once

#include "IRenderer2D.h"
#include "ITextureFactory.h"

struct SDL_Renderer;
struct SDL_Window;
namespace Moge
{
	class SDLRenderer: public IRenderer2D, public ITextureFactory
	{
	public:
		SDLRenderer( Engine* engine );
		virtual ~SDLRenderer();
		void createWindow( 
			const Math::IPosition<int>& winPos, 
			const Math::ISize<unsigned int>& winSize, 
			const std::string& winName = "Unnamed window." ) override;
		void setBackgroundColor( const ColorE color );
		void setBackgroundColor( const ColorS& color );
		void forceDestroy();
		
		void render( IRenderable* renderable );
		std::shared_ptr<ITexture>& createTexture( const Path& path, const Supported2DRenderers renderer ) override;
		std::shared_ptr<ITexture>& createTexture( const ImageSurface& is ) override;
		std::shared_ptr<ITexture>& findTexture( const Path& path ) override;
		void removeTexture( const std::shared_ptr<ITexture>& texture ) override;
		

	protected:
	private:
		
		SDL_Renderer* renderer = nullptr;
		SDL_Window* window = nullptr;
		bool rendererWasDestroyed = false;
	};
}