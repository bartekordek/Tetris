#pragma once

#include "ITextureFactory.h"

#include <map>
#include <memory>

namespace Moge
{
	class Engine;
	class SurfaceFactory;
	class TextureFactory: public ITextureFactory
	{
	public:
		TextureFactory( Engine* engine );
		virtual ~TextureFactory();
		ITexture* createTexture( const Path& path ) override;
		ITexture* findTexture( const Path& path ) override;
		void removeTexture( ITexture* texture ) override;
	protected:
	private:
		
		std::map<char*, std::shared_ptr<ITexture>> textures;
		SurfaceFactory* surfaceFactory = nullptr;
	};
}