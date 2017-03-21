#pragma once

#include "MogeLib.h"
#include "ITexture.h"
#include "SurfaceFactory.h"
#include "Path.h"


#include <memory>

namespace  Moge 
{
	class Engine;
	class MogeLib_API ITextureFactory
	{
	public:
		ITextureFactory( Engine* engine );
		virtual ~ITextureFactory();
		virtual std::shared_ptr<ITexture>& createTexture( const Path& path, const Supported2DRenderers renderer) = 0;
		virtual std::shared_ptr<ITexture>& createTexture( const ImageSurface& is ) = 0;
		virtual std::shared_ptr<ITexture>& findTexture( const Path& path ) = 0;
		virtual void removeTexture( const std::shared_ptr<ITexture>& texture ) = 0;
	protected:
		Engine* getEngine();
	private:
		Engine* engine = nullptr;
	};
}