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
		void setBackgroundColor( const ColorE color ) override;
		void setBackgroundColor( const ColorS& color ) override;
		void forceDestroy() override;

		void render( const IRenderable& renderable ) override;
		void render( 
			const ITexture& texture, 
			const Math::IPosition<double>& position, 
			const Math::Vector3D<double>& targetSize ) override;
		void render( const IPrimitive& primitive, const Math::IPosition<double>& position, const Math::Vector3D<double>& targetSize ) override;
		void updateScreen()override;
		void clear() override;

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