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
		TextureSDL& operator=( const TextureSDL& right );
		
		void set( SDL_Texture* texture );
		SDL_Texture* get()const;
		void setPath( const Path& path );
		const char* getPath()const override;

		const Math::Vector3D<double>& getSize()const override;
		void setSize( const Math::Vector3D<double>& size ) override;
		
	private:
		SDL_Texture* texture = nullptr;
		Path texturePath = Path( "" );
		Math::Vector3D<double> size = Math::Vector3D<double>();
	};
}