#pragma once

#include "Path.h"
#include "ITexture.h"

struct SDL_Texture;
namespace Moge
{
	class TextureSDL: public ITexture
	{
	public:
		TextureSDL();
		TextureSDL(const TextureSDL& orig);
		virtual ~TextureSDL();
		
		const Supported2DRenderers getRendererId()const override;
		void set( SDL_Texture* texture );
		SDL_Texture* get()const;
		void setPath( const Path& path );
		const char* getPath()const override;
		
	private:
		SDL_Texture* texture = nullptr;
		Path texturePath;
	};
}