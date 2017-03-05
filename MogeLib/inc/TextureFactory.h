#pragma once

#include "ITextureFactory.h"

#include <map>

namespace Moge
{
	class Engine;
	class SurfaceFactory;
	class TextureFactory: public ITextureFactory
	{
	public:
		TextureFactory( Engine* engine );
		virtual ~TextureFactory();
		std::shared_ptr<ITexture>& createTexture( const Path& path ) override;
		std::shared_ptr<ITexture>& findTexture( const Path& path ) override;
		void removeTexture( const std::shared_ptr<ITexture>& texture ) override;
	protected:
	private:
		
		std::map<char*, std::shared_ptr<ITexture>> textures;
		SurfaceFactory* surfaceFactory = nullptr;
	};
}