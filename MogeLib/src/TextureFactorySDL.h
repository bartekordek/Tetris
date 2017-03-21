#pragma once

#include "ITextureFactory.h"

#include <map>

namespace Moge
{
	class Engine;
	class SurfaceFactory;
	class TextureFactorySDL: public ITextureFactory
	{
	public:
		TextureFactorySDL( Engine* engine );
		virtual ~TextureFactorySDL() = default;
		std::shared_ptr<ITexture>& createTexture( const Path& path, const Supported2DRenderers renderer ) override;
		std::shared_ptr<ITexture>& createTexture( const ImageSurface& is ) override;
		std::shared_ptr<ITexture>& findTexture( const Path& path ) override;
		void removeTexture( const std::shared_ptr<ITexture>& texture ) override;
	protected:
	private:
		
		std::map<char*, std::shared_ptr<ITexture>> textures;
		SurfaceFactory* surfaceFactory = nullptr;
	};
}