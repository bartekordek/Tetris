#pragma once

#include "Path.h"
#include "ITexture.h"
#include <memory>

struct SDL_Texture;
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

		const Math::IVector3D<double>& getSize()const override;
		void setSize( const Math::IVector3D<double>& size ) override;

		const Math::IVector3D<double>& getScale()const override;
		void setScale( const Math::IVector3D<double>& scale ) override;
		
	private:
		SDL_Texture* texture = nullptr;
		Path texturePath;
		std::unique_ptr<Math::IVector3D<double>> size;
		std::unique_ptr<Math::IVector3D<double>> realSize;
		std::unique_ptr<Math::IVector3D<double>> scale;
	};
}