#pragma once

#include "Path.h"
#include "ITexture.h"
#include <memory>
#include <SDL.h>

namespace Moge
{
	class TextureSDL: public ITexture
	{
	public:
		TextureSDL();
		TextureSDL(const TextureSDL& orig);
		virtual ~TextureSDL();
		
		void set( SDL_Texture* texture );
		SDL_Texture* get()const;
		void setPath( const Path& path );
		const char* getPath()const override;
		SDL_Texture* getTexture()const;

		Math::ISize<int>& getSize() override;
		const Math::ISize<int>& getSize()const override;
		
	private:
		SDL_Texture* texture = nullptr;
		Path texturePath;
		std::unique_ptr<Math::ISize<int>> size;
	};
}